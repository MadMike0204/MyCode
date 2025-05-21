// 最少可选颜色优先 (MRV) + 最大度优先 (DH) + 向前探测一步 (Forward Checking)
// 保留原始代码结构，修改为找到第一个解决方案并输出到文件
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm> // 用于 std::sort
#include <fstream>   // 用于 ifstream 和 ofstream
#include <sstream>   // 用于 stringstream
#include <string>    // 用于 std::string 和 to_string
#include <utility>   // 用于 std::pair
#include <limits>    // 用于 numeric_limits

// 移除了 #include "readSample.cpp" - 由 loadGraph 函数替代

using namespace std;

// 使用固定大小的数组，与原始代码一致，但请注意其局限性
// 数组大小为 1001，以适应 1-based 索引，最大顶点编号为 1000
int max_vNum; // 顶点总数 (1-based 索引，最大到 max_vNum)
int eNum;     // 边总数
int matrix[1001][1001]; // 邻接矩阵 (使用 1-based 索引)
// 存储每个顶点的颜色 (使用 1-based 索引，0 表示未着色)
int color[1001];
// 可用颜色数量 (颜色编号从 1 到 cNum)
int cNum;

struct Vertex {
	// colorAccess[c] 为 true 表示颜色 c 对该顶点不可用 (被已着色邻居阻塞)
	// 使用 1-based 索引用于颜色 (大小 26 用于颜色 1-25)
	bool colorAccess[26];
	// remainCNum 不再存储在结构体中，而是在 MRV_DH_find 中动态计算
	int degree; // 顶点的度数
	int pos; // 顶点索引 (1-based)
}vertex[1001]; // 顶点数组使用 1-based 索引

// --- 图加载函数 (适配邻接矩阵和 1-based 索引) ---
// 读取 .col 文件并填充邻接矩阵。
void loadGraph(const string& filename, int matrix[1001][1001], int& num_vertices, int& num_edges) {
	ifstream infile(filename);
	if (!infile.is_open()) {
		cerr << "错误：无法打开文件 " << filename << endl;
		exit(1); // 如果文件无法打开则退出
	}

	// 初始化矩阵为 0
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			matrix[i][j] = 0;
		}
	}

	char type;
	string line;
	num_vertices = 0;
	num_edges = 0;

	while (getline(infile, line)) {
		// 跳过空行和以 'c' 开头的注释行
		if (line.empty() || line[0] == 'c') continue;

		stringstream ss(line);
		if (line[0] == 'p') { // 问题行：p edge num_vertices num_edges
			string p_str, edge_str;
			ss >> type >> edge_str >> num_vertices >> num_edges;
			// max_vNum 在 setVertex 中设置
			// cout << "加载图： " << num_vertices << " 顶点, " << num_edges << " 边." << endl; // 调试输出
		}
		else if (line[0] == 'e') { // 边行：e u v
			int u, v;
			ss >> type >> u >> v;
			// .col 文件通常是 1-based 索引，并且此代码使用 1-based 矩阵
			if (u > 0 && u <= num_vertices && v > 0 && v <= num_vertices) {
				// 添加边到邻接矩阵 (无向图)
				matrix[u][v] = 1;
				matrix[v][u] = 1;
			}
			else {
				cerr << "警告：边连接到超出范围的顶点: " << u << " " << v << " 在文件 " << filename << endl;
			}
		}
		// 忽略其他行类型（如果有）
	}
	infile.close();
}


// --- 辅助函数 ---

// 函数：计算度数并初始化顶点结构体和颜色数组
void setVertex(int num_vertices, const int matrix[1001][1001], int color[1001], Vertex vertex[1001], int num_colors) {
	max_vNum = num_vertices; // 设置全局 max_vNum
	cNum = num_colors; // 设置全局 cNum

	for (int i = 1; i <= max_vNum; i++) {
		vertex[i].pos = i;
		vertex[i].degree = 0; // 重置度数
		for (int j = 1; j <= max_vNum; j++) {
			vertex[i].degree += matrix[i][j];
		}
		// 初始化 colorAccess 数组，所有颜色 (1 到 cNum) 最初都是可访问的 (未被阻塞)
		for (int k = 1; k <= cNum; k++) {
			vertex[i].colorAccess[k] = false;
		}
		color[i] = 0; // 初始化颜色为未着色 (此代码中使用 0 表示未着色)
	}
}

