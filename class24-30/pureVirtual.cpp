#include <iostream>
#include <string>

// 定义一个接口（包含纯虚函数的类）
class Printable {
public:
    virtual std::string GetClassName() = 0; // 纯虚函数
};

// Entity 类实现 Printable 接口
class Entity : public Printable {
public:
    virtual std::string GetName() { return "Entity"; }
    std::string GetClassName() override { return "Entity"; } // 实现纯虚函数
};

// Player 类继承 Entity 并重写方法
class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name) {}
    std::string GetName() override { return m_Name; }
    std::string GetClassName() override { return "Player"; } // 重写实现
};

// 独立的类实现 Printable 接口
class A : public Printable {
public:
    std::string GetClassName() override { return "A"; } // 实现纯虚函数
};


// 接受接口指针的函数，实现了“一个接口，多种实现”
void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}


int main() {
    Entity* e = new Entity();
    Player* p = new Player("Cherno");
    A* a = new A();
    // 调用 Print 函数打印不同对象的类名，实现多态
    Print(e); // 输出 "Entity"
    Print(p); // 输出 "Player"
    Print(a); // 输出 "A"

    // 不能实例化包含未实现纯虚函数的类
    // Printable obj; // 错误！Printable 是抽象类
}