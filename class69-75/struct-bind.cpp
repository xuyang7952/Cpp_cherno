#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <array>

// 示例1：结构体
struct Person {
    std::string name;
    int age;
    bool isStudent;
};

Person GetPerson() {
    return {"Bob", 22, true};
}

// 示例2：返回 tuple
std::tuple<double, double> GetCoordinates() {
    return {3.14, 2.71};
}

int main() {
    // 1. 解包结构体
    auto [name, age, student] = GetPerson();
    std::cout << "Name: " << name 
              << ", Age: " << age 
              << ", Student: " << (student ? "Yes" : "No") << "\n";

    // 2. 解包 tuple
    auto [x, y] = GetCoordinates();
    std::cout << "Coordinates: (" << x << ", " << y << ")\n";

    // 3. 解包 std::pair（如 map 的元素）
    std::map<std::string, int> scores = {{"Alice", 95}, {"Bob", 88}};
    for (const auto& [key, value] : scores) {
        std::cout << key << ": " << value << "\n";
    }

    // 4. 解包数组
    int numbers[3] = {10, 20, 30};
    auto [a, b, c] = numbers;
    std::cout << "Array unpacked: " << a << ", " << b << ", " << c << "\n";

    // 5. 使用引用避免拷贝（重要！）
    std::string longText = "This is a very long string...";
    struct Data { std::string text; int id; };
    Data d{longText, 42};

    auto& [ref_text, ref_id] = d; // 引用绑定
    ref_text += " (modified)";
    std::cout << "Modified: " << d.text << "\n";

    return 0;
}