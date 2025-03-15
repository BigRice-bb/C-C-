#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const int a=10;//全局变量..直接修改不可以
//常量区的全局变量不可以修改,间接修改也不可以

void test01()
{
    //  int* const p=&a;//不可修改
    // *p=20;
    // printf("%d\n",a);
    const int b=10;//局部常量放在栈区,可以用间接方式修改其值,伪常量
    //int* p=&b;
    //*p=20;
    printf("%d\n",b);
    int cv[b];//现在c语言已经修改了,局部常量也是不可以间接修改的

    //字符串常量是否可以修改
    char* str="aaasadsa";
    str[0]='b';
    printf("%s",str);
}
int main()
{

    test01();
    system("pause");
    return 0;
}