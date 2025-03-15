#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct linknode{
    int data;
    struct linknode *next;
}linknode;

//链表初始化--返回用户头节点
linknode* init_linklist();
//打印链表
void show_linklist(linknode *head);
//插入节点--需求,传入两个数,第一个数为插入位置基准,第二个数为插入数据
//要求插在第一个数的前一个节点
void insert_linknode(linknode *head,int olddata,int newdata);
//删除链表  需求--用户传入想删的数,删除该数的节点,
//如果有多个,删除第一个
void delete_linknode(linknode *head,int data);
//清空链表
void clear_linklist(linknode *head);
//销毁链表
void destroy_linklist(linknode *head);
//通过位置插入数据
void insert_pos(linknode*head,int pos,int data);
//链表的反转
linknode* reverse_linklist(linknode*head);