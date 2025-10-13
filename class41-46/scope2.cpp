#include <iostream>
#include <memory>
#include <chrono>

// 图片1的Entity类
class Entity {
public:
    Entity() { std::cout << "Created Entity\n"; }
    ~Entity() { std::cout << "Destroyed Entity\n"; }
};

// 图片4的作用域指针（现代版）
class ScopedTimer {
public:
    ScopedTimer() : start(std::chrono::high_resolution_clock::now()) {}
    ~ScopedTimer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = end - start;
        std::cout << "作用域耗时: " 
                  << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
                  << "微秒\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

int main() {
    std::cout << "=== C++栈生存期演示 ===\n";
    
    { // 作用域1：基本栈对象
        ScopedTimer timer;
        Entity e;  // 栈上创建
        std::cout << "在作用域内使用对象...\n";
    } // 自动销毁e和timer
    
    std::cout << "\n";
    
    { // 作用域2：智能指针管理堆对象
        ScopedTimer timer;
        auto ptr = std::make_unique<Entity>();  // 堆分配，自动管理
        std::cout << "使用智能指针对象...\n";
    } // 自动释放

    { // 使用堆创建对象
        ScopedTimer timer;
        Entity* e4 = new Entity();  // 堆分配
        std::cout << "使用堆指针对象...\n";
        delete e4;
    } // 手动释放e4
    
    std::cout << "\n";
    
    return 0;
}