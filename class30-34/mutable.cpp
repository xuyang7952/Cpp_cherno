#include <iostream>
#include <string>

class Entity
{
private:
    std::string name;
    mutable int m_debugCount = 0;
public:
    // - return &name; 会返回 name 的地址（即指针），类型是 std::string*
    // - 而我们需要返回引用，所以直接写 return name; 配合返回类型中的 & 符号即可
    // - 虽然函数体内直接写 return name; ，但由于返回类型被声明为 const std::string& （常量字符串引用），编译器会自动将 name 转换为引用返回
    // - 这意味着函数返回的是对成员变量 name 的引用，而不是创建 name 的副本
    const std::string& GetName() const
    {
        m_debugCount++;
        return name;
    };
};

int main()
{
    const Entity e;
    std::cout << e.GetName() << std::endl;
    std::cout << e.GetName() << std::endl;
    // std::cout << e.m_debugCount << std::endl;

    int x =8;
    // auto f =[&](){
    auto f =[=]()mutable{ 
        x++;
        std::cout << "x：" << x << std::endl;
    };
    f();
    std::cout << "x：" << x << std::endl;
    return 0;
}