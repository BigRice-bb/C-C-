#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE *fp;

    //相对路径打开文件，文件会创建在当前文件夹下

    fp = fopen("test.txt","w+");
    //fp = fopen("../test.txt","w+");//上一级目录下
    //fp = fopen("C:/Users/Burger/Documents/CODEING/Cpp_project/C_project/c_file/test.txt","w+");
    //权限为打开文件，如果文件不存在则创建，如果文件存在则清空文件内容
    if(fp == NULL)
    {
        perror("Error opening file");//打印Error opening file：xxx具体错误信息
    }
    else
    {
        printf("File opened successfully\n");
        fclose(fp);
    }
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}