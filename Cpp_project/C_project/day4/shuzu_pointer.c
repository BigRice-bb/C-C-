#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//数组指针的定义方式
//1.先定义数组类型,再通过类型定义数组指针
void test01()
{
    int arr[5]={1,2,3,4,5};
    //typedef int(ARRAY_TYPE)[5];//重命名int[5]为ARRAY_type
    typedef int ARRAY_TYPE[5];//等价形式
    // ARRAY_TYPE* p=&arr;
    // printf("%d\n",sizeof(p));
    ARRAY_TYPE arr1;
    printf("%d\n",sizeof(arr1));//20
    for (size_t i = 0; i < 5; i++)
    {
        arr1[i]=i+1;
    }
    ARRAY_TYPE *parr=&arr1;//指向一个数组的指针
    //*parr=arr1数组名
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ",(*parr)[i]);//要加小括号,[]优先级高
    }
}
void test02()
{
    //2.直接定义数组指针类型typedef int (*ARRP_TYPE)[5];
    int arr[5]={1,2,3,4,5};
    //int (*arrp)[5]=&arr;//数组指针定义方式,指向一个大小为5的数组的指针
    typedef int (*ARRP_TYPE)[5];//定义数组指针数据类型
    ARRP_TYPE arrp=&arr;
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ",(*arrp)[i]);//要加小括号,[]优先级高
    }
}
//3.直接创建数组指针 int (*arrp)[5]=&arr;
//注:指针数组定义 int * arr[5];里面可以存5个指针 
int main()
{

    test02();
    system("pause");
    return 0;
}
