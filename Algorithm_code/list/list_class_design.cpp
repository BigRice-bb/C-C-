#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
// 规定链表自带头结点
// 规定节点索引从0开始

// 节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    // 链表节点的三种构造方法
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 实现链表类
class MyLinkedList
{
public:
    MyLinkedList()
    { // 默认构造需要头节点
        this->head = new ListNode();
        this->m_size = 0;
    } // 默认构造
    // MyLinkedList(MyLinkedList &list) : head(list.head),m_size(list.m_size) {}
    ListNode *head;                      // 头节点
    int m_size;                          // 链表大小
    int get(int index);                  // ：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    void addAtHead(int val);             // ：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    void addAtTail(int val);             // ：将值为 val 的节点追加到链表的最后一个元素。
    void addAtIndex(int index, int val); // ：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    void deleteAtIndex(int index);       // ：如果索引 index 有效，则删除链表中的第 index 个节点。

    // 翻转链表
    void reverseList();
    // 打印链表
    void printList();
    // 两两交换节点
    void swapPairs();
    // 删除链表倒数第N个元素
    void removeNthFromEnd(int n);

    ~MyLinkedList()
    {
        free(head);
    }
};
// 方法实现
int MyLinkedList::get(int index)
{
    if (index < 0 || index >= this->m_size || this->head->next == NULL) // 0-m_size-1
        return -1;
    ListNode *cur = head;
    index++; // 0-m_size-1  ->   1-m-size
    while (index--)
    {
        cur = cur->next;
    }
    return cur->val;
}
void MyLinkedList::addAtHead(int val)
{
    ListNode *new_node = new ListNode(val);
    new_node->next = this->head->next;
    this->head->next = new_node;
    this->m_size++;
}
void MyLinkedList::addAtTail(int val)
{
    ListNode *new_node = new ListNode(val);
    ListNode *cur = this->head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;
    this->m_size++;
}
void MyLinkedList::addAtIndex(int index, int val)
{
    if (index > this->m_size)
    {
        return;
    }
    if (index <= 0)
    {
        addAtHead(val);
        return;
    }
    // index  1-m_size-1
    ListNode *new_node = new ListNode(val);
    ListNode *cur = this->head;
    while (index--)
    {
        cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
    this->m_size++;
}
void MyLinkedList::deleteAtIndex(int index)
{ // 注意链表为空也要return
    if (index < 0 || index >= this->m_size)
    {
        return;
    }
    // index 0-m_size-1
    // 找到需要删除的前一节点
    ListNode *cur = this->head;
    while (index--)
    {
        cur = cur->next;
    }
    ListNode *del_node = cur->next;
    cur->next = cur->next->next;
    delete del_node; // 记得释放内存
    this->m_size--;
}

void MyLinkedList::reverseList()
{
    // 双指针法
    ListNode *pre = NULL;
    ListNode *cur = this->head->next;
    head->next = NULL;
    while (cur != NULL)
    {
        ListNode *next = cur->next; // 定义一个缓存变量
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    this->head->next = pre;
}

// 打印链表
void MyLinkedList::printList()
{
    ListNode *cur = this->head;
    while (cur->next != NULL)
    {
        cout << cur->next->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
// 两两交换节点
void MyLinkedList::swapPairs()
{
    ListNode *cur = this->head;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        ListNode *temp = cur->next; // 暂存0号节点地址
        cur->next = cur->next->next;
        temp->next = cur->next->next;
        cur->next->next = temp;
        cur = cur->next->next;
    }
}
void MyLinkedList::removeNthFromEnd(int n)
{
    // 快慢指针  构造 滑动窗口
    ListNode *fast = this->head;
    ListNode *slow = this->head;
    do
    {
        fast = fast->next; // fast先移动n+1次
    } while (n--);
    while (fast != NULL) // 当fast==NULL,slow和fast之间相隔n个节点,slow指向倒数第n+1个节点
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *del_node = slow->next;
    slow->next = slow->next->next;
    delete del_node; // 释放内存
}
//找出相交链表的入口节点  若不想交返回NULL
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode* pa=headA;
    ListNode* pb=headB;
    while (pa!=pb)
    {
        if (pa->next!=NULL)
        {
            pa=pa->next;
        }else
        {
            pa=headB;
        }
        if (pb->next!=NULL)
        {
            pb=pb->next;
        }else
        {
            pb=headA;
        }
    }
    return pa;
}

// 基本功能的验证--头插--尾插--中间插--删除--获取元素
void test01()
{
    MyLinkedList obj;
    obj.addAtHead(1);
    obj.addAtTail(3);
    // cout<<obj.m_size << endl;
    obj.addAtIndex(1, 2);       // 链表变为1-> 2-> 3
    cout << obj.get(1) << endl; // 返回2
    obj.deleteAtIndex(1);       // 现在链表是1-> 3
    cout << obj.get(1) << endl; // 返回3
}
// 反转链表的验证
void test02()
{
    MyLinkedList *mylist = new MyLinkedList();
    mylist->addAtHead(1);
    mylist->addAtTail(3);
    mylist->addAtIndex(1, 2); // 链表变为1-> 2-> 3
    mylist->printList();
    cout << "---------------------------\n";
    mylist->reverseList();
    mylist->printList();
}
// 两两交换链表的验证
void test03()
{
    MyLinkedList *mylist = new MyLinkedList();
    mylist->addAtHead(1);
    mylist->addAtTail(2);
    mylist->addAtTail(3);
    mylist->addAtTail(4);
    mylist->printList();
    cout << "---------------------------\n";
    mylist->swapPairs();
    mylist->printList();
}
// 删除链表的倒数第N个节点的验证
void test04()
{
    MyLinkedList *mylist = new MyLinkedList();
    mylist->addAtHead(1);
    mylist->addAtTail(2);
    mylist->addAtTail(3);
    mylist->addAtTail(4);
    mylist->addAtTail(5);
    mylist->printList();
    cout << "---------------------------\n";
    mylist->removeNthFromEnd(4);
    mylist->printList();
}
// 找出相交链表的入口节点的验证
void test05()
{
    ListNode *headA = new ListNode(4);
    ListNode *headB = new ListNode(5);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(8);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    headA->next = node1;
    node1->next = node2;
    node2->next = node3;
    headB->next = node2;
    node3->next = node4;
    ListNode *res = getIntersectionNode(headA, headB);
    cout << res->val << endl;
}
int main()
{
    test05();
    system("pause");
    return EXIT_SUCCESS;
}