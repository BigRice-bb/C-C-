#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    //1.格式化字符串
    char buf[1024]={0};
    sprintf(buf,"aaa%sccc","bbb");
    puts(buf);
    //2.拼接字符串
    memset(buf,0,1024);
    char str1[]="aaa";
    char str2[]="bbb";
    char str3[]="ccc";
    sprintf(buf,"%s%s%s",str1,str2,str3);
    puts(buf);
    

}
int main()
{

    test01();
    system("pause");
    return 0;
}