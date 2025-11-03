#include <iostream>
#include <array>      // 必须包含头文件
#include <algorithm>  // 用于 std::sort 等
#include <stdexcept>  // 用于捕获异常

// 打印数组的模板函数
template<typename T, size_t N>
void PrintArray(const std::array<T, N>& arr) {
    std::cout << "Array contents: ";
    for (const auto& elem : arr) {  // 范围 for 循环
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

// 使用迭代器遍历
template<typename T, size_t N>
void PrintWithIterator(const std::array<T, N>& arr) {
    std::cout << "Using iterator: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. 声明与初始化
    std::array<int, 5> data = {10, 20, 30, 40, 50};  // 初始化列表
    std::array<double, 3> values{};                   // 全部初始化为 0.0
    std::array<std::string, 2> names = {"Alice", "Bob"};

    // 2. 访问元素
    data[0] = 100;                    // 使用 operator[]
    data.at(4) = 500;                 // 使用 at()（带边界检查）

    // 3. 安全访问示例（演示异常处理）
    try {
        data.at(10) = 999;            // 越界访问，抛出 std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // 4. 获取大小和遍历
    std::cout << "Size of data: " << data.size() << "\n";     // 输出 5
    std::cout << "Is empty? " << (data.empty() ? "Yes" : "No") << "\n";

    PrintArray(data);
    PrintWithIterator(data);

    // 5. 使用 STL 算法
    std::sort(data.begin(), data.end());
    std::cout << "After sorting: ";
    PrintArray(data);

    // 6. 拷贝数组
    std::array<int, 5> data_copy = data;  // 完全拷贝
    data_copy[0] = 999;
    std::cout << "Original: ";
    PrintArray(data);
    std::cout << "Copy: ";
    PrintArray(data_copy);

    return 0;
}