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
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            //法一 : 每次只将层序的最后一个元素存入结果中
            vector<int> res;
            if (root == NULL) return res;
            queue<TreeNode*> q; // 创建队列,用于存储节点
            q.push(root);//将根节点压入队列中
            while (!q.empty())
            {
                int size = q.size(); // 获取当前层的节点数
                for (int i = 0; i < size; i++)
                {
                    TreeNode* node = q.front(); 
                    q.pop();//弹出队首元素
                    if (i == size - 1) // 如果是当前层的最后一个节点，则将其值存入结果中
                    {
                        res.push_back(node->val);
                    }
                    if (node->left != NULL)
                    {
                        q.push(node->left);//将左节点压入队列中
                    } 
                    if (node->right != NULL)
                    {
                        q.push(node->right);//将右节点压入队列中
                    }
                }
            }
            return res;//返回结果   
        }

    //     //法二
    //     vector<int> rightSideView(TreeNode* root) {
    //         vector<int> res;
    //         if (root == NULL) return res;
    //         queue<TreeNode*> q; // 创建队列,用于存储节点
    //         q.push(root);//将根节点压入队列中
    //         while (!q.empty())
    //         {
    //             TreeNode* node = q.front();
    //             q.pop();//弹出队首元素                  
    //             res.push_back(node->val);//将节点值存入结果中
    //             if (node->right != NULL)
    //             {
    //                 q.push(node->right);//将右节点压入队列中
    //             }
    //         }
    //         return res;//返回结果
    //     }
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
    vector<int> res = s.rightSideView(root);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] <<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}
