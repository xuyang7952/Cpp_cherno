#include <iostream>
#include <cstddef>

class Entity {
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

struct Vector3 {
    float x, y, z;
};


int main() {
    Entity e;
    Entity* ptr = &e;

    e.Print();        // 直接调用
    ptr->Print();     // 通过指针调用
    (*ptr).Print();   // 等价写法，但更繁琐

    // 使用 new 分配内存，需要手动管理生命周期，返回的是指针，用指针调用，-> 或 (*ptr).Print()
    Entity* ptr2 = new Entity();
    ptr2->Print();
    delete ptr2;

    // 验证结构体成员偏移量
    std::size_t offsetx = reinterpret_cast<std::size_t>(&((Vector3*)0)->x);
    std::size_t offsety = reinterpret_cast<std::size_t>(&((Vector3*)0)->y);
    std::size_t offsetz = reinterpret_cast<std::size_t>(&((Vector3*)0)->z);
    std::cout << offsetx << std::endl;  // 输出: 0
    std::cout << offsety << std::endl;  // 输出: 4
    std::cout << offsetz << std::endl;  // 输出: 8
}