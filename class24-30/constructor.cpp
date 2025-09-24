// 构造函数
#include <iostream>

class Entity{
public:
    float x,y;
    // 构造函数，
    Entity(){
        x = 0.0f;
        y = 0.0f;
        std::cout << "Entity constructor" << std::endl;
    }
    Entity(float x, float y){
        this->x = x;
        this->y = y;
    }
    void print(){
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
    ~Entity(){
        std::cout << "Entity destructor" << std::endl;
    }
};

class Log{
private:
    // Log() {}; // 禁止构造函数
public:
    Log() = delete;// 禁止构造函数
    static void Write(){};
};

void func(){
    Entity e;
    e.print(); // 实例结束后，调用析构函数
};

int main ()
{
    // Entity e;
    // std::cout << "x: " << e.x << ", y: " << e.y << std::endl;
    // e.print();
    func();
    return 0;
}