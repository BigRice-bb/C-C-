#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int str_reserch(char* str,char* buf)
{
    char *str1=str;
    char *buf1=buf;
    for (int  i = 0; i < strlen(str); i++)
    {
        if (str[i]==buf[0])
        {
            for (int j = 1; j < strlen(buf); j++)
            {
                if(str[i+j]!=buf[j])
                {
                    break;
                }
                else if(j==strlen(buf)-1 && str[i+j]==buf[j])
                {
                    return i;
                }
            }          
        }
    }
    return -1;
    
}
void test01()
{
    char str[]="asjdfgashOBasdas";
    char buf[]="jd";
    int a = str_reserch(str,buf);
    printf("%d\n",a);
}
int main()
{
    test01();
    system("pause");
    return 0;
}