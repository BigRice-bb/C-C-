#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void test01(char *arr)
{
    char *p = arr;
    if (*p == '\0')
    {
        return;
    }
    test01(p + 1);
    printf("%c ", *p);
}
//斐波那契数列
int fib(int n)
{
    if (n==1 || n==2)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
    
}
int main()
{
    char arr[] = "abcdefghijk";
    test01(arr);
    printf("%d \n",fib(10));
    system("pause");
    return 0;
}
