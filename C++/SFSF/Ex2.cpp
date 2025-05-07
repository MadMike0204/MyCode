#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <set>
#include <fstream>   // For ofstream
#include <sstream>   // For stringstream
#include <string>    // For string manipulation
#include <queue>
#include <unordered_set>
#include <list>
#include <cmath>
#include <map>

using namespace std;

// 定义一个常量表示顶点未着色
const int UNASSIGNED = -1;
const int MAX_ATTEMPTS = 1000000;  // Maximum number of attempts for coloring
const int TIMEOUT_SECONDS = 300;  // 5 minutes timeout
const int INITIAL_TABU_TENURE = 7;
const int MAX_ITERATIONS = 10000;
const int RESTART_THRESHOLD = 1000;
const double COOLING_RATE = 0.95;
const int SUBGRAPH_SIZE = 50;  // Size of subgraphs for decomposition
const int POPULATION_SIZE = 200;  // Increased population size
const int MAX_GENERATIONS = 2000;  // Increased generations
const int TOURNAMENT_SIZE = 7;     // Increased tournament size
const double MUTATION_RATE = 0.15; // Increased mutation rate
const int LOCAL_SEARCH_DEPTH = 3;  // Added local search depth

// Structure to store vertex information
struct VertexInfo {
    int vertex;
    int degree;
    VertexInfo(int v, int d) : vertex(v), degree(d) {}
};

// Compare vertices based on degree
bool compareByDegree(const VertexInfo& a, const VertexInfo& b) {
    if (a.degree != b.degree)
        return a.degree > b.degree;
    return a.vertex < b.vertex;
}

// Calculate saturation degree of a vertex
int calculateSaturation(int v, const vector<int>& colors, const vector<vector<int>>& adj) {
    unordered_set<int> adjacent_colors;
    for (int u : adj[v]) {
        if (colors[u] != UNASSIGNED) {
            adjacent_colors.insert(colors[u]);
        }
    }
    return adjacent_colors.size();
}

// Get available colors for a vertex with dynamic ordering
vector<int> getAvailableColors(int v, int num_colors, const vector<int>& colors, 
    const vector<vector<int>>& adj, const vector<int>& color_usage) {
    vector<bool> used_colors(num_colors, false);
    for (int u : adj[v]) {
        if (colors[u] != UNASSIGNED) {
            used_colors[colors[u]] = true;
        }
    }
    
    // Create pairs of (usage_count, color)
    vector<pair<int, int>> color_pairs;
    for (int c = 0; c < num_colors; ++c) {
        if (!used_colors[c]) {
            color_pairs.push_back({color_usage[c], c});
        }
    }
    
    // Sort by usage (prefer less used colors)
    sort(color_pairs.begin(), color_pairs.end());
    
    vector<int> available_colors;
    for (const auto& p : color_pairs) {
        available_colors.push_back(p.second);
    }
    
    return available_colors;
}

// Calculate conflicts for a vertex
int calculateConflicts(int v, const vector<int>& colors, const vector<vector<int>>& adj) {
    int conflicts = 0;
    for (int u : adj[v]) {
        if (colors[u] != UNASSIGNED && colors[u] == colors[v]) {
            conflicts++;
        }
    }
    return conflicts;
}

// Check if it's safe to color vertex v with color c
bool isSafe(int v, int c, const vector<int>& colors, const vector<vector<int>>& adj) {
    for (int u : adj[v]) {
        if (colors[u] != UNASSIGNED && colors[u] == c) {
            return false;
        }
    }
    return true;
}

// Find connected components using BFS
vector<vector<int>> findConnectedComponents(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;
    
    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            vector<int> component;
            queue<int> q;
            q.push(start);
            visited[start] = true;
            
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                component.push_back(v);
                
                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                    }
                }
            }
            
            components.push_back(component);
        }
    }
    
    return components;
}

// Create subgraph from vertices
pair<vector<vector<int>>, vector<int>> createSubgraph(const vector<int>& vertices, 
    const vector<vector<int>>& adj) {
    map<int, int> old_to_new;
    vector<int> new_to_old;
    
    // Create vertex mapping
    for (int i = 0; i < vertices.size(); i++) {
        old_to_new[vertices[i]] = i;
        new_to_old.push_back(vertices[i]);
    }
    
    // Create adjacency list for subgraph
    vector<vector<int>> subgraph(vertices.size());
    for (int i = 0; i < vertices.size(); i++) {
        int v = vertices[i];
        for (int u : adj[v]) {
            auto it = old_to_new.find(u);
            if (it != old_to_new.end()) {
                subgraph[i].push_back(it->second);
            }
        }
    }
    
    return {subgraph, new_to_old};
}

