#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    int *p=(int*)calloc(10,sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",p[i]);//calloc会对内存进行初始化为0
    }

    if(p!=NULL)
    {
        free(p);//其余和malloc相同
        p=NULL;
    }
    
}
void test02()
{
    int *p=(int*)calloc(10,sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        p[i]=i+100;
        //printf("%d\n",p[i]);//calloc会对内存进行初始化为0
    }
    printf("%d\n",p);
    int *p1=(int*)realloc(p,sizeof(int)*20);
    printf("%d\n",p1);//查看realloc的分配机制
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n",p1[i]);
    }
    //realloc不会将新扩的内存初始化为0
    //接下来缩小空间
    int *p2=(int*)realloc(p1,sizeof(int)*5);
    printf("%d\n",p2);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",p2[i]);
    }
    if(p!=NULL)
    {
        free(p);//其余和malloc相同
        p=NULL;
    }  
}
int main()
{

    test02();
    system("pause");
    return 0;
}
