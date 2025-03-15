#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 数据类型 更加灵活  用void* 接受数据地址
// 链表节点类型
struct LinkNode
{
    void *data;
    struct LinkNode *next;
};
// 链表类型的结构体,维护一个链表的所有信息
struct LList
{
    struct LinkNode *m_head; // 链表头结点
    int m_size;              // 链表长度
};

// 隐藏链表的真实数据类型,用户不可以直接操作
typedef void *LinkList;
LinkList LinkListInit()
// 链表初始化使用void*接收,底层编程人员使用(LList*)进行类型转换
{
    struct LList *my_list = (struct LList *)malloc(sizeof(struct LList));
    if (my_list == NULL)
    {
        return NULL;
    }
    // 初始化链表成员
    my_list->m_head = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    my_list->m_head->next = NULL;
    my_list->m_size = 0;
    my_list->m_head->data = 0;
    return (void *)my_list;
}

// 插入链表--链表--位置--数据
// 链表节点标号从0开始,若pos大于m_size,则插入到链表尾部
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
    struct LinkNode *preCur = my_list->m_head; // 指向pos前一个节点
    for (int i = 0; i < pos; i++)
    {
        preCur = preCur->next;
    }
    struct LinkNode *new_node = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    new_node->data = data;
    new_node->next = preCur->next;
    preCur->next = new_node;
    my_list->m_size++;
}
// 遍历链表
struct Person
{
    char name[64];
    int age;
};
void myprint_person(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("%s %d \n", p->name, p->age);
}
void LinkListPrint(LinkList list, void (*myPrint)(void *))
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list;
    struct LinkNode *cur = my_list->m_head->next;
    while (cur != NULL)
    {
        myprint_person(cur->data);
        cur = cur->next;
    }
}

// 销毁链表
void LinkListDestroy(LinkList list)
{
    if (list == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list;
    struct LinkNode *cur = my_list->m_head->next;
    while (cur != NULL)
    {
        // 每个节点都需要释放
        struct LinkNode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(my_list->m_head);
    my_list->m_head = NULL;
    free(my_list);
    my_list = NULL;
    printf("销毁成功\n");
}
// 删除链表元素--pos--按照位置删除
void LinkListErase_pos(LinkList list, int pos)
{
    struct LList *my_list = (struct LList *)list; // 链表类型转换
    if (list == NULL)
    {
        return;
    }
    if (pos < 0 || pos >= my_list->m_size)
    {
        return;
    }
    // 找到pos的前一个节点
    struct LinkNode *preCur = my_list->m_head;
    for (int i = 0; i < pos; i++)
    {
        preCur = preCur->next;
    }
    // 删除pos位置的节点
    struct LinkNode *pCur = preCur->next;
    preCur->next = pCur->next;
    free(pCur);
    pCur = NULL;
    my_list->m_size--;
}
// 删除链表元素--data--按照数据删除--函数指针
int myCompare_person(void *data1, void *data2)
{
    struct Person *p1 = (struct Person *)data1;
    struct Person *p2 = (struct Person *)data2;
    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
void LinkListErase_data(LinkList list, void *data, int (*myCompare)(void *, void *))
{
    int flag;
    if (list == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    struct LList *my_list = (struct LList *)list; // 链表类型转换
    struct LinkNode *pre = my_list->m_head;
    struct LinkNode *cur = pre->next;
    while (cur != NULL)
    {
        flag = 1;
        if (myCompare(cur->data, data) == 0)
        {
            pre->next = cur->next;
            struct LinkNode *oldcur = cur;
            cur = cur->next;
            free(oldcur);
            oldcur = NULL;
            my_list->m_size--;
            flag = 0;
        }
        if (cur==NULL)
        {
            break;
        }
        if (flag == 1)
        {
            pre = cur;
            cur = cur->next;
        }
    }
}
// 清空链表
void LinkListClear(LinkList list)
{
    struct LList *my_list = (struct LList *)list; // 链表类型转换
    if (list == NULL)
    {
        return;
    }
    struct LinkNode *cur = my_list->m_head->next;
    while (cur != NULL)
    {
        struct LinkNode *next = cur->next;
        free(cur);
        cur = next;
    }
    my_list->m_head->next = NULL;
    my_list->m_size = 0;
}
//返回链表长度
int LinkListSize(LinkList list)
{
    struct LList *my_list = (struct LList *)list; // 链表类型转换
    if (list == NULL)
    {
        return -1;
    }
    return my_list->m_size;
}
//返回头结点地址


// 测试
void test01()
{
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};
    struct Person p6 = {"fff", 60};
    // 初始化链表
    LinkList list = LinkListInit();
    // 插入数据
    LinkListInsert(list, 0, &p1);
    LinkListInsert(list, 1, &p2);
    LinkListInsert(list, 2, &p3);
    LinkListInsert(list, 3, &p4);
    LinkListInsert(list, 4, &p5);
    LinkListInsert(list, 5, &p6);
    LinkListInsert(list, 6, &p3);
    // 遍历链表
    LinkListPrint(list, myprint_person);
    printf("链表长度:%d  ------------------------------\n",LinkListSize(list));
    // 删除data的数据
    LinkListErase_data(list, &p3, myCompare_person);
    LinkListPrint(list, myprint_person);
    printf("链表长度:%d  ------------------------------\n",LinkListSize(list));
    //清空链表
    LinkListClear(list);
    LinkListPrint(list, myprint_person);
    printf("链表长度:%d  ------------------------------\n",LinkListSize(list));

    // 销毁链表
    LinkListDestroy(list);
}
int main()
{

    test01();
    system("pause");
    return 0;
}