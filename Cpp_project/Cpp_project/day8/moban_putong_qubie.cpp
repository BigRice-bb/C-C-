//模版和普通函数的区别
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<typename T>
T my_add(T a,T b)
{
    return a+b;
}
int my_add2(int a,int b)
{
    return a+b;
}

void test01()
{
    int a=10;
    int b=20;
    char c='c';
    cout<<my_add(a,b)<<endl;//模版函数调用
    cout<<my_add2(a,b)<<endl;//普通函数调用
    //cout<<my_add(a,c)<<endl;//模版函数不会进行隐式类型转换
    cout<<my_add<int>(a,c)<<endl;//模版函数调用指明数据类型
    cout<<my_add2(a,c)<<endl;//普通函数会进行隐式类型转换
}

//2.模版和普通函数的调用规则
template<typename T>
void myfunc(T a)
{
    cout<<"模版函数调用"<<endl;
}       
//模版函数也可以进行重载
template<typename T>
void myfunc(T a,T b)
{
    cout<<"模版函数重载调用"<<endl;
}                                                    
void myfunc(int a)
{
    cout<<"普通函数调用"<<endl;
}
void test02()
{
    int a=10;
    myfunc(a);//普通函数调用,当模版函数和普通函数都可以调用时，优先调用普通函数
    myfunc<>(a);//模版函数调用
    myfunc<int>(a);//模版函数调用
    myfunc(a,a);//模版函数重载调用

    char c='c'; 
    myfunc(c);//会调用模版函数，当模版函数更加匹配数据类型时优先调用模版函数
}
int main()
{
    //test01();
    test02();
    return EXIT_SUCCESS;
}