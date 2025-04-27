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

//创建链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reversr(ListNode* pre, ListNode* cur)
{
    if (cur == NULL)
    {
        return pre;
    }
    ListNode* next = cur->next;
    cur->next = pre;
    return reversr(cur, next);
}
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            return reversr(NULL, head);
    }
    };
void test01()
{
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode* cur = head;
    while (cur!= NULL)
    {
        cout << cur->val << endl;
        cur = cur->next;
    }
    Solution s;
    ListNode* newHead = s.reverseList(head);
    cout << "-----------------" << endl;
    cur = newHead;
    while (cur!= NULL)
    {
        cout << cur->val << endl;
        cur = cur->next;
    } 
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}