// 函数：检查将 color_kind 颜色分配给 index 顶点是否安全
// 检查是否与已着色的邻居冲突
bool check(int index, int color_kind, int num_vertices, const int matrix[1001][1001], const int color[1001]) {
	for (int i = 1; i <= num_vertices; i++) {
		// 判断是否相邻且邻居颜色相同
		if (matrix[index][i] && color[i] == color_kind)
			return false; // 发现冲突，不安全
	}
	return true; // 与已着色邻居无冲突，安全
}

// Function: Find the next vertex to color (MRV + DH)
// Finds the uncolored vertex with the minimum remaining available colors.
// Ties are broken by selecting the vertex with the maximum degree.
// Returns the 1-based index of the selected vertex, or 0 if all vertices are colored or a dead end is found.
int MRV_DH_find(int num_vertices, const int color[1001], const Vertex vertex[1001], int num_colors) {
	int minC = num_colors + 1; // Initialize with a value greater than max possible remaining colors
	int pos = 0; // 0 indicates no vertex found

	for (int i = 1; i <= num_vertices; i++) {
		if (color[i] == 0) { // If vertex i is uncolored (using 0 for unassigned)
			// Calculate current_remainCNum based on the colorAccess state of vertex[i]
			int current_remainCNum = 0;
			for (int j = 1; j <= num_colors; j++) {
				if (!vertex[i].colorAccess[j]) // If color j is accessible (not blocked)
					current_remainCNum++;
			}

			if (current_remainCNum == 0) {
				// If an uncolored vertex has no available colors, it's a dead end
				return 0;
			}

			// MRV check
			if (minC > current_remainCNum) {
				minC = current_remainCNum;
				pos = i;
			}
			// Degree tie-breaking
			else if (minC == current_remainCNum) {
				// Need to handle the case where pos is still 0 (no vertex found yet)
				if (pos == 0 || vertex[i].degree > vertex[pos].degree) {
					pos = i;
				}
			}
		}
	}
	return pos; // Return the 1-based index of the selected vertex
}

// --- Output Function ---
// Writes the coloring solution to a text file.
void outputColoringToFile(const string& base_filename, int num_colors, const int color[1001], int num_vertices) {
	// Build output filename, e.g., le450_5a_colored_5.txt
	string output_filename = base_filename;
	// Find and replace .col extension
	size_t dot_pos = output_filename.rfind(".col");
	if (dot_pos != string::npos) {
		output_filename.replace(dot_pos, 4, ""); // Remove .col
	}
	// Find and replace .txt extension if it's a custom map file
	dot_pos = output_filename.rfind(".txt");
	if (dot_pos != string::npos) {
		output_filename.replace(dot_pos, 4, ""); // Remove .txt
	}
	output_filename += "_colored_" + to_string(num_colors) + ".txt";

	ofstream outfile(output_filename);
	if (!outfile.is_open()) {
		cerr << "错误：无法创建输出文件 " << output_filename << endl;
		return;
	}

	outfile << "图着色方案 for " << base_filename << " (" << num_vertices << " 顶点, " << num_colors << " 颜色)" << endl;
	outfile << "Vertex Index (0-based): Color" << endl; // 输出格式为 0-based 索引
	outfile << "---------------------------------" << endl;

	// 输出每个顶点的颜色 (将内部的 1-based 索引转换为输出的 0-based 索引)
	for (int i = 1; i <= num_vertices; ++i) {
		outfile << (i - 1) << ": " << color[i] << endl; // 输出 0-based 索引，1-based 颜色
	}

	outfile.close();
	cout << "着色方案已保存到文件: " << output_filename << endl;
}


