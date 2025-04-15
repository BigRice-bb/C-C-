#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//创建邻节点结构体
struct edgeNode
{
    int pos; //邻接点下标
    struct edgeNode *next; //指向下一个邻接点的指针
    //int weight; //权值
};
//顶点数组的结构体
struct vertexNode
{
    char data[9];  //顶点信息
    struct edgeNode *firstEdge;  //指向第一个邻接点的指针
};
//图的结构体
struct graph
{
    struct vertexNode vertexs[10]; //顶点数组
    int vertexNum; //顶点数
    int edgeNum; //边数
};
//查看某一节点位置
int findPos(struct graph *graph, char *data)
{
    for (int i = 0; i < graph->vertexNum; i++)
    {
        if (strcmp(graph->vertexs[i].data, data) == 0)
        {
            return i;
        }
    }
    return -1;
}
//创建一个图
void createGraph(struct graph *graph)
{
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &graph->vertexNum, &graph->edgeNum);
    printf("请输入顶点信息：\n");
    for (int i = 0; i < graph->vertexNum; i++)
    {
        scanf("%s", graph->vertexs[i].data);
        graph->vertexs[i].firstEdge = NULL;
    }
    printf("请输入%d条边的信息: \n", graph->edgeNum);
    char v1[9], v2[9];
    //int weight;
    for (int k = 0; k < graph->edgeNum; k++)
    {
        scanf("%s %s", v1, v2);
        int i = findPos(graph, v1);
        int j = findPos(graph, v2);
        struct edgeNode *node = (struct edgeNode *)malloc(sizeof(struct edgeNode));
        node->pos = j; //邻接点下标 
        //node->weight = weight; //权值
        node->next = graph->vertexs[i].firstEdge; //将新节点插入到链表的头部
        graph->vertexs[i].firstEdge = node; //更新头指针
    }
}
//打印图
void printGraph(struct graph *graph)
{
    printf("\n");
    printf("邻接表：\n");
    for (int i = 0; i < graph->vertexNum; i++)
    {
        printf("%s ", graph->vertexs[i].data);
        struct edgeNode *node = graph->vertexs[i].firstEdge;
        while (node != NULL)
        {
            printf("\t%s ", graph->vertexs[node->pos].data);
            node = node->next;
        }
        printf("\n");
    }
}

void test01()
{
    struct graph graph;
    createGraph(&graph);
    printGraph(&graph);

}
int main()
{
    
    test01();
    system("pause");
    return 0;
}