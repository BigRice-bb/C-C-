#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct person{
    char * name;
    int age;
};
struct person ** space_allo(int len)
{
    //给二级指针分配内存
    struct person **per=(struct person **)\
    malloc(sizeof(struct person*)*len);
    //给一级指针分配内存
    for (size_t i = 0; i < len; i++)
    {
        per[i]=(struct person *)\
        malloc(sizeof(struct person));
        per[i]->name=(char*)malloc(16);
        per[i]->age=20+i;
        sprintf(per[i]->name,"name_%d",i);
    }
    return per;
}
void show(struct person **per,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%s  %d\n",per[i]->name,per[i]->age);
    }
}
void free_space(struct person **per,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        free(per[i]->name);
        free(per[i]);
    }
    free(per);
}
void test02()
{
    struct person **per=NULL;
    per=space_allo(3);
    show(per,3);
    free_space(per,3);
}
void test01()
{
    //创建结构体数组  内存分配在堆区
    struct person **per=(struct person **)\
    malloc(sizeof(struct person*)*3);
    //接下来创建3个结构体
    struct person p1;
    per[0]=&p1;
    p1.name=(char*)malloc(16);
    p1.age=11;
    strcpy(p1.name,"wangb");
    struct person p2;
    per[1]=&p2;
    p2.name=(char*)malloc(16);
    p2.age=11;
    strcpy(p2.name,"wangb");
    struct person p3;
    per[2]=&p3;
    p3.name=(char*)malloc(16);
    p3.age=11;
    strcpy(p3.name,"wangb");
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s  %d\n",(*per[i]).name,(*per[i]).age);
    }
    for (size_t i = 0; i < 3; i++)
    {
        free(per[i]->name);
    }
    free(per);
    

}
int main()
{

    test02();
    system("pause");
    return 0;
}