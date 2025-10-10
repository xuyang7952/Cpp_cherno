#include <iostream>
#include <string>

class Entity {
public:
    std::string m_Name;
    int m_Age;
public:
    // 两个构造函数允许隐式转换
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {};
    Entity(int age) : m_Name("Unknown"), m_Age(age) {};
};

int main() {
    // Entity a = "Cherno";    // 隐式转换：const char* → string → Entity,只允许一次隐式转换
    Entity a = std::string("Cherno");    // 隐式转换：const char* → string → Entity
    Entity b = 22;          // 隐式转换：int → Entity
    std::cout << a.m_Name << std::endl;
    std::cout << b.m_Age << std::endl;
    // 等价于：Entity b = Entity(22);
}