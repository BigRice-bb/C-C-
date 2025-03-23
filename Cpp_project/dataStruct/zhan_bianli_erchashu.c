#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//树节点结构体
struct BinaryNode
{
    int data;
    struct BinaryNode *left;//左孩子
    struct BinaryNode *right;//右孩子
};
//创建一个顺序栈



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
}
int main()
{

    test01();
    system("pause");
    return 0;
}