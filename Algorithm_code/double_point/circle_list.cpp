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
class Solution
{
public:
    // 二刷
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)//有环形,且fast追到了slow
            {
                ListNode * pre =head ;
                while (pre != slow)
                {
                    pre = pre->next;
                    slow = slow->next;
                }
                return pre;
            }
            
        }
        return NULL;//无环形
    }

    // 一刷
    ListNode *detectCycle1(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};
void test01()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;//1-2-3-4-5-1
    ListNode *ret = s.detectCycle(head);
    cout << ret->val << endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}