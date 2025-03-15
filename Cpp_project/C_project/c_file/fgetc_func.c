
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE * fp;
    fp=fopen("test.txt","r+");//打开文件
    if (fp==NULL)
    {
        perror("Error opening file");//打印Error信息
        return -1;
    }
    int ret=fgetc(fp);//读取一个字符，文件指针自动加一
    printf("读取的字符为:%c\n",ret);
    ret=fgetc(fp);//读取下一个字符
    printf("读取的字符为:%c\n",ret);
    while( ret != EOF)//EOF为文件结束标志
    {
        ret=fgetc(fp);//读取下一个字符
        if (ret != EOF) {
            printf("读取的字符为:%c\n",ret);
        }
    }
    // ret=fgetc(fp);//读取下一个字符
    // printf("读取的字符为:%c\n",ret);
    fclose(fp);//关闭文件
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}