// Color a subgraph using DSATUR
bool colorSubgraph(vector<int>& colors, const vector<vector<int>>& adj, 
    const vector<int>& vertices, int num_colors) {
    
    // Create subgraph
    auto [subgraph, new_to_old] = createSubgraph(vertices, adj);
    vector<int> subcolors(vertices.size(), UNASSIGNED);
    
    // Sort vertices by degree
    vector<VertexInfo> vertex_order;
    for (int i = 0; i < subgraph.size(); i++) {
        vertex_order.emplace_back(i, subgraph[i].size());
    }
    sort(vertex_order.begin(), vertex_order.end(), compareByDegree);
    
    // Try to color each vertex
    for (const auto& vi : vertex_order) {
        int v = vi.vertex;
        vector<bool> used_colors(num_colors, false);
        
        // Mark colors used by neighbors
        for (int u : subgraph[v]) {
            if (subcolors[u] != UNASSIGNED) {
                used_colors[subcolors[u]] = true;
            }
        }
        
        // Find first available color
        int color = UNASSIGNED;
        for (int c = 0; c < num_colors; c++) {
            if (!used_colors[c]) {
                color = c;
                break;
            }
        }
        
        if (color == UNASSIGNED) {
            return false;
        }
        
        subcolors[v] = color;
    }
    
    // Map colors back to original graph
    for (int i = 0; i < vertices.size(); i++) {
        colors[new_to_old[i]] = subcolors[i];
    }
    
    return true;
}

// Main coloring function using graph decomposition
bool graphColoring(int num_vertices, int num_colors, const vector<vector<int>>& adj, vector<int>& colors) {
    colors.assign(num_vertices, UNASSIGNED);
    auto start_time = chrono::steady_clock::now();
    
    // Find connected components
    vector<vector<int>> components = findConnectedComponents(adj);
    cout << "Found " << components.size() << " connected components" << endl;
    
    // Process each component
    for (const auto& component : components) {
        // If component is small enough, color it directly
        if (component.size() <= SUBGRAPH_SIZE) {
            if (!colorSubgraph(colors, adj, component, num_colors)) {
                return false;
            }
            continue;
        }
        
        // Split large components into overlapping subgraphs
        for (int i = 0; i < component.size(); i += SUBGRAPH_SIZE/2) {
            // Create subgraph with overlap
            vector<int> subgraph_vertices;
            for (int j = i; j < min(i + SUBGRAPH_SIZE, (int)component.size()); j++) {
                subgraph_vertices.push_back(component[j]);
            }
            
            // Try to color the subgraph
            if (!colorSubgraph(colors, adj, subgraph_vertices, num_colors)) {
                return false;
            }
            
            // Check timeout
            auto current_time = chrono::steady_clock::now();
            if (chrono::duration_cast<chrono::seconds>(current_time - start_time).count() > TIMEOUT_SECONDS) {
                cout << "\nTimeout reached after " << TIMEOUT_SECONDS << " seconds." << endl;
                return false;
            }
        }
    }
    
    // Verify the coloring
    for (int v = 0; v < num_vertices; v++) {
        if (colors[v] == UNASSIGNED) {
            return false;
        }
        for (int u : adj[v]) {
            if (colors[v] == colors[u]) {
                return false;
            }
        }
    }
    
    return true;
}

// Structure to represent an individual in the population
struct Individual {
    vector<int> colors;
    int fitness;
    
    Individual(int size) : colors(size), fitness(0) {}
    
    // Initialize with random colors
    void randomize(int num_colors) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, num_colors - 1);
        for (int& color : colors) {
            color = dis(gen);
        }
    }
};

// Calculate fitness of an individual (number of conflicts to minimize)
int calculateFitness(const Individual& ind, const vector<vector<int>>& adj) {
    int conflicts = 0;
    for (int v = 0; v < adj.size(); v++) {
        for (int u : adj[v]) {
            if (ind.colors[v] == ind.colors[u]) {
                conflicts++;
            }
        }
    }
    return conflicts;
}

// Tournament selection
Individual& tournamentSelect(vector<Individual>& population) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, population.size() - 1);
    
    Individual* best = &population[dis(gen)];
    for (int i = 1; i < TOURNAMENT_SIZE; i++) {
        Individual& competitor = population[dis(gen)];
        if (competitor.fitness < best->fitness) {
            best = &competitor;
        }
    }
    return *best;
}

