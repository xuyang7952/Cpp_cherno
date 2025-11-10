#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // for std::greater
#include <string>

// 自定义结构体
struct Person {
    std::string name;
    int age;

    // 重载 << 便于打印
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.name << " (" << p.age << ")";
    }
};

int main() {
    std::cout << "=== C++ std::sort 演示 ===\n\n";

    // -----------------------------
    // 1. 整数默认升序排序
    // -----------------------------
    std::vector<int> nums = {5, 2, 8, 1, 9, 3};
    std::cout << "原始数组: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    std::sort(nums.begin(), nums.end()); // 默认升序

    std::cout << "升序排序: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n\n";

    // -----------------------------
    // 2. 使用 std::greater 降序
    // -----------------------------
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    std::cout << "降序排序: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n\n";

    // -----------------------------
    // 3. Lambda 自定义排序：按绝对值升序
    // -----------------------------
    std::vector<int> mixed = {-3, 4, -1, 2, -5};
    std::cout << "混合数组: ";
    for (int x : mixed) std::cout << x << " ";
    std::cout << "\n";

    std::sort(mixed.begin(), mixed.end(), [](int a, int b) {
        return std::abs(a) < std::abs(b); // 绝对值小的在前
    });

    std::cout << "按绝对值排序: ";
    for (int x : mixed) std::cout << x << " ";
    std::cout << "\n\n";

    // -----------------------------
    // 4. 特殊规则：把数字 1 放到最后
    // -----------------------------
    std::vector<int> special = {3, 1, 4, 1, 5, 9, 2, 6, 1};
    std::cout << "特殊数组: ";
    for (int x : special) std::cout << x << " ";
    std::cout << "\n";

    std::sort(special.begin(), special.end(), [](int a, int b) {
        if (a == 1) return false; // a 是 1，则不能放前面 → 放后面
        if (b == 1) return true;  // b 是 1，则 a 应该放前面
        return a < b;             // 其他情况正常升序
    });

    std::cout << "1 放最后: ";
    for (int x : special) std::cout << x << " ";
    std::cout << "\n\n";

    // -----------------------------
    // 5. 排序自定义对象（Person）
    // -----------------------------
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"Diana", 25}
    };

    std::cout << "原始人员列表:\n";
    for (const auto& p : people) std::cout << "  " << p << "\n";

    // 按年龄升序，同龄按名字字典序
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.age != b.age) {
            return a.age < b.age;
        }
        return a.name < b.name;
    });

    std::cout << "\n按年龄+姓名排序:\n";
    for (const auto& p : people) std::cout << "  " << p << "\n";
    std::cout << "\n";

    // -----------------------------
    // 6. 稳定排序演示（保留相等元素原顺序）
    // -----------------------------
    std::vector<std::pair<int, char>> data = {
        {2, 'a'}, {1, 'b'}, {2, 'c'}, {1, 'd'}
    };

    std::cout << "原始配对数据: ";
    for (auto p : data) std::cout << "(" << p.first << "," << p.second << ") ";
    std::cout << "\n";

    // 普通 sort（不稳定）
    auto unstable = data;
    std::sort(unstable.begin(), unstable.end(),
              [](const auto& x, const auto& y) { return x.first < y.first; });
    std::cout << "std::sort 结果: ";
    for (auto p : unstable) std::cout << "(" << p.first << "," << p.second << ") ";
    std::cout << "\n";

    // stable_sort（稳定）
    std::stable_sort(data.begin(), data.end(),
                     [](const auto& x, const auto& y) { return x.first < y.first; });
    std::cout << "std::stable_sort 结果: ";
    for (auto p : data) std::cout << "(" << p.first << "," << p.second << ") ";
    std::cout << "\n";

    return 0;
}