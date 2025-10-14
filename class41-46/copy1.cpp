#include <iostream>
#include <string>

struct Vector2
{
    float x, y;
};

int main()
{
    int a = 10;
    int b = a;
    a = 20;
    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << a << std::endl;
    Vector2 v1 = {2.0f, 3.0f};
    std::cout << "v1: " << v1.x << ", " << v1.y << std::endl;
    Vector2 v2 = v1;
    std::cout << "v2: " << v2.x << ", " << v2.y << std::endl;
    v2.x = 100.0f;
    std::cout << "v1: " << v1.x << ", " << v1.y << std::endl;
    std::cout << "v2: " << v2.x << ", " << v2.y << std::endl;

    // new对象，copy是指针的copy，会改变new对象的指针
    Vector2* v3 = new Vector2(v1);
    Vector2* v4 = v3;
    Vector2 v5 = *v3; // 解引用指针，获取指针指向的对象,这里是值拷贝，不会改变new对象的指针
    std::cout << "v3: " << v3->x << ", " << v3->y << std::endl;
    std::cout << "v4: " << v4->x << ", " << v4->y << std::endl;
    std::cout << "v5: " << v5.x << ", " << v5.y << std::endl;
    v3->x = 200.0f;
    std::cout << "v3: " << v3->x << ", " << v3->y << std::endl;
    std::cout << "v4: " << v4->x << ", " << v4->y << std::endl;
    std::cout << "v5: " << v5.x << ", " << v5.y << std::endl;
    // 释放new对象
    delete v3;
    return 0;
}