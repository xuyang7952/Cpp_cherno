// 枚举类型
#include <iostream>
using namespace std;

enum class Color
{
    RED=0,
    GREEN,
    BLUE
};

int main()
{
    Color c = Color::RED;
    if (c == Color::RED)
    {
        cout << "RED" << endl;
        cout << (int)c << endl;
    }
    // if (int(c) == 0)
    if ((int)c == 0)
    {
        cout << "GREEN" << endl;
    }
    return 0;
}