// Enhanced crossover operation with multiple crossover points
Individual crossover(const Individual& parent1, const Individual& parent2) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, parent1.colors.size() - 1);
    
    Individual child(parent1.colors.size());
    int num_points = 3;  // Number of crossover points
    vector<int> points;
    
    // Generate crossover points
    for (int i = 0; i < num_points; i++) {
        points.push_back(dis(gen));
    }
    sort(points.begin(), points.end());
    
    // Perform multi-point crossover
    int current_parent = 0;
    for (int i = 0; i < parent1.colors.size(); i++) {
        if (current_parent < points.size() && i >= points[current_parent]) {
            current_parent++;
        }
        child.colors[i] = (current_parent % 2 == 0) ? parent1.colors[i] : parent2.colors[i];
    }
    
    return child;
}

// Mutation operation
void mutate(Individual& ind, int num_colors) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    uniform_int_distribution<> color_dis(0, num_colors - 1);
    
    for (int& color : ind.colors) {
        if (dis(gen) < MUTATION_RATE) {
            color = color_dis(gen);
        }
    }
}

// Enhanced local search with depth
void localSearch(Individual& ind, const vector<vector<int>>& adj, int num_colors) {
    bool improved;
    int depth = 0;
    
    do {
        improved = false;
        for (int v = 0; v < adj.size(); v++) {
            // Count conflicts for current color
            int current_conflicts = 0;
            for (int u : adj[v]) {
                if (ind.colors[v] == ind.colors[u]) {
                    current_conflicts++;
                }
            }
            
            if (current_conflicts > 0) {
                // Try each color
                int best_color = ind.colors[v];
                int min_conflicts = current_conflicts;
                
                for (int c = 0; c < num_colors; c++) {
                    if (c != ind.colors[v]) {
                        int conflicts = 0;
                        for (int u : adj[v]) {
                            if (c == ind.colors[u]) {
                                conflicts++;
                            }
                        }
                        if (conflicts < min_conflicts) {
                            min_conflicts = conflicts;
                            best_color = c;
                        }
                    }
                }
                
                if (best_color != ind.colors[v]) {
                    ind.colors[v] = best_color;
                    improved = true;
                }
            }
        }
        depth++;
    } while (improved && depth < LOCAL_SEARCH_DEPTH);
}

// Main coloring function using genetic algorithm
bool graphColoringGenetic(int num_vertices, int num_colors, const vector<vector<int>>& adj, vector<int>& colors) {
    auto start_time = chrono::steady_clock::now();
    
    // Initialize population
    vector<Individual> population(POPULATION_SIZE, Individual(num_vertices));
    for (auto& ind : population) {
        ind.randomize(num_colors);
        ind.fitness = calculateFitness(ind, adj);
    }
    
    // Main genetic algorithm loop
    int generation = 0;
    int stagnation = 0;
    int best_fitness = INT_MAX;
    
    while (generation < MAX_GENERATIONS) {
        // Check timeout
        auto current_time = chrono::steady_clock::now();
        if (chrono::duration_cast<chrono::seconds>(current_time - start_time).count() > TIMEOUT_SECONDS) {
            cout << "\nTimeout reached after " << TIMEOUT_SECONDS << " seconds." << endl;
            return false;
        }
        
        // Create new generation
        vector<Individual> new_population;
        
        // Elitism: keep best individual
        auto best_it = min_element(population.begin(), population.end(),
            [](const Individual& a, const Individual& b) { return a.fitness < b.fitness; });
        new_population.push_back(*best_it);
        
        // Generate rest of new population
        while (new_population.size() < POPULATION_SIZE) {
            // Select parents
            Individual& parent1 = tournamentSelect(population);
            Individual& parent2 = tournamentSelect(population);
            
            // Create child through crossover
            Individual child = crossover(parent1, parent2);
            
            // Mutate
            mutate(child, num_colors);
            
            // Local search
            localSearch(child, adj, num_colors);
            
            // Calculate fitness
            child.fitness = calculateFitness(child, adj);
            
            new_population.push_back(child);
        }
        
        // Replace old population
        population = move(new_population);
        
        // Update best fitness and check for stagnation
        int current_best = population[0].fitness;
        if (current_best < best_fitness) {
            best_fitness = current_best;
            stagnation = 0;
        } else {
            stagnation++;
        }
        
        // Print progress
        if (generation % 10 == 0) {
            cout << "\rGeneration " << generation << ", Best fitness: " << best_fitness 
                 << ", Stagnation: " << stagnation << flush;
        }
        
        // Check if solution found
        if (best_fitness == 0) {
            colors = population[0].colors;
            cout << "\nSolution found in generation " << generation << endl;
            return true;
        }
        
        // Check for stagnation
        if (stagnation > 100) {
            // Introduce diversity
            for (int i = POPULATION_SIZE/2; i < POPULATION_SIZE; i++) {
                population[i].randomize(num_colors);
                population[i].fitness = calculateFitness(population[i], adj);
            }
            stagnation = 0;
        }
        
        generation++;
    }
    
    // If we reach here, we couldn't find a perfect solution
    // Return the best solution found
    auto best_it = min_element(population.begin(), population.end(),
        [](const Individual& a, const Individual& b) { return a.fitness < b.fitness; });
    colors = best_it->colors;
    
    return false;
}

