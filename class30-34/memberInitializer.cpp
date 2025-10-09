#include <iostream>
#include <string>

// 简单的日志宏（对应图片中的LOG）
#define LOG(x) std::cout << x << std::endl

// Example类（对应图片3）
class Example {
public:
    Example() {
        LOG("Example: Default constructor!");
    }

    Example(int x) {
        std::cout << "Example: Created with " << x << "!" << std::endl;
    }
};

// Entity类 - 演示正确的成员初始化列表用法
class Entity {
private:
    std::string m_Name;    // 声明顺序：m_Name在前
    int m_Score;           // m_Score其次
    Example m_Example;     // m_Example最后（对应图片2的顺序规则）
    
public:
    // ✅ 正确：使用成员初始化列表（高效）
    Entity() : m_Name("Unknown"), m_Score(8), m_Example(10) {
        LOG("Entity constructed with initializer list");
    }
    
    // ✅ 正确：带参数的构造函数
    Entity(const std::string& name, int score) 
        : m_Name(name), m_Score(score), m_Example(score) {
        std::cout << "Entity '" << m_Name << "' created with score " << m_Score << std::endl;
    }

    // ❌ 错误示范：在构造函数体内赋值（性能浪费）
    Entity(const std::string& name) {
        // 错误做法：先默认构造，再赋值
        m_Name = name;                    // std::string先默认构造，再赋值
        m_Score = 5;                      // int先默认初始化(垃圾值)，再赋值
        m_Example = Example(15);          // Example先默认构造，再赋值覆盖
        LOG("Entity constructed with assignment (inefficient)");
    }

    // 获取成员信息
    const std::string& GetName() const { return m_Name; }
    int GetScore() const { return m_Score; }
};

// 演示必须使用初始化列表的情况
class MustUseInitializerList {
private:
    const int m_ConstValue;    // const成员必须用初始化列表
    int& m_RefValue;           // 引用成员必须用初始化列表
public:
    MustUseInitializerList(int value, int& ref) 
        : m_ConstValue(value), m_RefValue(ref) {  // 必须在这里初始化
        // m_ConstValue = value;  // ❌ 错误：不能在函数体内初始化const成员
        // m_RefValue = ref;       // ❌ 错误：引用必须在构造时绑定
    }
    
    void Print() const {
        std::cout << "Const: " << m_ConstValue << ", Ref: " << m_RefValue << std::endl;
    }
};

int main() {
    std::cout << "=== 演示成员初始化列表的优势 ===\n" << std::endl;
    
    // 1. 使用初始化列表的高效构造
    std::cout << "1. 高效构造（使用初始化列表）:" << std::endl;
    Entity e1;  // 直接调用合适的构造函数
    std::cout << "Name: " << e1.GetName() << ", Score: " << e1.GetScore() << "\n" << std::endl;
    
    // 2. 低效构造的对比
    std::cout << "2. 低效构造（构造函数体内赋值）:" << std::endl;
    Entity e2("TestObject");  // 经历默认构造+赋值的浪费
    std::cout << "Name: " << e2.GetName() << ", Score: " << e2.GetScore() << "\n" << std::endl;
    
    // 3. 带参数的初始化列表
    std::cout << "3. 带参数的高效构造:" << std::endl;
    Entity e3("Cherno", 95);
    std::cout << "Name: " << e3.GetName() << ", Score: " << e3.GetScore() << "\n" << std::endl;
    
    // 4. 必须使用初始化列表的情况
    std::cout << "4. 必须使用初始化列表的情况:" << std::endl;
    int refValue = 100;
    MustUseInitializerList must(50, refValue);
    must.Print();
    
    std::cout << "\n=== 演示结束 ===" << std::endl;
    
    return 0;
}