#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//一些特殊的宏
//__FILE__ 宏所在文件的文件名
//__LINE__ 宏所在文件的行号
//__DATE__ 宏被编译时的日期
//__TIME__ 宏被编译时的时间
//__STDC__ 如果编译器遵循ANSI C标准，它的值为1
//__cplusplus 如果编译器是C++编译器，它的值为1
//__STDC_VERSION__ 当前使用的C标准的版本号


void test01()
{
    printf("文件名：%s\n", __FILE__);
    printf("行号：%d\n", __LINE__);
    printf("编译日期：%s\n", __DATE__);
    printf("编译时间：%s\n", __TIME__);
    printf("ANSI C标准：%d\n", __STDC__);
    //printf("C++编译器：%d\n", __cplusplus);
}
//#define DEBUG
#ifdef DEBUG
void func()
{
    printf("debug版本\n");
}
#else
void func()
{
    printf("release版本\n");
}
#endif


int main()
{

    test01();
    func();
    system("pause");
    return 0;
}