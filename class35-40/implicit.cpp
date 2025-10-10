#include <iostream>
#include <string>

// 简单的日志宏
#define LOG(x) std::cout << x << std::endl

// Entity类定义（对应图片1）
class Entity {
private:
    std::string m_Name;
    int m_Age;
public:
    // 构造函数1：接受字符串（允许隐式转换）
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {
        LOG("字符串构造函数被调用: " << name);
    }
    
    // 构造函数2：接受整数（允许隐式转换）
    Entity(int age) : m_Name("Unknown"), m_Age(age) {
        LOG("整数构造函数被调用: " << age);
    }
    
    // 获取信息
    void PrintInfo() const {
        std::cout << "Name: " << m_Name << ", Age: " << m_Age << std::endl;
    }
};

// 演示隐式转换的函数（对应图片2）
void PrintEntity(const Entity& entity) {
    LOG("PrintEntity函数被调用");
    entity.PrintInfo();
}

// 使用explicit关键字的改进版本（对应图片2、3）
class SafeEntity {
private:
    std::string m_Name;
    int m_Age;
public:
    // 允许字符串的隐式转换（合理）
    SafeEntity(const std::string& name) : m_Name(name), m_Age(-1) {
        LOG("SafeEntity字符串构造: " << name);
    }
    
    // 使用explicit禁止整数的隐式转换（对应图片2、3）
    explicit SafeEntity(int age) : m_Name("Unknown"), m_Age(age) {
        LOG("SafeEntity整数构造: " << age);
    }
    
    void PrintInfo() const {
        std::cout << "SafeEntity - Name: " << m_Name << ", Age: " << m_Age << std::endl;
    }
};

void PrintSafeEntity(const SafeEntity& entity) {
    LOG("PrintSafeEntity函数被调用");
    entity.PrintInfo();
}

int main() {
    LOG("=== C++隐式转换与explicit关键字演示 ===");
    LOG("对应图片1、2、3的所有内容\n");
    
    // ============================================
    // 图片1内容：隐式转换基本用法
    // ============================================
    LOG("1. 隐式转换基本用法（图片1）");
    
    // 直接构造（推荐）
    Entity a("Cherno");
    a.PrintInfo();
    
    // 隐式转换：const char* → string → Entity，两次不行
    Entity b = std::string("Cherno");  // 一次隐式转换
    b.PrintInfo();
    
    // 隐式转换：int → Entity
    Entity c = 22;        // 一次隐式转换
    c.PrintInfo();
    
    LOG("");
    
    // ============================================
    // 图片2内容：隐式转换限制与问题
    // ============================================
    LOG("2. 隐式转换限制演示（图片2）");
    
    // ✅ 允许：一次隐式转换（int → Entity）
    PrintEntity(22);
    
    // ❌ 错误演示：需要两次转换（注释掉避免编译错误）
    // PrintEntity("Cherno");  // const char[7] → string → Entity
    LOG("错误：PrintEntity(\"Cherno\") 需要两次隐式转换，C++不允许！");
    
    // ✅ 解决方案1：显式转换为string
    LOG("解决方案1：显式转换为string");
    PrintEntity(std::string("Cherno"));  // 先显式转换
    
    // ✅ 解决方案2：显式构造Entity
    LOG("解决方案2：显式构造Entity");
    PrintEntity(Entity("Cherno"));      // 直接构造Entity
    
    LOG("");
    
    // ============================================
    // 图片2、3内容：explicit关键字用法
    // ============================================
    LOG("3. explicit关键字演示（图片2、3）");
    
    // SafeEntity的使用
    SafeEntity safe1("Nagi");
    safe1.PrintInfo();
    
    // ✅ 允许：字符串隐式转换（合理）
    SafeEntity safe2 = std::string("ImplicitString");
    safe2.PrintInfo();
    
    // ❌ 错误：explicit禁止整数隐式转换（注释掉）
    // SafeEntity safe3 = 25;  // 编译错误！
    LOG("错误：SafeEntity safe3 = 25; - explicit禁止隐式转换");
    
    // ✅ 必须显式调用构造函数
    LOG("正确用法：显式调用构造函数");
    SafeEntity safe4(25);           // 直接初始化
    SafeEntity safe5 = SafeEntity(30); // 显式构造
    safe4.PrintInfo();
    safe5.PrintInfo();
    
    // ✅ 函数调用也需要显式
    PrintSafeEntity(SafeEntity(35));  // 必须显式构造
    
    LOG("");
    
    // ============================================
    // 图片3内容：实际应用场景
    // ============================================
    LOG("4. 实际应用场景（图片3）");
    LOG("数学运算库：防止数字和向量意外比较");
    LOG("低级封装：避免偶然转换和性能问题");
    
    // 模拟数学库场景
    class Vector3 {
    public:
        explicit Vector3(float value) {  // 防止 float 隐式转为 Vector3
            LOG("Vector3显式构造: " << value);
        }
        
        // 禁止意外的比较操作
        bool operator==(const Vector3& other) const { return true; }
    };
    
    Vector3 vec(1.0f);
    // ❌ 以下代码会被explicit阻止（注释掉）
    // if (vec == 1.0f) {  // 编译错误：不能隐式转换
    //     LOG("意外的比较被阻止！");
    // }
    
    LOG("✅ explicit成功阻止了数字与向量的意外比较");
    
    LOG("\n=== 演示完成 ===");
    LOG("按Enter键退出...");
    std::cin.get();
    
    return 0;
}