#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01()
{
    int num=2;//int 4字节 
    //2=0000 0000 0000 0000 0000 0000 0000 0010;
    //取反%x 输出是1111 1111 1111 1111 1111 1111 1111 1101
    //负数的补码为符号位不动 其余为取反加一 
    //1000 0000 0000 0000 0000 0000 0000 0011=-3 
    printf("%d\n",~num);
}
void test02()
{
    int num=5;//0000 0101
    //让其第6位为1
    num|=64;//01000000;
    //结果为0100 0101=0x45
    printf("%x",num);
}
//异或实现两个数交换
void test03()
{
    int num1=5;
    int num2=7;
    num1=num1^num2;
    num2=num1^num2;//=num1
    num1=num1^num2;//=num2
    printf("%d %d",num1,num2);
}
void test04()
{
    signed int num1=0x83;//1000 0011
    num1>>=2;//0010 0000
    printf("%x\n",num1);
}
int main()
{

    test04();
    system("pause");
    return 0;
}