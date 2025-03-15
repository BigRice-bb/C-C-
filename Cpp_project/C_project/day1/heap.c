#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int* getspace()
{
    int*p=(int*)malloc(sizeof(int)*5);//这片内存是连续的空间
    p[0]=10;
    return p;
}

void test01()
{
    int*p=getspace();//堆区内存不会释放,可以正确访问
    printf("%d",p[0]);
    free(p);
    p=NULL;
    printf("%d",p[0]);
}


void allocatespace(char **p)
{
    *p=(char*)malloc(100);
    strcpy(*p,"helloworld");
    printf("%s\n",*p);
}

void test02()
{
    char *str=NULL;
    allocatespace(&str);
    printf("%s\n",str);
}
int main()
{

    test02();
    system("pause");
    return 0;
}