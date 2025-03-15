#define _CRT_SECURE_NO_WARNINGS//减掉传统函数的一些不安全警告
#include <stdio.h>//标准输入输出  printf scanf
#include <stdlib.h>//标准库 malloc free
#include <string.h>//包含字符串处理函数
#include <math.h>

typedef struct person {
    char* name;
    int age;
}person;

void test01()
{
    person p1;//typedef可以免去c语言的struct
}

int main()
{
    
    char buf[1024];
    strcpy(buf,"hello world");
    printf("%s\n",buf);
    system("pause");//调用系统函数,pause阻塞
    return 0;
}