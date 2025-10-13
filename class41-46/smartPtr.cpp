#include <iostream>
#include <memory>
#include <vector>

class Entity {
public:
    Entity() { std::cout << "Created Entity\n"; }
    ~Entity() { std::cout << "Destroyed Entity\n"; }
    void Print() const { std::cout << "Entity is alive!\n"; }
};

int main() {
    std::cout << "=== unique_ptr ===\n";
    {
        auto unique = std::make_unique<Entity>();
        unique->Print();
    } // unique 出作用域，自动销毁

    std::cout << "\n=== shared_ptr ===\n";
    {
        auto shared = std::make_shared<Entity>();
        auto shared2 = shared;  // 共享所有权
        shared->Print();
    } // 引用计数为0，自动销毁

    std::cout << "\n=== weak_ptr ===\n";
    {
        auto shared = std::make_shared<Entity>();
        std::weak_ptr<Entity> weak = shared;

        if (auto ptr = weak.lock()) {
            ptr->Print();
        }

        // shared 出作用域，对象被销毁
        // 再次检查 weak
        if (auto ptr = weak.lock()) {
            ptr->Print();
        } else {
            std::cout << "Entity already destroyed\n";
        }
    }

    return 0;
}