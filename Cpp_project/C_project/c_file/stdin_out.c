#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    fclose(stdout);//关闭标准输出流，则printf无法输出
    printf("Hello_World\n");//可以正常输出
    system("pause");//调用系统命令暂停pause，让用户按任意键继续
    return EXIT_SUCCESS;//标准库宏，程序正常退出，一般为0
}