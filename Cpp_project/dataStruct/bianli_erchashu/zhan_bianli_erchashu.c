#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "zhan_shunxu_category.h"
//树节点结构体
struct BinaryNode
{
    
    int data;
    struct BinaryNode *left;//左孩子
    struct BinaryNode *right;//右孩子
    int flag;
};
void nonRecursion( struct BinaryNode*nodeA)
{
    SStack *stack = init_SeqStack();//初始化栈
    push_SeqStack(stack, nodeA);
    while (stack->size> 0)
    {
        struct BinaryNode *node = (struct BinaryNode *)top_SeqStack(stack);
        //printf("%c ", node->data);
        pop_SeqStack(stack);
        //如果标志位为真 输出
        if (node->flag == 1)
        {
            printf("%c ", node->data);
            continue;
        }
        //如果为假
        node->flag = 1;
        //如果右孩子不为空，入栈
        if (node->right != NULL)
        {
            push_SeqStack(stack, node->right);
        }
        //如果左孩子不为空，入栈
        if (node->left != NULL)
        {
            push_SeqStack(stack, node->left);
        }
        //自身入栈
        push_SeqStack( stack, node);
    }
    destroy_SeqStack(stack);

}

void test01()
{
    struct BinaryNode nodeA = {'A', NULL, NULL,0};
    struct BinaryNode nodeB = {'B', NULL, NULL,0};
    struct BinaryNode nodeC = {'C', NULL, NULL,0};
    struct BinaryNode nodeD = {'D', NULL, NULL,0};
    struct BinaryNode nodeE = {'E', NULL, NULL,0};
    struct BinaryNode nodeF = {'F', NULL, NULL,0};
    struct BinaryNode nodeG = {'G', NULL, NULL,0};
    struct BinaryNode nodeH = {'H', NULL, NULL,0};
    //建立节点间的关系
    nodeA.left = &nodeB;
    nodeA.right = &nodeF;

    nodeB.right = &nodeC;

    nodeC.left = &nodeD;
    nodeC.right = &nodeE;

    nodeF.right = &nodeG;

    nodeG.left = &nodeH;
    //非递归遍历
    nonRecursion(&nodeA);


}
int main()
{

    test01();
    system("pause");
    return 0;
}