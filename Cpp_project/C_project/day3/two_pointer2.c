#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//二级指针输出特性

void allocatespace(int** p)
{
    int *temp=(int*)malloc(sizeof(int)*10);
    for (size_t i = 0; i < 10; i++)
    {
        temp[i]=100+i;
    }
    *p=temp;
}
void printer(int **p)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",(*p)[i]);
    }
    
}

void spacefree(int **p)
{
    if ((*p)!=NULL)
    {
        free(*p);
        *p=NULL;
    }
}
void test01()
{
    int *p=NULL;//创建一个指针接收函数内部返回的地址空间地址
    allocatespace(&p);//p为二级指针
    printer(&p);
    // if ((p)!=NULL)
    // {
    //     free(p);
    //     p=NULL;
    // }
    spacefree(&p); 
}

int main()
{

    test01();
    system("pause");
    return 0;
}