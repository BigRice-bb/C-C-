#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  MAX 1024  //栈的最大空间
 
//数据类型无法确定--使用void*接受
typedef struct Stack
{
    void* data[MAX];
    int size;

}SStack;//创建栈结构体
//返回用户void*
typedef void* SeqStack;
//栈的初始化
SeqStack init_SeqStack();
//入栈
void push_SeqStack(SeqStack stack, void* data);
//出栈
void pop_SeqStack(SeqStack stack);
//返回栈顶元素
void* top_SeqStack(SeqStack stack);
//返回栈的大小
int size_SeqStack(SeqStack stack) ;
//销毁栈
void destroy_SeqStack(SeqStack stack);