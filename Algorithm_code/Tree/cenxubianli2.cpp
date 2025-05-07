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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> res;//用于存储结果
            queue<TreeNode*> q;//创建队列,用于存储节点
            if (root == NULL) return res; // 如果根节点为空，则返回空结果
            int size = 0; // 用于存储当前层的节点数
            q.push(root);//将根节点压入队列中
            while (!q.empty())
            {
                size = q.size(); // 获取当前层的节点数
                vector<int> level; // 用于存储当前层的节点值
                while (size--)//从队列里拿出当前层的节点
                {
                    TreeNode* node = q.front(); 
                    q.pop();//弹出队首元素
                    level.push_back(node->val);//将节点值存入结果中
                    if (node->left != NULL)
                    {
                        q.push(node->left);//将左节点压入队列中
                    } 
                    if (node->right != NULL)
                    {
                        q.push(node->right);//将右节点压入队列中
                    }
                }
                res.push_back(level);//将当前层的节点值存入结果中
            }
            reverse(res.begin(),res.end());//反转结果
            return res;//返回结果
        }
    };
void test01()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(9);
    TreeNode* node2 = new TreeNode(20);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    Solution s;
    vector<vector<int>> res = s.levelOrderBottom(root);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}