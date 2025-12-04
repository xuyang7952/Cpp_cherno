#include <iostream>
#include <cstring>
#include <cstdint>

class String {
public:
    // 默认构造函数
    String() = default;
    
    // 从 C 字符串初始化
    String(const char* str) {
        std::cout << "Created!\n";
        m_Size = std::strlen(str);
        m_Data = new char[m_Size];
        std::memcpy(m_Data, str, m_Size);
    }
    
    // 拷贝构造函数
    String(const String& other) {
        std::cout << "Copied!\n";
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        std::memcpy(m_Data, other.m_Data, m_Size);
    }
    
    // ✅ 移动构造函数（关键！）
    String(String&& other) noexcept {
        std::cout << "Moved!\n";
        // "偷取" other 的资源
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        // 将 other 置为有效但空的状态
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    
    // 析构函数
    ~String() {
        delete[] m_Data;
    }
    
    // 打印字符串内容
    void Print() const {
        if (m_Data) {
            for (uint32_t i = 0; i < m_Size; i++) {
                std::cout << m_Data[i];
            }
        }
        std::cout << "\n";
    }

private:
    char* m_Data = nullptr;
    uint32_t m_Size = 0;
};

class Entity {
public:
    // 构造函数接受右值引用（支持移动）
    explicit Entity(String&& name) : m_Name(std::move(name)) {}
    
    // 构造函数接受左值引用（支持拷贝）
    explicit Entity(const String& name) : m_Name(name) {}
    
    void PrintName() const {
        m_Name.Print();
    }

private:
    String m_Name;
};


int main() {
    std::cout << "=== Test 1: Moving temporary object ===\n";
    // 创建临时 String 对象并移动到 Entity
    Entity entity1(String("Cherno"));
    entity1.PrintName();
    
    std::cout << "\n=== Test 2: Copying named object ===\n";
    // 创建命名的 String 对象（左值）
    String name("Yan");
    Entity entity2(name);  // 这里会发生拷贝
    entity2.PrintName();
    
    std::cout << "\n=== Test 3: Explicit move ===\n";
    // 显式移动命名对象
    String name2("Explicit Move");
    Entity entity3(std::move(name2));  // 强制移动
    entity3.PrintName();
    
    // name2 现在处于有效但未指定的状态（通常是空）
    std::cout << "name2 after move: ";
    name2.Print();  // 应该输出空行
    
    return 0;
}