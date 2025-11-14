#include <iostream>
#include <typeinfo>
using namespace std;

// 基类（必须有虚函数才能用 dynamic_cast）
class Base {
public:
    virtual ~Base() = default; // 启用多态
};

class Derived : public Base {
public:
    void sayHello() { cout << "Hello from Derived!" << endl; }
};

class Another : public Base {};

int main() {
    cout << "=== 1. static_cast 示例 ===" << endl;
    {
        double d = 3.14159;
        int i = static_cast<int>(d);
        cout << "double -> int: " << d << " -> " << i << endl;

        // 指针向上转换（安全）
        Derived* derived = new Derived();
        Base* base = static_cast<Base*>(derived); // 向上转换，总是安全
        delete derived;
    }

    cout << "\n=== 2. dynamic_cast 示例 ===" << endl;
    {
        Base* ptr = new Derived(); // 实际指向 Derived 对象

        // 成功向下转换
        Derived* d = dynamic_cast<Derived*>(ptr);
        if (d) {
            d->sayHello();
        }

        // 失败的转换
        Another* a = dynamic_cast<Another*>(ptr);
        if (!a) {
            cout << "dynamic_cast to Another failed (nullptr returned)" << endl;
        }

        delete ptr;
    }

    cout << "\n=== 3. const_cast 示例 ===" << endl;
    {
        // 安全场景：原始对象不是 const
        char data[] = "Mutable String"; // 栈上数组，可修改
        const char* cstr = data;
        char* mutable_str = const_cast<char*>(cstr);
        mutable_str[0] = 'm'; // OK: 修改的是非 const 对象
        cout << "After const_cast and modify: " << mutable_str << endl;
    }

    cout << "\n=== 4. reinterpret_cast 示例 ===" << endl;
    {
        int value = 0x41424344; // ASCII: A=0x41, B=0x42, C=0x43, D=0x44
        char* bytes = reinterpret_cast<char*>(&value);

        cout << "Interpreting int as bytes (may vary by endianness): ";
        for (int i = 0; i < static_cast<int>(sizeof(int)); ++i) {
            if (bytes[i] >= 32 && bytes[i] <= 126) // 可打印 ASCII
                cout << bytes[i];
            else
                cout << '?';
        }
        cout << endl;
    }

    cout << "\n✅ 所有类型转换示例执行完毕。" << endl;
    return 0;
}