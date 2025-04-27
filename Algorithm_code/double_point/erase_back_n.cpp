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

class Solution {
    public:
    //二刷
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* back = head;
        while (n--)
        {
            back = back->next;//先走n步
        }
        while (back!=NULL)
        {
            pre = pre->next;
            back = back->next;
        }
        pre->next = pre->next->next;
        return dummy->next;
    }



    //一刷
        ListNode* removeNthFromEnd1(ListNode* head, int n) {
            //创建虚拟头节点
        ListNode* dummy_head=new ListNode(0);
        dummy_head->next=head;
              // 快慢指针  构造 滑动窗口
        ListNode *fast = dummy_head;
        ListNode *slow = dummy_head;
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
        ListNode* result = dummy_head->next;
        delete dummy_head;
        return  result;
        }
    };

void test01()
{
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode* ret = s.removeNthFromEnd(head, 3);
    while (ret != NULL)
    {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
    
}


int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}