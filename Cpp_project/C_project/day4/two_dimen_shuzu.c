#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    //3种方式--创建一个二维数组,本质是一个连续的线性空间
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    int arr1[3][3]={1,2,3,4,5,6,7,8,9};
    int arr2[][3]={1,2,3,4,5,6,7,8,9};//行可省,自动识别
    //二维数组名的含义
    printf("%d\n",sizeof(arr));//36,整个空间的大小
    //两种情况,二维数组名不代表数组指针
    //1,sizeof
    //2,对数组名取地址,步长为整个数组大小
    int (*p)[3]=arr;//一般二维数组名代表一维数组指针
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d ",(*(p+i))[j]);
            if (j==2)
            {
                printf("\n");
            }        
        }    
    }
}
void test02()
{
    int arr1[3][3]={1,2,3,4,5,6,7,8,9};
    //二维数组指针
    //1.typedef int(*PARR_TYPE)[3][3];
    //PARR_TYPE parr=&arr1;
    //2.直接定义数组指针
    int (*parr)[3][3]=&arr1;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d ",(*parr)[i][j]);
            if (j==2)
            {
                printf("\n");
            }        
        }    
    }
}
//二维数组做函数参数如何传递
//void printer(int(*p)[3],int hang)
void printer(int p[][3],int hang)//等价 
{
    for (size_t i = 0; i < hang; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d ",p[i][j]);
        }
    }
    
}
void test03()
{
    int arr1[3][3]={1,2,3,4,5,6,7,8,9};
    printer(arr1,3);
}
int main()
{

    test03();
    system("pause");
    return 0;
}