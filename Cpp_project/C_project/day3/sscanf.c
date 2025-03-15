#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    char str[]="12345def";
    char buf1[128];
    char buf2[128];
    //sscanf(str,"%s%*d%s",buf1,buf2);%s不会碰到数字就停止
    sscanf(str,"%*d%s",buf1);
    printf("%s\n",buf1);
}
void test02()
{
    char str[]="abc12345def";
    char buf1[128];
    char buf2[128];
    char buf[256];
    sscanf(str,"%[a-z]%*d%s",buf1,buf2);//%s不会碰到数字就停止
    sprintf(buf,"%s%s",buf1,buf2);
    printf("%s\n",buf);
}
void test03()
{
    char str[]="abc12345def";
    char buf[256];
    char buf1[256];
    char buf2[256];
    sscanf(str,"%3s%*d%s",buf1,buf2);//%3s指定读三位
    sprintf(buf,"%s%s",buf1,buf2);
    printf("%s\n",buf);
}
void test04()
{
    char str[]="abc12345def";
    char buf[256];
    sscanf(str,"%[a-cd-f]",buf);//%3s指定读三位
    printf("%s\n",buf);
}
void test05()
{
    char str[]="abc12345def";
    char buf[256];
    sscanf(str,"%[^1-9]",buf);//%3s指定读三位
    printf("%s\n",buf);
}

//练习1:将ip地址:127.0.0.1每个段拿出来,分别存储在4个整型变量中
void test06()
{
    char str[]="127.0.0.1";
    int num1;
    int num2;
    int num3;
    int num4;
    sscanf(str,"%d.%d.%d.%d",&num1,&num2,&num3,&num4);
    printf("%d %d %d %d\n",num1,num2,num3,num4);
}

//练习2:提取字符串中的有效字符"asd#wangbo$asdfas123"只提取#$之间的数
void test07()
{
    char str[]="abd12#wangbo$asdas323";
    char buf[128];
    //sscanf(str,"%*[a-zA-Z0-9]#%[^$]",buf);
    sscanf(str,"%*[^#]#%[^$]",buf);
    printf("%s\n",buf);
}
int main()
{

    test07();
    system("pause");
    return 0;
}