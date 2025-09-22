#include <iostream>

int main(){
    int a = 10;
    int b = 20;
    if(a>b){
    // if(1){
        std::cout<<"a大于b"<<std::endl;
    };
    bool  flag = 'b'=='b';
    if(flag){
        std::cout<<"'b'='b'"<<std::endl;
    }
    if (1) std::cout<<"1"<<std::endl;
    // 指针的if
    int* p = &a;
    if(p){
        std::cout<<"p指向的地址不是nullptr"<<std::endl;
    }
    if(*p==11){
        std::cout<<"*p==10"<<std::endl;
    }
    else if (*p==10){
        std::cout<<"*p==10"<<std::endl;
    }
    return 0;
}