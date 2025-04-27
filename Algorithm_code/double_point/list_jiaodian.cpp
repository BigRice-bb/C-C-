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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* pa=headA;
        ListNode* pb=headB;
        while (pa!=pb)
        {
            if (pa!=NULL)
            {
                pa=pa->next;
            }else
            {
                pa=headB;
            }
            if (pb!=NULL)
            {
                pb=pb->next;
            }else
            {
                pb=headA;
            }
        }
        return pa;
    }





    //一刷
        ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        ListNode* pa=headA;
        ListNode* pb=headB;
        while (pa!=pb)
        {
            if (pa!=NULL)
            {
                pa=pa->next;
            }else
            {
                pa=headB;
            }
            if (pb!=NULL)
            {
                pb=pb->next;
            }else
            {
                pb=headA;
            }
        }
        return pa;
        }
    };
void test01()
{
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);
    ListNode* node6=new ListNode(6);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;//1-2-3-4-5-6
    ListNode* node7=new ListNode(7);
    ListNode* node8=new ListNode(8);
    node7->next=node8;
    node8->next=node3;//7-8-3-4-5-6
    Solution s;
    ListNode* res=s.getIntersectionNode(node1,node7);
    cout << res->val << endl;
    
    
}

int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}