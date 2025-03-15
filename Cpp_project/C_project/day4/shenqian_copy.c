#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct person{
    char *name;
    int age;
};//+赋值是深还是浅,关键在于里面是指针char*  还是数组char []
//指针就会赋值地址过去,共享内存,数组就会创建副本,相互独立
void test01()
{
    struct person p1;
    struct person p2;
    p1.age=19;
    strcpy(p1.name,"pengz");
    p2=p1;
    printf("p1 %s %d  p2 %s %d",p1.name,p1.age,p2.name,p2.age);
    //直接等号赋值是深拷贝吗?   看内部是指针还是数组
    //修改p2的name  看看p1会不会变
    //p2.name="wnagb";字符串是一个指针,不可以直接赋值
    strcpy(p2.name,"wangb");
    printf("p1 %s %d  p2 %s %d",p1.name,p1.age,p2.name,p2.age);
}
//1.浅拷贝的重复释放问题
void test02()
{
    struct person p1;
    struct person p2;
    p1.age=19;
    p1.name=(char* )malloc(64);//p1在堆区开辟空间,name存放的堆区的入口地址
    strcpy(p1.name,"pengz");
    p2.age=10;
    p2.name=(char* )malloc(64);//p2在堆区开辟空间,name存放的堆区的入口地址
    strcpy(p2.name,"wangb");
    p2=p1;//浅拷贝操作会把p1的堆区入口地址复制给p2,p1p2共享同一片堆区
    printf("p1 %s %d  p2 %s %d\n",p1.name,p1.age,p2.name,p2.age);
    //释放内存
    free(p1.name);
    //free(p2.name);//对内存进行了重复的释放,且p2的内存造成泄漏未释放
}
//2.深拷贝
void test03()
{
    struct person p1;
    struct person p2;
    p1.age=19;
    p1.name=(char* )malloc(64);//p1在堆区开辟空间,name存放的堆区的入口地址
    strcpy(p1.name,"pengz");
    p2.age=10;
    p2.name=(char* )malloc(64);//p2在堆区开辟空间,name存放的堆区的入口地址
    strcpy(p2.name,"wangb");
    p2.name=p1.name;
    strcpy(p2.name,p1.name);
    printf("p1 %s %d  p2 %s %d\n",p1.name,p1.age,p2.name,p2.age);
    //释放内存
    free(p1.name);
    free(p2.name);//不会对内存进行重复的释放
}
int main()
{

    test02();
    system("pause");
    return 0;
}