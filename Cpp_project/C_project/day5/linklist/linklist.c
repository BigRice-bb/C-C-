#include"linklist.h"

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

void show_linklist(linknode *head)
{
    linknode* temp=head->next;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void insert_linknode(linknode *head, int olddata, int newdata)
{
    if (head == NULL) return; 
    linknode *temp=head;
    linknode *newnode=(linknode*)malloc(sizeof(linknode));
    newnode->data=newdata;
    newnode->next=NULL;
    while (temp->next!=NULL && temp->next->data!=olddata )
    {
        temp=temp->next;
    }
    if (temp->next==NULL)
    {
        printf("没有找到插入位置\n");
        return;
    }
    printf("找到 %d，插入 %d\n", olddata, newdata);
    newnode->next=temp->next;
    temp->next=newnode;
}

void delete_linknode(linknode *head, int data)
{
    if(head==NULL)return;
    linknode *pre=head;
    linknode *cur=head->next;
    while (pre->next!=NULL && cur->data!=data)
    {
        cur=cur->next;
        pre=pre->next;
    }
    if(cur==NULL)
    {
        printf("没有找到删除位置\n");
        return;
    }
    pre->next=cur->next;
    free(cur);
    cur=NULL;    
}

void clear_linklist(linknode *head)
{
    if (head==NULL)
    {
        return;
    }
    linknode *temp=head->next;
    while (temp!=NULL)
    {
        head->next=temp->next;
        free(temp);
        temp=head->next;
    }
}

void destroy_linklist(linknode *head)
{
    if (head==NULL)
    {
        return;
    }
    linknode *temp=head->next;
    while (temp!=NULL)
    {
        head->next=temp->next;
        free(temp);
        temp=head->next;
    }
    free(head);
    head=NULL;
}

void insert_pos(linknode *head, int pos, int data)
{
    if (head==NULL)
    {
        return;
    }
    //先创建一个新节点
    linknode *newnode=(linknode *)malloc(sizeof(linknode));
    newnode->data=data;
    newnode->next=NULL;
    //创建中间节点
    linknode *pre=head;
    linknode *cur=head->next;
    for (size_t i = 1; i < pos; i++)
    {
        if (pre==NULL)
        {
            printf("插入位置不合法\n");
            return;
        }
        pre=pre->next;
        cur=cur->next;
    }
    pre->next=newnode;
    newnode->next=cur;
}

linknode* reverse_linklist(linknode *head)
{
    if (head == NULL || head->next == NULL) return head; // 空链表或只有一个元素
    linknode *pre=NULL;
    linknode *cur=head->next;
    linknode *nex=NULL;
    while (cur!=NULL)
    {
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    head->next = pre; // 重新连接头结点（仅对带头结点的情况适用）
    return head;      // 对于不带头结点的链表，应返回 `pre`
}
