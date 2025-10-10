#include <iostream>
#include <string>

// 前向声明
class Entity;
void PrintEntity(Entity* e);

class Entity {
public:
    int x, y;
    std::string name;
    
    // 构造函数：解决命名冲突 + 传递this指针
    Entity(int x, int y, const std::string& name) {
        this->x = x;      // 解决参数名冲突
        this->y = y;      // 明确指定成员变量
        this->name = name;
        
        std::cout << "构造函数中: ";
        PrintEntity(this);  // 传递当前对象指针
    }
    
    // const成员函数：演示const正确的this
    int GetX() const {
        // this->x = 5;  // ❌ 错误：const函数中不能修改成员
        
        const Entity* e = this;  // ✅ 正确：this在const函数中是const指针
        std::cout << "GetX()中: x = " << this->x << std::endl;
        
        return this->x;  // ✅ 允许读取操作
    }
    
    // 非const成员函数：可以修改对象
    void SetX(int newX) {
        this->x = newX;  // ✅ 允许修改
        std::cout << "SetX()后: ";
        PrintEntity(this);
    }
    
    // 返回this支持链式调用
    Entity& AddX(int value) {
        this->x += value;
        // `this` 是指向当前对象的指针，`*this` 是对该指针解引用，得到的是当前对象本身。
        // 函数返回类型为 `Entity&`，即返回一个引用，所以可以直接返回 `*this` 来返回当前对象的引用。
        // 而 `Entity& = this` 语法错误，`this` 是指针，不能直接赋值给引用类型，需要解引用。
        // return *this;  // ✅ 返回当前对象引用，支持链式调用
        Entity &ref = *this;
        return ref;  // ✅ 返回当前对象引用，支持链式调用
    }
    
    // 返回this支持链式调用
    Entity& AddY(int value) {
        this->y += value;
        // `this` 是指向当前对象的指针，`*this` 是对该指针解引用，得到的是当前对象本身。
        // 函数返回类型为 `Entity&`，即返回一个引用，所以可以直接返回 `*this` 来返回当前对象的引用。
        // 返回时会自动将对象转换为对象的引用。
        return *this;  // ✅ 返回当前对象引用，支持链式调用
    }
};

// 打印实体信息的函数
void PrintEntity(Entity* e) {
    if (e) {
        std::cout << "Entity: " << e->name 
                  << "(" << e->x << ", " << e->y << ")" << std::endl;
    }
}

int main() {
    std::cout << "=== C++ this关键字演示 ===" << std::endl;
    
    // 1. 创建对象（自动调用构造函数）
    Entity entity(10, 20, "TestEntity");
    
    // 2. 调用const成员函数
    int x = entity.GetX();
    
    // 3. 调用非const成员函数
    entity.SetX(30);
    
    // 4. 链式调用演示
    entity.AddX(5).AddY(10);  // 流畅接口
    PrintEntity(&entity);
    
    std::cout << "=== 演示完成 ===" << std::endl;
    return 0;
}