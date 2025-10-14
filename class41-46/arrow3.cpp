#include <iostream>

// 1. 基本结构体
struct Vector3 {
    float x, y, z;
};

// 2. 实体类
class Entity {
public:
    void Print() const { std::cout << "Hello from Entity!" << std::endl; }
};

// 3. 智能指针类（重载 ->）
class ScopedPtr {
private:
    Entity* m_Obj;

public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {}
    ~ScopedPtr() { delete m_Obj; }

    Entity* operator->() {
        return m_Obj;
    }
};

// 4. 主函数
int main() {
    // 示例1：基本箭头操作符
    Entity e;
    Entity* ptr = &e;
    ptr->Print();

    // 示例2：箭头操作符重载
    ScopedPtr scoped_entity = new Entity();
    scoped_entity->Print();  // 通过重载的 -> 调用

    // 示例3：获取成员偏移量
    std::size_t offsetx = reinterpret_cast<std::size_t>(&((Vector3*)0)->x);
    std::size_t offsety = reinterpret_cast<std::size_t>(&((Vector3*)0)->y);
    std::size_t offsetz = reinterpret_cast<std::size_t>(&((Vector3*)0)->z);

    std::cout << "x offset: " << offsetx << std::endl;
    std::cout << "y offset: " << offsety << std::endl;
    std::cout << "z offset: " << offsetz << std::endl;

    return 0;
}