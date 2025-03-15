#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#pragma pack(show)
//1,第一个属性开始从0开始偏移
//2,第二个属性开始 对齐按当前最大的对齐成员的整数倍
//3,所有属性计算完,再整体做二次偏移,整体需是最大成员的整数倍
//对齐模数比,前面最大的对齐方式 
//内存对齐如何计算
typedef struct _STUDENT1{
    int a;//0-3
    char b;//4-7
    double c;//8-15
    float d;//16-19
}student1;//大小为24
typedef struct _STUDENT2{
    double c;//0-7
    int a;//7-11
    float d;//12-15
    char e;//16
    //填充7字节
}student2;//大小为24

//结构体嵌套结构体,子结构体大小为该结构体的最大数据类型和对齐模数比 的整数倍上
typedef struct _STUDENT3{
    char a;//0-7
    student1 b;//8-31
    double c;//32-39
}student3;//大小为24


void test01()
{
    printf("%d\n",sizeof(student3));//24
}
int main()
{

    test01();
    system("pause");
    return 0;
}