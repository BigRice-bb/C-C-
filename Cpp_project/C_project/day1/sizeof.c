#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    int b;
    printf("%d\n",sizeof b);
    char a[]={"abcdef"};//包含终止符\0,所以总大小为7
    printf("%d\n",sizeof(a));
}
int main()
{

    test01();
    system("pause");
    return 0;
}