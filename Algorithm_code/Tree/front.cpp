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
void print(TreeNode* root,vector<int>& res)
{
    if (root == NULL)//退出条件
    {
        return;
    }
    res.push_back(root->val);
    print(root->left, res);
    print(root->right, res);
}

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            print(root, res);
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
    vector<int> res = s.preorderTraversal(root);
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