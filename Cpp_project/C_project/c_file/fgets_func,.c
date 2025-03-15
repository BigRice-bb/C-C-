#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE * fp=fopen("test.txt","r");//打开文件,只读权限
    if (fp==NULL)
    {
        perror("Error opening file");//打印Error信息
        return -1;
    }
    char buf[16];
    //fgets(buf,16,fp);//读取一行数据
    printf("读取的字符串为:%s\n",fgets(buf,16,fp));
    fclose(fp);//关闭文件

    //也可以从系统标准输入文件中获取字符串
    printf("你输入的字符串为：%s\n",fgets(buf,16,stdin));
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}