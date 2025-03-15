#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_arr(int* arr,int len)//int *arr等价于int arr[]
{
    //数组名传入函数退化为1级指针
    printf("%d\n",sizeof(arr));//输出为8,退化为1级指针
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
void test01()
{
    //一维数组名是不是指针?
    int arr[5]={1,2,3,4,5};
    //1.sizeof 
    printf("%d\n",sizeof(arr));//输出为20,代表不是一个int型指针
    //指针步长为整个数组的长度,数组指针
    //2.对数组名取地址
    printf("%d\n",&arr);//6291072
    printf("%d\n",&arr+1);//6291092,步长为20.没那么简单
    //以上两种情况数组名不是一个int指针
    //int*p=arr;//其余情况数组名都代表指向第一个元素的指针

    //如何打印数组
    int len=sizeof(arr)/sizeof(int);//数组大小如何获取
    print_arr(arr,len);//数组名传入函数退化为1级指针

    //arr数组名  为指针常量--指针的指向不可以修改
    //const int *a  --常量指针  指针指向的值为常量 不可改
    //int * const a --指针常量  指针为常量,不可以修改

    //数组索引可不可以为负数,原数组名不可以为负,但是索引可以为负
    int *p=arr;
    p+=3;
    printf("%d\n",p[-1]);//3  这种情况可以为负

}
int main()
{

    test01();
    system("pause");
    return 0;
}