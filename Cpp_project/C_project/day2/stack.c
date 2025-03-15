#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    int a=10;//先入栈--栈低
    int b=20;//后入栈--比上面的高
    printf("栈低地址为: %d",&a);//5ffe9c
    printf("栈顶地址为: %d",&b);//5ffe98
    //所以a先入栈为高地址,b后入栈为低地址
    
}
void test02()
{
    int a=0x11223344;
    char* c=(char*)&a;
    printf("%x",*c);
    printf("%x",*(c+1));
}
int main()
{

    test02();
    system("pause");
    return 0;
}