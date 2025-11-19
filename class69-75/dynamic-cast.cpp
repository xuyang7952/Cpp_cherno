#include <iostream>
#include <typeinfo>

// 基类必须有虚函数（启用多态）
class Entity {
public:
    virtual ~Entity() = default; // 虚析构函数（推荐）
    virtual void Print() { std::cout << "Entity\n"; }
};

class Player : public Entity {
public:
    void Attack() { std::cout << "Player attacks!\n"; }
};

class Enemy : public Entity {
public:
    void Defend() { std::cout << "Enemy defends!\n"; }
};

int main() {
    // 情况1：实际是 Player
    Entity* e1 = new Player();
    
    Player* p1 = dynamic_cast<Player*>(e1);
    if (p1) {
        p1->Attack(); // 安全调用
    }

    // 情况2：实际是 Enemy，尝试转为 Player → 失败
    Entity* e2 = new Enemy();
    
    Player* p2 = dynamic_cast<Player*>(e2);
    if (!p2) {
        std::cout << "Cast failed: e2 is not a Player!\n";
    }

    // 情况3：引用转换（失败会抛异常）
    try {
        Player& p_ref = dynamic_cast<Player&>(*e2);
        p_ref.Attack();
    } catch (const std::bad_cast& e) {
        std::cout << "Bad cast caught: " << e.what() << "\n";
    }

    delete e1;
    delete e2;
    return 0;
}