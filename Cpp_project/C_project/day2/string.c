#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void test01()
{
    //char str[]={'a','b','c','d'};//若不加结尾标志
    char str[]={'a','b','c','d',0};//加0或\0,则代表这是一个字符串
    printf("%s\n",str);//abcd后输出乱码

    //对于已经给定数组大小的,未初始化部分默认初始化为0
    char str1[9]={'a','b','c','d'};
    printf("%s\n",str1);

    //若以字符串形式初始化,编译器会自动在结尾补上\0
    char str2[]="abcd";
    printf("%s\n",str2);
    printf("%d\n",sizeof(str2));//5,sizeof会包含\0
    printf("%d\n",strlen(str2));//4strlen不包含\0

    //若指定数组长度,sizeof就会随之改变,strlen不会变
    char str3[100]="abcd";
    printf("%s\n",str3);
    printf("%d\n",sizeof(str3));//100,sizeof代表数组大小
    printf("%d\n",strlen(str3));//4 strlen不包含\0

    //若字符串中包含\0呢,字符串会提前结束,\0就是结束标志
    char str4[]="ab\0cd";
    printf("%s\n",str4);
    printf("%d\n",sizeof(str4));//6,sizeof代表数组大小,后面好有个\0
    printf("%d\n",strlen(str4));//2 strlen不包含\0

    //若字符串中包含\012呢,\10代表\n,所以输出为ab\ncd
    char str5[]="ab\012cd";//\012是一个整体,代表一个字符
    printf("%s\n",str5);
    printf("%d\n",sizeof(str5));//6,sizeof代表数组大小,后面好有个\0
    printf("%d\n",strlen(str5));//5 strlen不包含\0

}

//字符串拷贝功能实现
void str_cpy(char* src,char* dst)
{
    for (int i = 0; src[i]!='\0'; i++)
    {
        dst[i]=src[i];
    }
    
}
void test02()
{
    char src[]="asadasdasdasdfg";
    char dst[100];
    str_cpy(src,dst);
    printf("%s\n",dst);

}
//字符串翻转
void str_re(char* str)
{
    const int i=strlen(str);
    char buf[i+1];

    for(int j=i-1;j>=0;j--)
    {
        buf[i-1-j]=str[j];
    }
    buf[i]='\0';
    strcpy(str,buf);
}

void str_re2(char* str)
{
    int start=0;
    int end=strlen(str)-1;
    while(start<end)
    {
        char t=str[start];
        str[start]=str[end];
        str[end]=t;
        start++;
        end--;
    }     
}

void test03()
{
    char str[]="hello world";
    str_re2(str);
    printf("%s\n",str);
}

int main()
{

    test03();
    system("pause");
    return 0;
}
