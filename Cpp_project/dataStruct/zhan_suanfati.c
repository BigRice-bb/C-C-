#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//5+5*(6)+9/3*1)-(1+3(     就近匹配问题
//创建栈结构体
typedef struct Stack
{
    char data[8];
    int size;
}stack;
//初始化栈
stack*  init_Stack()
{
    stack* mystack = (stack*)malloc(sizeof(stack));
    if (mystack== NULL)
    {
        return NULL;
    }
    mystack->size = 0;
    memset(mystack->data,0,sizeof(char)*8);
    return mystack;
}
//入栈
void push_SeqStack(stack* mystack, char data)
{
    if (mystack== NULL)
    {
        return;
    }
    mystack->data[mystack->size] = data;
    mystack->size++;
}
//返回栈顶元素
char top_SeqStack(stack* mystack)
{
    if (mystack==NULL)
    {
        return '\0';
    }
    if (mystack->size == 0)
    {
        return '\0';
    }
    else
    {
        return mystack->data[mystack->size-1];
    }
    mystack->size--;//出栈
}
//判断栈是否为空
int is_empty_stack(stack* mystack)
{
    if (mystack==NULL)
    {
        return -1;
    }
    if (mystack->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}
void test01()
{
    char str[] ="5+5*(6)+(9/3*1)-(1+3())";
    char* p = str;
    stack* mystack = init_Stack();
    while (*p!='\0')
    {
        if (*p=='(')
        {
            push_SeqStack(mystack, *p);
        }
        else if (*p==')')
        {
            if (top_SeqStack(mystack)!= '(')
            {
                printf("括号匹配错误\n");
                return;
            }   
        }
        p++;
    }
    if (is_empty_stack(mystack))
    {
        printf("括号匹配错误\n");
        return;
    }
    printf("括号匹配正确\n");
    return;
}
int main()
{

    test01();
    system("pause");
    return 0;
}