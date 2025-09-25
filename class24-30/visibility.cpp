#include<iostream>

class Entity
{
// private: // 私有区域
// protected: // 保护区域
public: // 公有区域
    int X, Y;
    void Print() {}
public: // 公共区域
    Entity()
    {
        X = 0;    //  正确：类内部可以访问私有成员
        Print();   //  正确
    }
};

class Player : public Entity // 派生类
{
public:
    Player()
    {
        X = 2;    //  正确：派生类可以访问基类的保护成员
        Print();   //  正确
    }
};

int main()
{
    Entity e;
    e.Print(); // ❌ 错误：非派生类外部无法访问保护成员
    e.X = 2;   // ❌ 错误
}