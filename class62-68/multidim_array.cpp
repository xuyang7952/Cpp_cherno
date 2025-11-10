#include <iostream>
#include <vector>
#include <chrono>

// =============================
// 示例1：静态二维数组（栈）
// =============================
void static_array_example() {
    std::cout << "=== 1. 静态二维数组 ===\n";
    int grid[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// =============================
// 示例2：动态二维数组（指针数组）—— 不推荐
// =============================
void bad_dynamic_example(int rows, int cols) {
    std::cout << "\n=== 2. 动态二维数组（指针数组）—— 不推荐 ===\n";

    int** grid = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = i * cols + j;
        }
    }

    // 打印
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }

    // 释放内存（容易出错）
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

// =============================
// 示例3：一维数组模拟二维（推荐）
// =============================
void flat_array_example(int rows, int cols) {
    std::cout << "\n=== 3. 一维数组模拟二维（推荐）===\n";

    int* grid = new int[rows * cols];

    // 初始化
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i * cols + j] = i * cols + j;
        }
    }

    // 打印
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i * cols + j] << " ";
        }
        std::cout << "\n";
    }

    delete[] grid;
}

// =============================
// 示例4：std::vector（最推荐）
// =============================
void vector_example(int rows, int cols) {
    std::cout << "\n=== 4. std::vector（最推荐）===\n";

    // 方式1：vector of vectors
    std::vector<std::vector<int>> grid1(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid1[i][j] = i * cols + j;
        }
    }

    // 打印
    for (const auto& row : grid1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    // 方式2：单维 vector 模拟二维（更高性能）
    std::vector<int> grid2(rows * cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid2[i * cols + j] = i * cols + j;
        }
    }
}

// =============================
// 示例5：性能对比测试
// =============================
void performance_test() {
    const int N = 1000;
    const int ITERATIONS = 100;

    std::cout << "\n=== 5. 性能对比测试（" << N << "x" << N << "）===\n";

    // 测试一维数组方式
    int* flat = new int[N * N];
    auto start = std::chrono::steady_clock::now();

    for (int loop = 0; loop < ITERATIONS; ++loop) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                flat[i * N + j] = i + j;
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto flat_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    delete[] flat;

    // 测试 vector of vector（略慢）
    std::vector<std::vector<int>> grid(N, std::vector<int>(N));
    start = std::chrono::steady_clock::now();

    for (int loop = 0; loop < ITERATIONS; ++loop) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                grid[i][j] = i + j;
            }
        }
    }

    end = std::chrono::steady_clock::now();
    auto vec_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "一维数组模拟耗时: " << flat_time.count() << " ms\n";
    std::cout << "vector of vector 耗时: " << vec_time.count() << " ms\n";
    std::cout << "(差异主要来自缓存局部性和内存分配模式)\n";
}

// =============================
// 主函数
// =============================
int main() {
    static_array_example();
    bad_dynamic_example(4, 5);
    flat_array_example(4, 5);
    vector_example(4, 5);
    performance_test();

    return 0;
}