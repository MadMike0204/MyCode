import pycuda.autoinit
import pycuda.driver as drv
from pycuda.compiler import SourceModule
import numpy as np
import os
os.environ['PATH'] += ';'+r"D:\Visual Studio\IDE\VC\Tools\MSVC\14.38.33130\bin\Hostx64\x64"
#神秘代码，不要改



def main():
    # 创建一个简单的 CUDA 核函数，实现向量加法
    mod = SourceModule("""
                       
    __global__ void vector_add(float *a, float *b, float *result, int n) {
        int idx = threadIdx.x + blockIdx.x * blockDim.x;
        if (idx < n) {
            result[idx] = a[idx] + b[idx];
        }
    }
    """)

    # 从模块中获取向量加法函数
    vector_add = mod.get_function("vector_add")

    # 生成两个大的随机向量
    n = 1024 * 1024  # 向量大小
    a = np.random.randn(n).astype(np.float32)
    b = np.random.randn(n).astype(np.float32)
    result = np.zeros_like(a)

    # 分配内存并将数据传输到 GPU
    a_gpu = drv.mem_alloc(a.nbytes)
    b_gpu = drv.mem_alloc(b.nbytes)
    result_gpu = drv.mem_alloc(result.nbytes)
    drv.memcpy_htod(a_gpu, a)
    drv.memcpy_htod(b_gpu, b)

    # 执行核函数
    threads_per_block = 256
    blocks_per_grid = (n + threads_per_block - 1) // threads_per_block
    vector_add(a_gpu, b_gpu, result_gpu, np.int32(n), block=(threads_per_block, 1, 1), grid=(blocks_per_grid, 1))

    # 将结果从 GPU 内存复制回主机
    drv.memcpy_dtoh(result, result_gpu)

    # 检查结果
    assert np.allclose(result, a + b)
    print("Vector addition executed correctly on GPU.")

if __name__ == "__main__":
    main()
