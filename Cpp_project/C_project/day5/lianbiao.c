#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//结构体定义链表节点
typedef struct linknode{
    int data;//链表节点数据域
    struct linknode *next;//链表节点下一跳地址--指针域
}linknode;

//静态链表的创建
void test01()
{
    //1.创建节点
    struct linknode node1 = {1,NULL};
    struct linknode node2 = {2,NULL};   
    struct linknode node3 = {3,NULL};
    struct linknode node4 = {4,NULL};
    struct linknode node5 = {5,NULL};
    //2.建立节点关系
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    //3.遍历链表
    struct linknode *temp = &node1;
    while (temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
//动态链表的创建--出了作用域任然可以操作动态链表
void test02()
{
    //1.创建节点
    struct linknode *node1 = (struct linknode *)\
    malloc(sizeof(struct linknode));
    struct linknode *node2 = (struct linknode *)\
    malloc(sizeof(struct linknode));
    struct linknode *node3 = (struct linknode *)\
    malloc(sizeof(struct linknode));
    struct linknode *node4 = (struct linknode *)\
    malloc(sizeof(struct linknode));
    struct linknode *node5 = (struct linknode *)\
    malloc(sizeof(struct linknode));
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;
    node5->data = 5;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=NULL;
    linknode *temp=node1;
    while(temp->next!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    //释放内存
    free(node1);node1=NULL;
    free(node2);node2=NULL;
    free(node3);node3=NULL;
    free(node4);node4=NULL;
    free(node5);node5=NULL;
}
int main()
{

    test01();
    system("pause");
    return 0;
}