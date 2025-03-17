#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//对于链表,头部的插入和删除比较容易
//栈的链式存储
//设计节点结构体--企业级  只维护指针域
struct StackNode
{
   struct StackNode* next;
};
//创建栈的结构体
typedef struct Sstack
{
    struct StackNode p_head;
    
    int m_size;
}Linkstack;

//栈的初始化
typedef void* Mystack;
Mystack  init_satck()
{
    Linkstack * mystack=(Linkstack*) malloc(sizeof(Linkstack));
    mystack->p_head.next=NULL;
    mystack->m_size=0;
    return (void*)mystack;
}
//入栈操作--在栈头部插入节点
void push_stack(Mystack stack,void * data)
{
    if (stack==NULL)
    {
        return;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    struct StackNode* new_node=(struct StackNode*)data;//只取数据的前4个字节
    new_node->next=mystack->p_head.next;
    mystack->p_head.next=new_node;
    mystack->m_size++;
}
//出栈
void pop_stack(Mystack stack)
{
    if (stack==NULL)
    {
        return;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    if (mystack->m_size==0)
    {
        return;
    }
    mystack->p_head.next=mystack->p_head.next->next;
    mystack->m_size--;
}
//返回栈顶元素
struct StackNode * top_stack(Mystack stack)
{
    if (stack==NULL)
    {
        return NULL;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    if (mystack->m_size==0)
    {
        return NULL;
    }
    return mystack->p_head.next;
}
//返回栈个数
int size_stack(Mystack stack)
{
    if (stack==NULL)
    {
        return -1;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    return mystack->m_size;
}
//判断是否为空
int is_empty_stack(Mystack stack)
{
    if (stack==NULL)
    {
        return -1;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    if (mystack->m_size==0)
    {
        return 1;
    }
    return 0;
}
//销毁栈
void destroy_stack(Mystack stack)
{
    if (stack==NULL)
    {
        return;
    }
    Linkstack* mystack=(Linkstack*)stack;//数据类型转换
    free(mystack);
    mystack=NULL;
}

struct Person
{
    struct StackNode * data;
    char name[64];
    int age;
};
void test01()
{
    //测试
    Mystack mystack=init_satck();
    struct Person p1={NULL,"aaa",10};
    struct Person p2={NULL,"bbb",20};
    struct Person p3={NULL,"ccc",30};
    struct Person p4={NULL,"ddd",40};
    struct Person p5={NULL,"eee",50};
    push_stack(mystack,&p1);
    push_stack(mystack,&p2);
    push_stack(mystack,&p3);
    push_stack(mystack,&p4);
    push_stack(mystack,&p5);
    printf("栈的大小为%d\n",size_stack(mystack));
    while (!is_empty_stack(mystack))
    {
        struct Person * p=(struct Person*)top_stack(mystack);
        printf("姓名：%s 年龄：%d\n",p->name,p->age);
        pop_stack(mystack);
    }
    printf("栈的大小为%d\n",size_stack(mystack));
    destroy_stack(mystack);
}
int main()
{

    test01();
    system("pause");
    return 0;
}