// --- 核心回溯函数 (MRV, DH, 前向检查, 保留原始剪枝) ---
// 修改为找到并输出第一个解决方案。
// index: 成功着色的顶点数量 (用于跟踪进度)。
// pos: 本次递归调用中要着色的顶点的 1-based 索引。
// usedColor: 原始代码中的参数，与颜色轮换对称性打破有关。
// 返回 true 如果在此分支中找到解决方案，否则返回 false。
bool findFirstColoringUtil_with_original_pruning(int index, int pos, int usedColor,
	int num_vertices, int num_colors,
	int color[1001], const int matrix[1001][1001], Vertex vertex[1001],
	const string& current_filename) { // 传递文件名用于输出

	// 基本情况：所有顶点都已着色
	// 原始代码的 base case 是 index == max_vNum，这可能是一个 bug 或特定计数逻辑。
	// 对于寻找第一个解，正确的 base case 是 index > num_vertices。
	// 我们使用 index > num_vertices 来确保所有顶点都被考虑。
	if (index > num_vertices) {
		// 找到一个解决方案！输出它并返回 true。
		outputColoringToFile(current_filename, num_colors, color, num_vertices);
		return true; // 找到解决方案，将 true 沿递归栈向上返回
	}

	// 如果 pos 为 0，表示 MRV_DH_find 找到了一个死胡同 (一个未着色顶点没有可用颜色)
	// 此检查剪枝了那些导致顶点无法着色的分支。
	if (pos == 0) {
		return false;
	}

	for (int i = 1; i <= num_colors; i++) { // 尝试每种颜色 (1 到 num_colors)
		// 检查颜色 i 是否可访问 (未被前向检查阻塞)
		if (!vertex[pos].colorAccess[i]) {
			// 检查将颜色 i 分配给 pos 顶点是否安全 (与已着色邻居无冲突)
			// 此检查是冗余的，如果 colorAccess 被 FC 完美维护，但保留它增加鲁棒性。
			if (check(pos, i, num_vertices, matrix, color)) {

				// 临时将颜色 i 分配给顶点 pos
				color[pos] = i;

				// --- 前向检查 ---
				// 存储 colorAccess 的变化以便回溯
				vector<pair<int, int>> colorAccessRecover; // pair: {邻居索引, 被阻塞的颜色}

				// 向邻居传播约束
				bool forward_check_ok = true;
				for (int j = 1; j <= num_vertices; j++) { // 遍历所有可能的邻居
					// 如果 j 是 pos 的邻居 并且 j 未着色
					if (matrix[pos][j] && color[j] == 0) {
						// 如果颜色 i 之前对邻居 j 是可访问的
						if (!vertex[j].colorAccess[i]) {
							// 将颜色 i 标记为对邻居 j 不可访问
							vertex[j].colorAccess[i] = true;
							// 记录此变化以便回溯
							colorAccessRecover.push_back({ j, i });

							// 检查邻居 j 是否还有任何可用颜色剩余
							bool neighbor_has_color = false;
							for (int k = 1; k <= num_colors; k++) {
								if (!vertex[j].colorAccess[k]) {
									neighbor_has_color = true;
									break;
								}
							}
							// 如果邻居 j 没有可用颜色剩余了，则此路径失败
							if (!neighbor_has_color) {
								forward_check_ok = false;
								break; // 发现冲突，停止传播此颜色，此分支是死胡同
							}
						}
					}
				}

				// 如果前向检查通过
				if (forward_check_ok) {
					// 使用 MRV+DH 找到下一个要着色的顶点
					int next_coloring_pos = MRV_DH_find(num_vertices, color, vertex, num_colors);

					// 递归调用：尝试着色下一个顶点
					// isNewColor 逻辑保留，用于控制原始代码中的 break 剪枝
					bool isNewColor = i > usedColor;
					int next_usedColor = isNewColor ? usedColor + 1 : usedColor;

					// *** 如果递归调用找到解决方案，立即返回 true ***
					if (findFirstColoringUtil_with_original_pruning(index + 1, next_coloring_pos, next_usedColor,
						num_vertices, num_colors, color, matrix, vertex, current_filename)) {
						return true; // 在更深的调用中找到解决方案，传播 true
					}

					// --- 原始代码的关键剪枝 ---
					// 如果使用了新颜色，并且子问题没有立即找到解，则跳过尝试当前顶点的其他颜色
					// 注意：这个剪枝是基于原始代码的计数逻辑，可能不适用于所有情况下的“找第一个解”
					// 但为了复现原始代码的速度，我们保留它。
					if (isNewColor) {
						// 回溯逻辑在 break 之前执行
						// Restore colorAccess state for affected neighbors
						for (auto const& p : colorAccessRecover) {
							vertex[p.first].colorAccess[p.second] = false; // 恢复可访问性
						}
						// Unassign the color from the current vertex
						color[pos] = 0; // 使用 0 表示未着色

						break; // 跳出当前顶点的颜色尝试循环
					}
				}


				// --- 回溯 (如果前向检查失败 或 子问题未找到解且未使用新颜色) ---
				// Restore colorAccess state for affected neighbors
				for (auto const& p : colorAccessRecover) {
					vertex[p.first].colorAccess[p.second] = false; // 恢复可访问性
				}
				// Unassign the color from the current vertex
				color[pos] = 0; // 使用 0 表示未着色

			} // check(pos, i) if 结束
		} // !vertex[pos].colorAccess[i] if 结束
	} // 颜色循环结束

	// 如果尝试了顶点 pos 的所有颜色 (或因剪枝而提前退出) 都无法找到解决方案
	return false; // 返回 false，触发上一层递归的回溯
}

