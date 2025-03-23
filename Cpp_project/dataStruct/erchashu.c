#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct BinaryNode
{
    int data;
    struct BinaryNode *left;//左孩子
    struct BinaryNode *right;//右孩子
};

void recursion(struct BinaryNode* root)
{
    if (root == NULL)//递归一定要有退出条件
    {
        return;
    }
    //先序遍历
    // printf("%c ", root->data);
    // recursion(root->left);
    // recursion(root->right);
    // 中序遍历
    // recursion(root->left);
    // printf("%c ", root->data);
    // recursion(root->right);
    // 后序遍历
    recursion(root->left);
    recursion(root->right);
    printf("%c ", root->data);
}

//求二叉树的叶子结点个数
void caculateLeafNode(struct BinaryNode* root,int *leaf)
{
    if (root == NULL)
    {
        return ;//出口
    }
    if (root->left == NULL && root->right == NULL)
    {
        (*leaf)++;
        printf("%c ", root->data);
    }
    caculateLeafNode(root->left,leaf);
    caculateLeafNode(root->right,leaf); 
}
//求树的深度
int caculateDepth(struct BinaryNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = caculateDepth(root->left);
    int right = caculateDepth(root->right);
    return left > right ? left + 1 : right + 1;
}
//拷贝二叉树
struct BinaryNode* copytree(struct BinaryNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    //先拷贝左子树
    struct BinaryNode* left = copytree(root->left);
    //在拷贝右子树
    struct BinaryNode* right = copytree(root->right);
    //创建新节点
    struct BinaryNode* newroot = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
    newroot->data = root->data;
    newroot->left = left;
    newroot->right = right;
    return newroot;
}
//释放二叉树
void freeBinaryTree(struct BinaryNode* root)
{
    if (root == NULL)
    {
        return;
    }
    freeBinaryTree(root->left);//先释放左,再释放右
    printf("左子树 %c 左子树\n", root->data);
    freeBinaryTree(root->right);
    printf("右子树 %c 右子树\n", root->data);

    free(root);//最后释放根
}

void test01()
{
    struct BinaryNode nodeA = {'A', NULL, NULL};
    struct BinaryNode nodeB = {'B', NULL, NULL};
    struct BinaryNode nodeC = {'C', NULL, NULL};
    struct BinaryNode nodeD = {'D', NULL, NULL};
    struct BinaryNode nodeE = {'E', NULL, NULL};
    struct BinaryNode nodeF = {'F', NULL, NULL};
    struct BinaryNode nodeG = {'G', NULL, NULL};
    struct BinaryNode nodeH = {'H', NULL, NULL};
    //建立节点间的关系
    nodeA.left = &nodeB;
    nodeA.right = &nodeF;

    nodeB.right = &nodeC;

    nodeC.left = &nodeD;
    nodeC.right = &nodeE;

    nodeF.right = &nodeG;

    nodeG.left = &nodeH;
    //递归遍历算法--传入根节点
    //recursion(&nodeA);
    //计算叶子个数
    // int leaf = 0;
    // caculateLeafNode(&nodeA,&leaf);
    // printf("叶子节点个数为:%d\n",leaf);
    //计算树的深度
    //printf("树的深度为:%d\n",caculateDepth(&nodeA));
    //拷贝二叉树
    struct BinaryNode *newRoot=copytree(&nodeA);
    recursion(newRoot);
    freeBinaryTree(newRoot);
}


int main()
{

    test01();
    system("pause");
    return 0;
}