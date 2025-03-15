//文件操作练习-文件中有若干行为解答的数学题，
//读出，解答，再将答案写入文件
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    FILE *fp;
    char buf[256]={0};//创建数组，接收每行内容
    char out[256]={0};//创建数组，接收每行内容,完成循环拼接，最后输出
    char sum[256] = {0};//创建数组，用于输出的拼接并初始化为空字符串
    int num1, num2, result;//接收三个数
    char ch;//接收运算符
    fp = fopen("math.txt", "r+");//打开文件
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while(1)
    {
        if(fgets(buf, sizeof(buf), fp) == NULL)//读取一行内容
        {
            break;
        }
        sscanf(buf,"%d%c%d=\n", &num1, &ch, &num2);//解析内容
        switch(ch)
        {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                printf("error\n");
                break;
        }
        sprintf(out, "%d%c%d=%d\n", num1, ch, num2, result);//拼接内容
        //printf("%s", out);//输出内容
        strcat(sum, out);//拼接字符串
    }
    //fputs(sum, fp);//写入内容
    fclose(fp);
    fp=fopen("math.txt", "w+");//打开文件
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fputs(sum, fp);//写入内容
    fclose(fp);
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}