#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *myfunc()
{
    int a=10;
    return &a;
}

void test01()
{
    //a为函数的局部变量,在函数运行结束后就会被释放,
    //这时候没有权限操控这个地址,这个地址也是无意义的
    int*a=myfunc();
    printf("%d\n",*a);
    printf("%d\n",*a);
}
int main()
{

    test01();
    system("pause");
    return 0;
}