// --- 图加载函数 (修改以在找到第一个解时停止) ---
void loadGraph(const string& filename, vector<vector<int>>& adj, int& num_vertices, int& num_edges) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    // First pass: find max vertex number to determine num_vertices
    num_vertices = 0;
    num_edges = 0;
    string line;
    while (getline(infile, line)) {
        if (line[0] == 'e') {
            stringstream ss(line);
            char type;
            int u, v;
            ss >> type >> u >> v;
            num_vertices = max(num_vertices, max(u, v));
            num_edges++;
        }
    }

    // Initialize adjacency list with correct size
    adj.assign(num_vertices, vector<int>());

    // Second pass: build adjacency list
    infile.clear();
    infile.seekg(0);
    while (getline(infile, line)) {
        if (line[0] == 'e') {
            stringstream ss(line);
            char type;
            int u, v;
            ss >> type >> u >> v;
            // Convert to 0-based indexing
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    infile.close();

    // Sort adjacency lists for better performance
    for (auto& neighbors : adj) {
        sort(neighbors.begin(), neighbors.end());
        neighbors.erase(unique(neighbors.begin(), neighbors.end()), neighbors.end());
    }
}

// --- 函数：将着色方案输出到文件 ---
void outputColoringToFile(const string& base_filename, int num_colors, const vector<int>& colors) {
    string output_filename = base_filename;
    size_t dot_pos = output_filename.rfind(".col");
    if (dot_pos != string::npos) {
        output_filename.replace(dot_pos, 4, "");
    }
    output_filename += "_colored_" + to_string(num_colors) + ".txt";

    ofstream outfile(output_filename);
    if (!outfile.is_open()) {
        cerr << "Error: Could not create output file " << output_filename << endl;
        return;
    }

    outfile << "Graph Coloring Solution" << endl;
    outfile << "Number of vertices: " << colors.size() << endl;
    outfile << "Number of colors: " << num_colors << endl;
    outfile << "---------------------------------" << endl;
    outfile << "Vertex Index (0-based): Color" << endl;
    outfile << "---------------------------------" << endl;

    for (size_t i = 0; i < colors.size(); ++i) {
        outfile << i << ": " << colors[i] << endl;
    }

    outfile.close();
    cout << "Solution saved to file: " << output_filename << endl;
}

int main() {
    vector<vector<int>> adj;
    int num_vertices = 0;
    int num_edges = 0;
    vector<int> colors;

    cout << "=== Experiment 2: Map Coloring ===" << endl;

    vector<pair<string, int>> files_and_colors = {
        {"le450_5a.col", 5},
        {"le450_15b.col", 15},
        {"le450_25a.col", 25}
    };

    for (const auto& entry : files_and_colors) {
        string filename = entry.first;
        int num_colors = entry.second;

        cout << "\nProcessing file " << filename << " with " << num_colors << " colors..." << endl;

        try {
            loadGraph(filename, adj, num_vertices, num_edges);
            cout << "Graph loaded: " << num_vertices << " vertices, " << num_edges << " edges." << endl;

            auto start = chrono::high_resolution_clock::now();
            cout << "Starting coloring algorithm..." << endl;
            bool success = graphColoringGenetic(num_vertices, num_colors, adj, colors);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = end - start;

            cout << "\n";  // New line after progress indicator
            if (success) {
                cout << "Successfully found a " << num_colors << "-coloring solution!" << endl;
                outputColoringToFile(filename, num_colors, colors);
            }
            else {
                cout << "Could not color the graph with " << num_colors << " colors." << endl;
                // Save partial solution
                outputColoringToFile(filename + "_partial", num_colors, colors);
            }

            cout << "Time taken: " << fixed << setprecision(6) << elapsed.count() << " seconds" << endl;
        }
        catch (const exception& e) {
            cerr << "Error processing " << filename << ": " << e.what() << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}

