#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct person
{
    char a;
    int b;
    char c;
    int d;
}person;//字节对齐 4字节的跳

void test01()
{
    person p1={'a',10,'c',20};//通过指针偏移修改p1.d的值
    char* p=(char*) &p1;//先进行强转
    *((int*)(p+12))=40;//再转回来
    printf("%d\n",p1.d);
}
int main()
{

    test01();
    system("pause");
    return 0;
}