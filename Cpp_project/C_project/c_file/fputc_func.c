//fputc函数的使用 写入一个字符到文件中
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    //利用相对路径在当前目录打开或新建文件
    FILE *fp;
    fp = fopen("test.txt","w+");
    if(fp == NULL)
    {
        perror("Error opening file");//打印Error信息
        return -1;
    }
    int ret=fputc('A',fp);//写入一个字符到文件中
    printf("写入字符的ascii码为:%d",ret);
    //写入成功
    fclose(fp);//关闭文件

    //再次打开文件，写入26个英文字符
    fp = fopen("test.txt","a+");//设置为追加模式
    if(fp == NULL)
    {
        perror("Error opening file");//打印Error信息
        return -1;
    }
    for(int i=1;i<26;i++)
    {
        fputc('A'+i,fp);//写入26个英文字符
    }
    fclose(fp);//关闭文件
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}