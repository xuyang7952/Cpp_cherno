#include <iostream>

// 基类 (Base Class)
class Entity {
public:
    float X, Y;
    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

// 派生类 (Derived Class)，使用 : 来继承
// 使用 public 继承方式
class Player : public Entity { // Player 公有继承自 Entity
public:
    const char* Name;
    void PrintName() {
        std::cout << Name << std::endl;
    }
};

int main ()
{
    Player player;
    player.X = 10.0f;
    player.Y = 20.0f;
    player.Move(1.0f, 2.0f);
    std::cout << "x: " << player.X << ", y: " << player.Y << std::endl;
    // 派生类的大小 = 基类的大小 + 派生类自己的大小
    std::cout << sizeof(Entity)<< std::endl;
    std::cout << sizeof(Player)<< std::endl;
    player.Name = "cherno";
    player.PrintName();
    return 0;
}