//练习，读取用户输入的所有字符到指定文件中，直到：wq结束
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    // char buf[10];//若写入8个字符，会读入换行\n,
    // //若写入多余8个，最后的换行符\n就会被舍弃，最后以为必然为\0
    // fgets(buf,10,stdin);
    // fputs(buf,stdout);
    FILE* fp=fopen("test.txt","w+");//打开文件-清空＋读写
    if (fp==NULL)
    {
        perror("Error opening file");//打印Error信息
        return -1;
    }
    char buf[128];//暂时的缓存，用于暂存用户输入的一行字符串
    while(1)
    {
        //利用fgets函数从标准输入中读取一行字符串
        fgets(buf,128,stdin);
        //判断用户输入的字符串是否为"wq\n"
        if(strcmp(buf,":wq\n")==0)
        {
            break;
        }
        //将读入的字符串写入文件中
        fputs(buf,fp);
        //清空buf
        memset(buf,0,128);  
    }
    fclose(fp);//关闭文件
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}