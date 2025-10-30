#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// 模拟 Device 类
class Device {
public:
    int id;
    Device(int i) : id(i) {}
};

class DeviceManager {
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    DeviceManager() {
        m_Devices["GPU"].push_back(new Device(1));
        m_Devices["CPU"].push_back(new Device(2));
    }

    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const {
        return m_Devices;
    }

    ~DeviceManager() {
        for (auto& pair : m_Devices) {
            for (auto ptr : pair.second) {
                delete ptr;
            }
        }
    }
};

int main() {
    // === 1. 基础类型推导 ===
    auto a = 42;           // int
    auto b = 3.14159;      // double
    auto c = "Hello";      // const char*
    auto d = std::string("World"); // std::string

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << std::endl;

    // === 2. 简化迭代器 ===
    std::vector<std::string> fruits = {"Apple", "Orange", "Banana"};

    std::cout << "\nFruits:" << std::endl;
    for (auto it = fruits.begin(); it != fruits.end(); ++it) {
        std::cout << "- " << *it << std::endl;
    }

    // 范围 for + auto（推荐）
    std::cout << "\nFruits (range-based):" << std::endl;
    for (const auto& fruit : fruits) {
        std::cout << "- " << fruit << std::endl;
    }

    // === 3. 复杂类型推导 ===
    DeviceManager dm;
    const auto& devices = dm.GetDevices(); // 避免写超长类型

    std::cout << "\nDevices:" << std::endl;
    for (const auto& pair : devices) {
        std::cout << pair.first << ": " << pair.second.size() << " device(s)" << std::endl;
    }

    // === 4. auto 与函数返回值 ===
    // 这是 C++11 引入的 lambda 表达式语法：[] 捕获列表，() 参数列表，-> std::string 指定返回类型，
    // 语法：[] 捕获列表 -> 返回类型 { 函数体 }
    // 用法：把 lambda 存到 auto 变量里，像普通函数一样调用
    // 案例：无参返回 string
    auto getName = []() -> std::string {
        return "Cherno";
    };

    // 带参数案例：两数相加
    auto add = [](int x, int y) -> int {
        return x + y;
    };

    // 调用示例
    std::cout << "\ngetName(): " << getName() << std::endl;
    std::cout << "add(3,4): " << add(3, 4) << std::endl;

    auto name = getName(); // name 是 std::string
    std::cout << "\nName: " << name << std::endl;

    return 0;
}