// 包含输入输出流库，用于使用 std::cout 和 std::endl
#include <iostream>
// 包含字符串库，用于使用 std::string 类型
#include <string>

// 定义基类 Entity
class Entity
{
public:
    // 注释掉的非虚函数版本
    // std::string GetName() { return "Entity"; }
    // 定义虚函数 GetName，返回实体名称
    // virtual std::string GetName() { return "Entity"; }
    // 定义纯虚函数 GetName，返回实体名称
    virtual std::string GetName() = 0;
};

// 定义派生类 Player，继承自 Entity 类
class Player : public Entity
{
private:
    // 成员变量，存储玩家名称
    std::string m_Name;
public:
    // 构造函数，使用传入的名称初始化玩家名称
    Player(const std::string& name) : m_Name(name) {}
    // 注释掉的非重写版本
    // std::string GetName() { return m_Name; }
    // 重写基类的虚函数 GetName，返回玩家名称
    // 重写基类的纯虚函数 GetName，纯虚函数，必须继承重写
    std::string GetName() override { return m_Name; }
};

// 定义函数 func，接受一个 Entity 指针作为参数，打印实体名称
void func(Entity* e){
    std::cout << e->GetName() << std::endl;
};

// 主函数，程序入口
int main ()
{
    // 创建一个 Entity 对象, 不能实例化一个纯虚函数的类
    // Entity e;
    // 创建一个 Player 对象，名称为 "xuyang"
    Player p("xuyang");
    // 调用 func 函数打印 Entity 对象的名称
    // func(&e);
    // 调用 func 函数打印 Player 对象的名称
    func(&p);    
    return 0;
}