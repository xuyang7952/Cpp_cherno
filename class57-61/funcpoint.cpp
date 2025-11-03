#include <iostream>
#include <vector>
#include <string>

// 示例 1：基础函数指针
void SayHello() {
    std::cout << "Hello from SayHello!\n";
}

void SayGoodbye() {
    std::cout << "Goodbye from SayGoodbye!\n";
}

// 示例 2：带参数的函数
void PrintValue(int value) {
    std::cout << "Value: " << value << "\n";
}

// 示例 3：作为参数传递（通用遍历函数）
void ForEach(const std::vector<int>& values, void (*func)(int)) {
    for (int value : values) {
        func(value);
    }
}

// 示例 4：使用 typedef 定义别名（C 风格）
typedef void (*PrintFunc)(int);

// 示例 5：使用 using（现代 C++ 推荐）
using CallbackFunc = void (*)();

int main() {
    std::cout << "=== 1. 基础函数指针 ===\n";
    auto func1 = SayHello;         // auto 自动推导
    CallbackFunc func2 = SayGoodbye;

    func1();  // 调用
    func2();

    std::cout << "\n=== 2. 带参数的函数指针 ===\n";
    PrintFunc printFunc = PrintValue;
    printFunc(42);

    std::cout << "\n=== 3. 函数指针作为回调参数 ===\n";
    std::vector<int> numbers = {1, 5, 4, 2, 3};
    ForEach(numbers, PrintValue);  // 将函数传入

    std::cout << "\n=== 4. 使用 lambda 替代函数指针（更现代） ===\n";
    // 注意：lambda 如果捕获了外部变量，则不能转为函数指针
    // 但无捕获的 lambda 可以隐式转换为函数指针

    auto lambda = [](int value) {
        std::cout << "[Lambda] Value: " << value << "\n";
    };

    // 传递无捕获 lambda 给期望函数指针的函数
    ForEach(numbers, lambda);

    std::cout << "\n=== 5. 函数指针数组（函数表） ===\n";
    CallbackFunc functionTable[] = {SayHello, SayGoodbye};

    for (int i = 0; i < 2; ++i) {
        std::cout << "Calling function " << i << ":\n";
        functionTable[i]();
    }

    return 0;
}