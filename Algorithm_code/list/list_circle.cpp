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

ListNode* list_circle(ListNode* head)
{
    if (head== NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            ListNode* cur = head;
            while (cur != slow)
            {
                cur = cur->next;
                slow = slow->next;
            }
            return cur;
        }
    }
    return NULL;
    
}

void test01()
{
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;
    ListNode* res = list_circle(head);
    cout << res->val << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}