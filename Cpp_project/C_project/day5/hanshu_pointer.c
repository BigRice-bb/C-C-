#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void func(int a)
{
    printf("a=%d\n",a);
}
void test01()
{
    //如何定义函数指针
    //1.先定义函数类型,再通过类型定义函数指针
    typedef void(FUNC)(int);//创建函数类型
    //类比创建数组类型 typedef int (ARRAY)[5];ARRAY代表一个数组类型
    FUNC*p=func;
    p(1);

    //2.定义出函数指针类型
    typedef void(*FUNC2)(int);
    FUNC2 p2=func;
    p2(2);

    //3.直接定义函数指针变量
    //void (*p3)(int)=func;
    void (*p3)(int)=func;
    p3(3);

    //区分函数指针和指针函数
    //函数指针:指向函数的指针
    //指针函数:返回值是指针的函数
}
//函数指针的数组
void func1()
{
    printf("func1 \n");
}
void func2()
{
    printf("func2 \n");
}
void func3()
{
    printf("func3 \n");
}
void test02()
{
    //定义一个函数指针数组
    // typedef void(*FUNC)();
    // FUNC arr[3]={func1,func2,func3};
    // typedef void(FUNC)();
    // FUNC* arr[3]={func1,func2,func3}; 
    void (*arr[3])()={func1,func2,func3};//直接定义
    for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        arr[i]();
    }
    
}
int main()
{

    test02();
    system("pause");
    return 0;
}