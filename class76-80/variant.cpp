// 注意：std::variant需要C++17或更高版本
// 编译命令：g++ -std=c++17 variant.cpp -o variant
#include <iostream>
#include <variant>
#include <string>

// 模拟读取文件：成功返回内容，失败返回错误码
enum class ErrorCode {
    None = 0,
    NotFound = 1,
    NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileAsString(bool success) {
    if (!success) {
        return ErrorCode::NotFound;
    }
    return std::string("Hello, Cherno!");
}

int main() {
    // g++ -std=c++17 variant.cpp -o variant
    // 1. 基本用法：存储不同类型的值
    std::variant<std::string, int> data;

    data = "Cherno";  // 赋值为 string
    if (auto* str = std::get_if<std::string>(&data)) {
        std::cout << "String: " << *str << "\n";
    }

    data = 42;  // 赋值为 int
    if (auto* num = std::get_if<int>(&data)) {
        std::cout << "Number: " << *num << "\n";
    }

    // 2. 实际应用：函数返回多类型结果
    auto result = ReadFileAsString(false); // 模拟失败

    if (auto* err = std::get_if<ErrorCode>(&result)) {
        std::cout << "Error occurred: code " << static_cast<int>(*err) << "\n";
    } else if (auto* content = std::get_if<std::string>(&result)) {
        std::cout << "File content: " << *content << "\n";
    }

    return 0;
}