#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



//提供一个函数,可以打印任意类型的函数
//用户提供数据和打印函数的接口
void print_txt(void *data,void(*myprint)(void *))
{
    myprint(data);
}
//用户提供
void myprint_int(void *data)
{
    int *p=(int*)data;
    printf("整型数据为:%d\n",*p);
}

struct person
{
    char name[64];
    int age;
};
void myprint_person(void *data)
{
    struct person* p=(struct person*)data;
    printf("姓名:%s,年龄:%d\n",p->name,p->age);
}

void test01()
{
    int a=10;
    print_txt(&a,myprint_int);
    struct person p={"张三",18};
    print_txt(&p,myprint_person);
}
int main()
{

    test01();
    system("pause");
    return 0;
}