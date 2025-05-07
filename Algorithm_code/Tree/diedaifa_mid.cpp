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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:

//法三 boolean法
    vector<int> midorderTraversal2(TreeNode *root)
    {
        //每个元素都是一个pair  second为bool类型,标记是否被访问过
        vector<int> res;
        stack<pair<TreeNode *, bool>> st; // 每个元素都是一个pair  second为bool类型,标记是否被访问过>
        if (root == NULL) return res; // 如果根节点为空，则返回空结果
        st.push(make_pair(root, false)); // 将根节点压入栈中,默认为false,代表还没有给right 和 left安排
        //中序遍历  左中右
        while (!st.empty())
        {
            pair<TreeNode *, bool> node = st.top(); // 弹出栈顶元素
            st.pop();                               // 弹出栈顶元素
            TreeNode * tnode=node.first; // 获取节点
            bool flag=node.second; // 获取节点的标记
            if (flag)//代表访问过  可以弹出插入
            {
                res.push_back(tnode->val); // 将节点值存入结果中
            }
            else//代表没有访问过  先将右节点压入栈中,再将当前节点压入栈中,最后将左节点压入栈中
            {
                if (tnode->right) st.push(make_pair(tnode->right, false)); // 将右节点先压入栈中
                st.push(make_pair(tnode, true));         // 将中节点压入栈中
                if (tnode->left) st.push(make_pair(tnode->left, false));  // 将左节点压入栈中
            }
        }
        return res; // 返回结果
        
    }
//法二
    vector<int> midorderTraversal1(TreeNode *root)
    {
        vector<int> res; // 用于存储结果
        stack<TreeNode *> st; // 创建栈,用于存储节点
        if (root == NULL) return res; // 如果根节点为空，则返回空结果
        st.push(root); // 将根节点压入栈中
        //中序遍历  左中右
        while (!st.empty())
        {
            TreeNode *node = st.top(); // 弹出栈顶元素
            st.pop();                 // 弹出栈顶元素
            if (node != NULL)         // 如果弹出的是空节点，则继续
            {
                //按照左中右的顺序插入元素
                if(node->right) st.push(node->right); // 将右节点先压入栈中
                st.push(node);         // 将中节点压入栈中
                st.push(NULL);        // 将空节点压入栈中
                if(node->left) st.push(node->left);  // 将左节点压入栈中
            }
            else//只有遇到空节点时才将结果存入
            {
                node = st.top(); // 弹出栈顶元素
                st.pop();         // 弹出栈顶元素
                res.push_back(node->val); // 将节点值存入结果中
            }
            
        }
        return res; // 返回结果
    }
    // 前序遍历--迭代法  中左右
    vector<int> midorderTraversal(TreeNode *root)
    {
        vector<int> res;      // 用于存储结果
        stack<TreeNode *> st; // 创建栈,用于存储节点
        TreeNode *cur = root; // 创建节点指针,用于遍历树
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL) // 遍历左子树
            {
                st.push(cur);    // 将节点压入栈中
                cur = cur->left; // 遍历左子树
            } // 一路向左遍历到最底部
            else
            {
                cur = st.top();          // 弹出栈顶元素
                st.pop();                // 弹出栈顶元素
                res.push_back(cur->val); // 将节点值存入结果中
                cur = cur->right;        // 遍历右子树
            }
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
    vector<int> res = s.midorderTraversal2(root);
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