#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // std::function
#include <string>

// 通用遍历函数，接受 std::function 类型的回调
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value : values) {
        func(value);
    }
}

int main() {
    std::vector<int> values = {1, 5, 4, 2, 3};
    int factor = 2;
    std::string prefix = "Value: ";

    std::cout << "=== 1. 最简单的 Lambda ===\n";
    std::for_each(values.begin(), values.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n\n";

    std::cout << "=== 2. 使用捕获列表 [factor]（值捕获）===\n";
    std::for_each(values.begin(), values.end(), [factor](int x) {
        std::cout << x * factor << " ";  // 使用外部变量
    });
    std::cout << "\n\n";

    std::cout << "=== 3. 引用捕获 [&prefix] 修改外部变量 ===\n";
    std::for_each(values.begin(), values.end(), [&prefix](int x) {
        std::cout << prefix << x << "\n";
        prefix += "*";  // 修改原始变量
    });
    std::cout << "After loop, prefix = '" << prefix << "'\n\n";

    std::cout << "=== 4. mutable：修改值捕获的副本 ===\n";
    int counter = 0;
    auto lambda = [counter]() mutable {
        counter++;
        std::cout << "Counter: " << counter << "\n";
    };
    lambda(); // Counter: 1
    lambda(); // Counter: 2
    std::cout << "Original counter: " << counter << " (unchanged)\n\n";

    std::cout << "=== 5. 使用 ForEach 函数传入 lambda ===\n";
    ForEach(values, [](int value) {
        std::cout << "[Processed] " << value << "\n";
    });

    std::cout << "\n=== 6. 用于 std::find_if 查找 >3 的第一个元素 ===\n";
    auto it = std::find_if(values.begin(), values.end(), [](int value) {
        return value > 3
        ;
    });
    if (it != values.end()) {
        std::cout << "First element > 3 is: " << *it << "\n";
    }

    std::cout << "\n=== 7. 用于 std::sort 自定义排序 ===\n";
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();  // 按长度升序排序
    });
    std::cout << "Sorted by length: ";
    for (const auto& w : words) {
        std::cout << w << "(" << w.length() << ") ";
    }
    std::cout << "\n";

    return 0;
}