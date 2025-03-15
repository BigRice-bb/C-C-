#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//定义链表节点数据结构,用户可以输入自定义链表
typedef struct linknode
{
    int data;
    linknode* next;
}linknode;
linknode* init_linklist()
{
    //创建头结点,返回头结点
    linknode *head=(linknode*)malloc(sizeof(linknode));
    head->next=NULL;
    //让用户输入几个初始化节点,-1代表退出
    //创建尾节点用于传递
    linknode *tail;
    tail->next=NULL;
    int val=-1;
    int num=1;
    while(1)
    {
        printf("输入第%d个节点的值: ",num);
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        //创建新节点
        linknode *newnode=(linknode*)malloc(sizeof(linknode));
        newnode->data=val;
        newnode->next=NULL;
        if (num==1)
        {
            head->next=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;//把新节点地址给上一个尾节点
            tail=newnode;//新节点变为尾节点
        }
        num++;
    }
    return head;
}
//查找倒数第k个节点的值并删除
void find_re_k_del(linknode* head, int k)
{
    //查找节点总数
    int count = 0;
    linknode* cur = head;
    while (cur->next!=NULL)
    {
        count++;
        cur = cur->next;
    }
    //倒数第二个也就是正数第count-k+1个节点
    linknode* pcur = head->next;
    linknode* pre=head;
    int pos = 1;
    while (pos!=count-k+1)
    {
        pre=pcur;
        pcur=pcur->next;
        pos++;
    }
    pre->next=pcur->next;//删除pcur节点
}
//展示链表
void show_linklist(linknode *head)
{
    linknode* temp=head->next;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void test01()
{
    linknode* head=init_linklist();
    show_linklist(head);
    find_re_k_del(head, 3);
    show_linklist(head);
}
int main()
{

    test01();
    system("pause");
    return 0;
}