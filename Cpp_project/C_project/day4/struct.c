#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//创建结构体的几种方式
//1
struct person{
    char name[10];
    int age;
};
//2
typedef struct person2{
    char name[10];
    int age;
}person_t;
//3
struct person3{
    char name[10];
    int age;
}p3;
//4
struct person4{
    char name[10];
    int age;
}p4={"wangbo",18};
//5  匿名结构体  一次性的
struct {
    char name[10];
    int age;
}p5={"wangbo",18};

void test01()
{
    struct person p1;//1
    person_t p2;//2
    p3.age=10;//3:定义时就创建
    printf("name: %s age:  %d",p4.name,p4.age);//4:定义时就赋值
}
//创建结构体
void test02()
{
    //分配在栈区
    struct person p1;
    //分配在堆区
    struct person *p=(struct person *)malloc(sizeof(struct person));
    strcpy(p->name,"wangbo");
    p->age=12;
    printf("%s  %d",p->name,p->age);
    if (p!=NULL)
    {
        free(p);
        p=NULL;
    }
}
//结构体变量数组的创建
void test03()
{
    //再栈上分配内存
    struct person p1[]={
        {"wangbo",18},
        {"wangbo2",28},
        {"wangbo3",38}
    };
    //堆区创建内存
    struct person *p=(struct person *)malloc(sizeof(struct person)*4);
    strcpy(p->name,"wangbo");
    p->age=18;
    strcpy((p+1)->name,"wangbo2");
    (p+1)->age=28;
    strcpy((p+2)->name,"wangbo3");
    (p+2)->age=38;
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s %d  ",(p+i)->name,(p+i)->age);
    }
    if (p!=NULL)
    {
        free(p);
        p=NULL;
    }
    
}
int main()
{

    test03();
    system("pause");
    return 0;
}