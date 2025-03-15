#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1024  //常规宏定义
//宏函数
//1.宏函数需要加小括号,保证运算结果
//宏的本质是展开替换,不加括号展开后优先级会有变化
//2.通常会将比较短小的函数封装成宏函数
//3.宏函数比普通函数效率高,省去了普通函数入栈和出栈的时间
//用空间换时间
#define MYADD(x,y) ((x)+(y))  


void test01()
{
    int a=MYADD(10,20);
    printf("%d\n",a);
}
int main()
{

    test01();
    system("pause");
    return 0;
}