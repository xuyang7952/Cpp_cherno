// 注意：std::any需要C++17或更高版本
// 编译命令：g++ -std=c++17 any.cpp -o any
#include <iostream>
#include <any>
#include <string>
#include <vector>

int main() {
    std::any data;

    // 存储不同类型的值
    data = 42;                          // int
    // std::cout << "Stored int: " << data << "\n";
    std::cout << "Stored int: " << std::any_cast<int>(data) << "\n";

    data = std::string("Hello, any!");  // std::string
    std::cout << "Stored string: " << std::any_cast<std::string>(data) << "\n";

    data = std::vector<int>{1, 2, 3};   // std::vector<int>
    auto& vec = std::any_cast<std::vector<int>&>(data); // 用引用避免拷贝
    std::cout << "Stored vector: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\n";

    // 安全访问：避免异常
    if (data.type() == typeid(std::vector<int>)) {
        const auto& safe_vec = std::any_cast<const std::vector<int>&>(data);
        std::cout << "Safely accessed vector size: " << safe_vec.size() << "\n";
    }

    // 清空
    data.reset();
    std::cout << "Has value after reset? " << std::boolalpha << data.has_value() << "\n";

    // 错误示例：类型不匹配（会抛异常）
    try {
        data = 3.14;
        std::any_cast<int>(data); // 尝试把 double 当 int 读
    } catch (const std::bad_any_cast& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}