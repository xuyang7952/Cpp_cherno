#include <iostream>

class Entity {
public:
    void Print() const { std::cout << "Hello from Entity!" << std::endl; }
};

class ScopedPtr {
private:
    Entity* m_Obj;

public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {}
    ~ScopedPtr() { delete m_Obj; }

    // 重载 -> 操作符
    Entity* operator->() {
        return m_Obj;
    }
};


int main() {
    // 隐式转换（Implicit Conversion），构造函数中接受 Entity*单一参数，可以触发隐式转换
    // 可以将 Entity* 隐式转换为 ScopedPtr,
    ScopedPtr entity = new Entity();
    // operator->() 返回一个指向 Entity 的指针
    // C++ 会自动链式调用：entity->Print() → 先调用 operator->() 返回 m_Obj，再调用 m_Obj->Print()
    entity->Print();  // ✅ 正常运行！
    return 0;
}