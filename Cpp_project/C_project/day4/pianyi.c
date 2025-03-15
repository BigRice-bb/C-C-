//结构体的偏移量
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
struct teacher{
    char a;//0-3
    int b;//4-7  内存对齐
    int c;//8-11
};
//两种方法查看属性偏移量
void test01()
{
    //1,offsetof函数  
    printf("c的属性偏移量为:%d \n",offsetof(struct teacher,c));
    //2.通过计算
    struct teacher t1={'a',10,20};
    struct teacher* p=&t1;
    printf("b的偏移量为:%d\n",(size_t)&(p->b)-(size_t)p);

    //通过偏移量操作内存
    printf("%d\n",*(int*)((char*)p+(size_t)&(p->b)-(size_t)p));
}
int main()
{

    test01();
    system("pause");
    return 0;
}