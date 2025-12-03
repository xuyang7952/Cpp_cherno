#include <iostream>
#include <string>

// 函数返回普通值（右值）
int GetValue() {
    return 10;
}

// 函数返回左值引用
int& GetLValue() {
    static int value = 20;  // static 确保生命周期足够长
    return value;
}

void BasicConcepts() {
    std::cout << "=== Basic Concepts ===\n";
    
    // 左值示例
    int i = 10;                    // i 是左值
    int a = i;                     // 可以用左值初始化
    
    // 右值示例
    int b = GetValue();            // GetValue() 返回右值
    int c = i + 5;                 // 表达式结果是右值
    
    // 验证左值/右值特性
    std::cout << "&i = " << &i << " (can take address)\n";  // ✅ 左值可取地址
    // std::cout << "&(i+5) = " << &(i+5) << "\n";         // ❌ 右值不能取地址
    
    // 赋值测试
    i = 100;                       // ✅ 左值可以被赋值
    // 10 = i;                     // ❌ 右值不能被赋值（编译错误）
    
    // 左值引用函数返回值
    GetLValue() = 30;              // ✅ 可以赋值，因为返回左值引用
    std::cout << "GetLValue() = " << GetLValue() << "\n";
}


void ReferenceBindingRules() {
    std::cout << "\n=== Reference Binding Rules ===\n";
    
    int x = 42;
    
    // 左值引用
    int& lref1 = x;                // ✅ OK - 左值绑定左值引用
    // int& lref2 = 100;           // ❌ Error - 右值不能绑定非const左值引用
    const int& lref3 = 100;        // ✅ OK - 右值可以绑定const左值引用
    
    std::cout << "lref1 = " << lref1 << ", lref3 = " << lref3 << "\n";
    
    // 右值引用
    int&& rref1 = 200;             // ✅ OK - 右值绑定右值引用
    // int&& rref2 = x;            // ❌ Error - 左值不能绑定右值引用
    int&& rref3 = std::move(x);    // ✅ OK - std::move将左值转为右值
    
    std::cout << "rref1 = " << rref1 << ", rref3 = " << rref3 << "\n";
    std::cout << "x after move = " << x << " (value may be unspecified)\n";
}


// 重载函数：区分左值和右值
void PrintName(const std::string& name) {
    std::cout << "[lvalue] " << name << std::endl;
}

void PrintName(std::string&& name) {
    std::cout << "[rvalue] " << name << std::endl;
}

void FunctionOverloading() {
    std::cout << "\n=== Function Overloading ===\n";
    
    std::string firstName = "Yan";
    std::string lastName = "Chernikov";
    
    // fullName 是左值
    std::string fullName = firstName + lastName;
    
    PrintName(fullName);                    // 调用 const& 版本（左值）
    PrintName(firstName + lastName);        // 调用 && 版本（右值）
    
    // 显式移动
    PrintName(std::move(fullName));         // 调用 && 版本（强制转为右值）
}


class ExpensiveObject {
public:
    ExpensiveObject(const std::string& name) : mName(name) {
        std::cout << "ExpensiveObject created: " << mName << std::endl;
    }
    
    // 拷贝构造函数
    ExpensiveObject(const ExpensiveObject& other) : mName(other.mName) {
        std::cout << "Copy constructor called for: " << mName << std::endl;
    }
    
    // 移动构造函数
    ExpensiveObject(ExpensiveObject&& other) noexcept : mName(std::move(other.mName)) {
        std::cout << "Move constructor called for: " << mName << std::endl;
    }
    
    const std::string& getName() const { return mName; }
    
private:
    std::string mName;
};

// 接受左值和右值的函数
void ProcessObject(const ExpensiveObject& obj) {
    std::cout << "Processing (copy): " << obj.getName() << std::endl;
}

void ProcessObject(ExpensiveObject&& obj) {
    std::cout << "Processing (move): " << obj.getName() << std::endl;
    // 这里可以"偷取"obj的资源，因为它是临时对象
}

void PerformanceOptimization() {
    std::cout << "\n=== Performance Optimization ===\n";
    
    ExpensiveObject obj1("Persistent Object");
    ExpensiveObject tempObj("Temporary Object");
    
    // 处理持久对象（需要拷贝）
    ProcessObject(obj1);
    
    // 处理临时对象（可以移动，避免拷贝）
    ProcessObject(ExpensiveObject("Another Temporary"));
}

int main() {
    BasicConcepts();
    ReferenceBindingRules();
    FunctionOverloading();
    PerformanceOptimization();
    
    return 0;
}