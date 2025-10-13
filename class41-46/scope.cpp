#include<iostream>

class Entity {
public:
    // 添加对象标识成员
    static int s_Counter;
    int m_Id;

    Entity() : m_Id(++s_Counter) { std::cout << "Created Entity " << m_Id << "\n"; }
    ~Entity() { std::cout << "Destroyed Entity " << m_Id << "\n"; }
};

// 初始化静态成员变量
int Entity::s_Counter = 0;


// 作用域指针，自动管理堆内存，脱离作用域时自动释放
class ScopedPtr {
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr) : m_Ptr(ptr) {}
    ~ScopedPtr() { delete m_Ptr; }  // 自动释放！
};

int main() {
    { // 开始作用域
        Entity e;  // 栈上创建
        Entity* e2 = new Entity();  // new Entity() 操作符会：- 在 堆内存 中创建一个 Entity 对象 - 返回指向这个对象的 指针 （类型为 Entity* ）
        ScopedPtr e3 = new Entity();  // 堆分配，但自动管理
    } // 结束作用域，e自动销毁，e3中的对象也会自动销毁
    
    // delete e2;  // 手动释放 e2
    return 0;
}