//指针的步长
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

//1.指针的步长代表+1的跳数
//2.指针解引用读出的字节数
void test01()
{
    char buf[100];
    int a=1000;
    memcpy(buf,&a,4);//将a的值拷贝到buf中
    printf("%d\n",*(int*)buf);//即可读出1000
}

//指针步长练习
struct person{
    char a;
    int b;
    char buf[64];
    int d;
};
void test02()
{
    struct person p1={'a',10,"hello world",20};
    //offsetof函数,可以返回某个数据在结构体中的偏移量
    printf("d的偏移量为:%d \n ",offsetof(struct person,d));
    printf("%d\n",*((int*)((char*)&p1+72)));
    //要求通过指针偏移输出20
    printf("%d\n",*(int*)((char*)((int*)&p1+2)+64));
}

int main()
{

    test02();
    system("pause");
    return 0;
}