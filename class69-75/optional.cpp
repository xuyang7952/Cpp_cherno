#include <iostream>
#include <fstream>
#include <string>
#include <optional>

// 安全地读取文件内容：成功返回内容，失败返回空 optional
std::optional<std::string> ReadFileAsString(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (!stream.is_open()) {
        return std::nullopt; // 明确返回空值
    }

    // 使用更简单的方式读取文件内容
    std::string result;
    std::string line;
    while (std::getline(stream, line)) {
        result += line + "\n";
    }
    
    // 移除最后一个换行符（如果存在）
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    
    return std::make_optional<std::string>(result); // 使用make_optional函数
}

int main() {
    // g++ -std=c++17 optional.cpp -o optional,必须使用c++17及以上版本
    auto data = ReadFileAsString("data.txt");

    // 方法1：显式检查
    if (data) {
        std::cout << "File read successfully!\n";
        std::cout << "Content: " << *data << "\n";
    } else {
        std::cout << "Failed to read file.\n";
    }

    // 方法2：使用 value_or 提供默认值
    std::string content = data.value_or("File not found or empty");
    std::cout << "Final content: " << content << "\n";

    return 0;
}