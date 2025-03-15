#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//二级指针输入特性
//二级指针--指针数组--数组名为二级指针,指向第一个地址元素的地址

void printer(int** p)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*p[i]);
    }
    
}
void test01()
{
    //创建二级指针接收大小为5个一级指针的堆区空间
    int**p=(int**)malloc(sizeof(int*)*5);
    int a1=10,a2=20,a3=30,a4=40,a5=50;
    for (size_t i = 1; i < 6; i++)
    {
        switch(i){
            case 1:p[i-1]=&a1;break;
            case 2:p[i-1]=&a2;break;
            case 3:p[i-1]=&a3;break;
            case 4:p[i-1]=&a4;break;
            case 5:p[i-1]=&a5;break;
            default: break;
        }
    }
    //用函数接收然后打印
    printer(p);
    if(p!=NULL)
    {
        free(p);
        p=NULL;
    }
}

//创建在栈区
void test02()
{
    int*p[5];//指针数组
    //整数开辟在堆区,并赋值
    int*num=(int*)malloc(sizeof(int)*5);
    for (size_t i = 0; i < 5; i++)
    {
        num[i]=10*i;
        p[i]=&num[i];
    }
    printer(p);
    if(num!=NULL)
    {
        free(num);
        num=NULL;
    }   
}
int main()
{

    test02();
    system("pause");
    return 0;
}