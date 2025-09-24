#include<iostream>

//int s_Var = 0;
// extern int s_Var;

struct Entity{
    // int x, y;
    static int x, y;
    // void print() {
    //     std::cout << "x = " << x << ", y = " << y << std::endl;
    // }
    static void print() {
        std::cout << "x = " << x << ", y = " << y << std::endl;
    }
};
//- 在结构体 Entity 中， static int x, y; 只是 声明 了静态成员变量，告诉编译器这些变量的存在和类型，但并没有为它们分配实际内存空间。
// 内存分配需求 ：静态成员变量不属于任何对象实例，而是属于整个类。为了实际创建这些变量并分配内存，必须在类的外部进行 定义 。
int Entity::x;
int Entity::y;

// static void print(Entity& e) {
//     std::cout << "x = " << e.x << ", y = " << e.y << std::endl;
// }

int main()
{

    Entity e;
    e.x = 2;
    e.y = 3;
    e.print();
    Entity e2;
    e2.x = 10;  
    e2.y = 20;
    e2.print();
    // 静态成员变量可以通过类名直接访问，也可以通过对象访问，但最好通过类名访问，
    // 因为对象访问可能会导致歧义，尤其是在存在继承关系时。
    Entity::x = 100;
    Entity::y = 200;
    Entity::print();
    e.print();
    // e2.print();
    // std::cout << "s_Var = " << s_Var << std::endl;
}
