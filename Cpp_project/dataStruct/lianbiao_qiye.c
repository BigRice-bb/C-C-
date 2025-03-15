#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 节点结构体--只维护指针域
struct LinkNode
{
    struct LinkNode *next;
};
// 链表结构体
struct LList
{
    struct LinkNode m_head; // 链表头结点
    int m_size;             // 链表长度
};
// 返回用户void*指针
typedef void *LinkList;
// 初始化链表
LinkList LinkListInit()
{
    struct LList *my_list = (struct LList *)malloc(sizeof(struct LList));
    if (my_list == NULL)
    {
        return NULL;
    }
    // 初始化链表成员
    my_list->m_head.next = NULL;
    my_list->m_size = 0;
    return (void *)my_list;
}
// 插入链表--链表--位置--数据
void LinkListInsert(LinkList list, int pos, void *data)
{
    if (list == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 进行数据类型转换
    if (pos < 0 || pos > my_list->m_size)         // 尾插
    {
        pos = my_list->m_size; // 更新pos,再按常规插入来操作
    }
    // 用户插入数据的前4个字节为地址维护的位置
    struct LinkNode *my_node = (struct LinkNode *)data; // 将数据的前4个字节强制转换为LinkNode*类型
    // 找到pos的前一个节点
    struct LinkNode *preCur = &my_list->m_head;
    for (int i = 0; i < pos; i++)
    {
        preCur = preCur->next;
    }
    // 将新节点插入到preCur和preCur->next之间
    my_node->next = preCur->next;
    preCur->next = my_node;
    my_list->m_size++; // 此时已经将pos插入到链表中,数据位不需要管具体类型
}

// 遍历链表,只能找到每个节点的地址,具体打印需要用户自定义

void LinkListPrint(LinkList list, void (*myPrint)(void *))
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 进行数据类型转换
    struct LinkNode *cur = my_list->m_head.next;
    while (cur != NULL)
    {
        myPrint(cur); // cur现在是4个字节的地址,用户可在函数内部转换指针步长
        cur = cur->next;
    }
}

// 删除节点--pos
void LinkListErase_pos(LinkList list, int pos)
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 进行数据类型转换
    if (pos < 0 || pos >= my_list->m_size)
    {
        return;
    }
    // 找到pos的前一个节点
    struct LinkNode *preCur = &my_list->m_head;
    for (int i = 0; i < pos; i++)
    {
        preCur = preCur->next;
    }
    // 删除pos节点
    struct LinkNode *delNode = preCur->next;
    preCur->next = delNode->next;
    my_list->m_size--;
}
// 删除节点--数据
void LinkListErase_data(LinkList list, void *data, int (*compare)(void *, void *))
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 进行数据类型转换--这只是一个头结点和size
    if (data == NULL)
    {
        return;
    }
    // 找到pos的前一个节点
    int flag;
    struct LinkNode *preCur = &my_list->m_head;
    while (preCur->next != NULL)
    {
        flag=0;
        if (compare(preCur->next, data) == 0)
        {
            struct LinkNode *delNode = preCur->next;
            preCur->next = delNode->next;
            my_list->m_size--;
            flag=1;
        }
        if (flag==0)
        {
            preCur = preCur->next;
        } 
    }
}
//销毁链表
void LinkListDestroy(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 进行数据类型转换
    free(my_list);
    my_list->m_size = 0;


    printf("销毁成功\n");
}

// 测试
struct person
{
    struct LinkNode node;
    char name[64];
    int age;
};
int compare_person(void *data1, void *data2)
{
    struct person *p1 = (struct person *)data1;
    struct person *p2 = (struct person *)data2;
    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
void myprint_person(void *data)
{
    struct person *p = (struct person *)data;
    printf("%s %d \n", p->name, p->age);
}

void test01()
{
    LinkList list = LinkListInit();
    struct person p1 = {NULL, "aaa", 10};
    struct person p2 = {NULL, "bbb", 20};
    struct person p3 = {NULL, "ccc", 30};
    struct person p4 = {NULL, "ddd", 40};
    struct person p5 = {NULL, "eee", 50};
    struct person p6 = {NULL, "fff", 60};
    struct person p7 = {NULL, "bbb", 20};
    LinkListInsert(list, 0, &p1);
    LinkListInsert(list, 1, &p2);
    LinkListInsert(list, 2, &p3);
    LinkListInsert(list, 3, &p4);
    LinkListInsert(list, 4, &p5);
    LinkListInsert(list, 5, &p6);
    LinkListInsert(list, 6, &p7);
    LinkListPrint(list, myprint_person);
    printf("链表长度:%d  ------------------------------\n", ((struct LList *)list)->m_size);
    LinkListErase_data(list, &p2, compare_person);
    LinkListPrint(list, myprint_person);
    printf("链表长度:%d  ------------------------------\n", ((struct LList *)list)->m_size);
    //销毁链表
    LinkListDestroy(list);
    printf("链表长度:%d  ------------------------------\n", ((struct LList *)list)->m_size);

}
int main()
{

    test01();
    system("pause");
    return 0;
}