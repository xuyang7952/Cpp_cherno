#include <iostream>
using namespace std;

class Entity
{
public:
    int *x;
    int y;
    // mutable 关键字用于修饰成员变量，即使在 const 成员函数中，被 mutable 修饰的成员变量也可以被修改。
    mutable int c;
public:
    // 第一个 const：表示返回的指针指向的内容是常量，不能通过该指针修改指向的内容
    // 第二个 const：表示返回的指针本身是常量，不能修改指针的指向
    // 第三个 const：表示该成员函数是常量成员函数，不能修改类的成员变量
    const int* const Getx()const
    {
        return x;
        c++; 
    }
    // const：表示该成员函数是常量成员函数，不能修改类的成员变量
    int Gety()const
    {
        return y;
    }
    // 非 const 版本的 Gety() 函数，用于非常量对象调用
    int Gety()
    {
        return y;
    }
};

// const 修饰参数
void printEntity(const Entity& e)
{
    cout << "Entity 的 x 指针指向的值为: " << *e.Getx() << endl;
    cout << "Entity 的 y 值为: " << e.Gety() << endl;
}

int main()
{
    const int MAX_AGE = 100;
    // MAX_AGE = 20; // error
    int* a =new int ;
    *a = 20;
    cout << "动态分配内存的值为: " << *a << endl;
    cout << "常量 MAX_AGE 的值为: " << MAX_AGE << endl;
    // 这里是将 MAX_AGE 的地址赋值给指针 a，这是合法的，但不建议这样做。
    // 因为 MAX_AGE 是一个常量，不应该被修改。
    a = (int*)&MAX_AGE;
    cout << "通过指针 a 访问 MAX_AGE 内存的值为: " << *a << endl;
    *a = 200;
    // 虽通过指针 a 成功修改了 MAX_AGE 所在内存的值（ *a = 200 后， *a 打印为200），但直接打印 MAX_AGE 时仍然显示原始值100。编译器的常量折叠优化
    // 编译器优化 ：对于编译期就能确定值的常量（如字面量初始化的const变量），编译器会进行 常量折叠 优化——在编译阶段直接将所有使用 MAX_AGE 的地方替换为其字面值100，而不是在运行时去内存中读取。
    // g++ -O0 const.cpp -o const0 关闭优化,还是未改变，编译器版本可能没法关闭基础的优化；
    cout << "修改后通过指针 a 访问 MAX_AGE 内存的值为: " << *a << endl;
    cout << "直接打印常量 MAX_AGE 的值为: " << MAX_AGE << endl;

    // 常量指针和指针常量
    // 常量指针：指向常量的指针，不能通过指针修改指向的内存中的值，但可以修改指针指向的地址。
    const int* b = new int(20);
    // int const * b = new int(20);  // 这两种写法是等价的，都是指向常量的指针。
    // *b = 200; // error
    cout << "常量指针 b 指向的值为: " << *b << endl;
    cout << "常量指针 b 的地址为: " << b << endl;
    b = a;
    cout << "修改指向后常量指针 b 指向的值为: " << *b << endl;
    cout << "修改指向后常量指针 b 的地址为: " << b << endl;
    // 指针常量：指针本身是常量，不能修改指针指向的地址，但可以通过指针修改指向的内存中的值。
    int* const c = a;
    cout << "指针常量 c 指向的值为: " << *c << endl;
    cout << "指针常量 c 的地址为: " << c << endl;
    *c = 200;
    cout << "修改值后指针常量 c 指向的值为: " << *c << endl;
    cout << "修改值后指针常量 c 的地址为: " << c << endl;

    const int* const d = b;
    cout << "常量指针常量 d 指向的值为: " << *d << endl;
    cout << "常量指针常量 d 的地址为: " << d << endl;
    // *d = 200; // error   
    return 0;
}