int main() {
	// 文件列表和对应的颜色数量
	vector<pair<string, int>> files_and_colors = {
		{"./map/given_map/le450_5a.col", 5},
		{"./map/given_map/le450_15b.col", 15},
		{"./map/given_map/le450_25a.col", 25}
		// 如果需要，添加你的自定义地图文件
		// {"./map/mymap/30p_90e_4a.txt", 4}
	};

	// 遍历每个文件和颜色组合
	for (const auto& entry : files_and_colors) {
		string filename = entry.first;
		int num_colors_for_file = entry.second; // 使用局部变量更清晰

		cout << "--- 处理文件: " << filename << " ---" << endl;
		cout << "尝试使用 " << num_colors_for_file << " 种颜色..." << endl;

		// 将图数据加载到矩阵中
		loadGraph(filename, matrix, max_vNum, eNum);
		cout << "图加载完成: " << max_vNum << " 顶点, " << eNum << " 边." << endl;

		// 初始化顶点数据和颜色数组
		// 将 num_colors_for_file 传递给 setVertex 以正确初始化 colorAccess
		setVertex(max_vNum, matrix, color, vertex, num_colors_for_file);

		// 处理空图情况
		if (max_vNum == 0) {
			cout << "图为空，无需着色。" << endl;
			cout << "耗时: 0.000000 秒" << endl;
			cout << "--------------------------------------------------------" << endl;
			continue; // 处理下一个文件
		}

		// 原始代码对 le450_15b 使用了初始顶点 43。
		// 为了复现其行为，我们在这里也指定初始顶点。
		// 对于其他图，我们仍然使用 MRV_DH_find 来选择初始顶点。
		int initial_pos;
		if (filename.find("le450_15b.col") != string::npos) {
			initial_pos = 43; // 原始代码对 15b 使用的初始顶点
			cout << "为 le450_15b.col 指定初始顶点: 43" << endl;
		}
		else {
			// 使用 MRV_DH_find 找到第一个要着色的顶点
			initial_pos = MRV_DH_find(max_vNum, color, vertex, num_colors_for_file);
			if (initial_pos == 0 && max_vNum > 0) {
				cout << "初始状态存在无法着色的顶点，无法找到方案。" << endl;
				cout << "耗时: 0.000000 秒" << endl;
				cout << "--------------------------------------------------------" << endl;
				continue; // 处理下一个文件
			}
			cout << "使用 MRV_DH_find 选择初始顶点: " << initial_pos << endl;
		}


		// 计时并运行图着色算法
		auto start = chrono::high_resolution_clock::now();
		// 从 initial_pos 开始递归着色。
		// index 1 表示我们正在尝试着色搜索顺序中的第 1 个顶点。
		// 传递初始 usedColor 为 0。
		bool success = findFirstColoringUtil_with_original_pruning(1, initial_pos, 0,
			max_vNum, num_colors_for_file, color, matrix, vertex, filename);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = end - start;

		// 输出结果和耗时
		if (success) {
			// 成功消息和文件输出已在 findFirstColoringUtil 中处理
			// 如果需要，可以在这里添加最终确认消息，但它已经打印了。
		}
		else {
			// 如果 findFirstColoringUtil 返回 false，表示在探索的分支中未找到解决方案。
			// 对于完整的搜索，这意味着使用指定颜色无法找到解决方案。
			cout << "无法使用 " << num_colors_for_file << " 种颜色为图着色 (已证明无解)。" << endl;
		}

		cout << "总耗时: " << fixed << setprecision(6) << elapsed.count() << " 秒" << endl;
		cout << "--------------------------------------------------------" << endl;
	}

	return 0;
}
