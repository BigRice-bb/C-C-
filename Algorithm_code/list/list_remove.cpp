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

//链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            if(head==NULL)
                return head;
            ListNode* dummy=new ListNode();//头节点创建时必须分配空间,不然是野指针,无法访问
            dummy->next = head;
            ListNode* cur=dummy;
            while(cur->next!=NULL)
            {
                if(cur->next->val==val)
                {
                    ListNode* tmp=cur->next;
                    cur->next=cur->next->next;
                    delete tmp;//移除节点后记得释放内存
                }
                else
                {
                    cur=cur->next;
                }
            }
            ListNode* result=dummy->next;
            delete dummy;//也要删除堆区内存
            return result;
        }
        //解法二--递归方法
        ListNode* removeElements(ListNode* head, int val) {
            if(head==NULL)
                return head;
            if(head->val==val)
            {
                ListNode* tmp=head;
                head=head->next;
                delete tmp;
                return removeElements(head,val);
            }
            else
            {
                head->next=removeElements(head->next,val);
            }
        }
    };


void test01()
{
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}