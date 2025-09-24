# include <iostream>

class Player {
public: // 公有成员，可在外部访问
    int x, y;
    int speed;
    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
private: // 私有成员，仅类内部可访问
    int health;
};

// struct Player {
//     int x, y; // 默认是公有的
//     int speed;
//     void Move(int xa, int ya) {
//         x += xa * speed;
//         y += ya * speed;
//     }
// };


// 来自您的第二张图：一个典型的使用struct表示数据的例子
struct Vec2 { // 表示一个2D向量/坐标点
    float x, y; // 数据是公有的，可以直接访问

    // 一个简单的方法，用于操作自身数据
    void Add(const Vec2& other) {
        x += other.x;
        y += other.y;
    }
};

int main ()
{
    Player player;
    player.x = 2;
    player.y = 3;
    player.speed = 10;
    // player.health = 100; // 错误：health 是私有的，不能在类外部访问
    player.Move(1,1);
    std::cout << "player.x = " << player.x << std::endl;
    std::cout << "player.y = " << player.y << std::endl;

    Vec2 v1 = {1.0f, 2.0f};
    Vec2 v2 = {3.0f, 4.0f};
    v1.Add(v2);
    std::cout << "v1.x = " << v1.x << std::endl;
    std::cout << "v1.y = " << v1.y << std::endl;
    return 0;
}