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
//创建节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        //前序遍历--迭代法  中左右
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;//用于存储结果
            stack<TreeNode*> st;//创建栈,用于存储节点
            st.push(root);//将根节点压入栈中
            while (!st.empty())
            {
                TreeNode* node = st.top(); 
                st.pop();//弹出栈顶元素
                if (node == NULL)
                {
                    continue;//如果弹出的是空节点，则继续
                }
                res.push_back(node->val);//将节点值存入结果中
                st.push(node->right);//将右节点先压入栈中
                st.push(node->left);//将左节点压入栈中
            }
            return res;
        }

        //后序遍历--迭代法  左右中
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;//用于存储结果
            stack<TreeNode*> st;//创建栈,用于存储节点
            st.push(root);//将根节点压入栈中
            while (!st.empty())
            {
                TreeNode* node = st.top(); 
                st.pop();//弹出栈顶元素
                if (node == NULL)
                {
                    continue;//如果弹出的是空节点，则继续
                }
                res.push_back(node->val);//将节点值存入结果中
                st.push(node->left);//将左节点先压入栈中
                st.push(node->right);//将右节点压入栈中
                
            }
            //反转结果
            for (size_t i = 0; i < res.size() / 2; i++)
            {
                swap(res[i], res[res.size() - 1 - i]);//交换元素
            }
            return res;
        }
    };
void test01()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = NULL;
    Solution s;
    vector<int> res = s.postorderTraversal(root);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}