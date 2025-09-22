// 引用
#include <iostream>
using namespace std;

// 值传递
void increment(int a)
{
    a++;
}
// 指针传递
void increment_ptr(int* a)
{
    // (*a)++; // 先解引用，再++
    cout << "*a++ = " << *a << endl;
    *a++; // 这么写，会有啥问题？，a
    cout << "*a++ = " << *a << endl;
}
// 引用传递
void increment_ref(int& a)
{
    a++;
}


int main()
{
    int a = 10;
    int b = 20;
    // int& ref; 会报错,声明后，必须赋值引用
    int& ref = a; // ref 是 a 的引用
    ref = 20; // 这也会改变 a 的值
    cout << "a = " << a << endl;
    cout << "ref = " << ref << endl;
    // 值传递
    increment(a);
    cout << "a = " << a << endl;
    // 指针传递
    increment_ptr(&a);
    cout << "a = " << a << endl;
    // 引用传递，更简单
    increment_ref(a);
    cout << "a = " << a << endl;

    // 引用，就是别名，和指针类似，但是更安全，不能指向 NULL，也不能改变指向，只能指向一个变量；可以使用指针实现类似功能； 
    int c = 30;
    int d = 40;
    int* ref2 = &c; // ref 是 c 的指针
    *ref2 =2; // 这也会改变 c 的值
    ref2 = &d; // ref 现在指向 d
    *ref2 = 1; // 这也会改变 d 的值
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "*ref2 = " << *ref2 << endl;  

    return 0;
}
