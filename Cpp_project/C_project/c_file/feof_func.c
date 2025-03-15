#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE * fp;
    fp=fopen("test.txt","w+");//打开文件-清空＋读写
    fputc('A',fp);//写入一个字符到文件中
    fputc('B',fp);//写入一个字符到文件中
    fputc(-1,fp);//写入一个字符到文件中
    fputc('C',fp);//写入一个字符到文件中
    fputc('D',fp);//写入一个字符到文件中
    fclose(fp);//关闭文件
    fp=fopen("test.txt","r+");//打开文件-读写
    while(1)
    {
        if(feof(fp))//判断文件是否结束
        {
            break;
        }
        int ret=fgetc(fp);//读取一个字符，文件指针自动加一
        printf("读取的字符为:%c\n",ret);
    }

    fclose(fp);//关闭文件
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}