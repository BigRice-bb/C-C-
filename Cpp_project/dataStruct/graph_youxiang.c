#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 图的结构体
typedef char VertexInfo[9];
struct Graph
{
    VertexInfo vertexs[10]; // 顶点数组
    int edge[10][10];       // 邻接边矩阵
    int vertexNum;          // 顶点数
    int edgeNum;            // 边数
};
// 创建一个图
void createGraph(struct Graph *graph)
{
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &graph->vertexNum, &graph->edgeNum);
    printf("请输入顶点信息：\n");
    for (int i = 0; i < graph->vertexNum; i++)
    {
        scanf("%s", graph->vertexs[i]);
    }
    // 初始化所有边为不存在
    for (int i = 0; i < graph->vertexNum; i++)
    {
        for (int j = 0; j < graph->vertexNum; j++)
        {
            graph->edge[i][j] = 0;
        }
    }
    printf("请输入弧头 弧尾和权值: \n");
    VertexInfo v1, v2;
    int w;
    for (int k = 0; k < graph->edgeNum; k++)
    {
        scanf("%s %s %d", v1, v2, &w);
        int i = 0;
        int j = 0;
        while (strcmp(graph->vertexs[i], v1) != 0)
        {
            i++;
        }
        while (strcmp(graph->vertexs[j], v2) != 0)
        {
            j++;
        } // 获取无向边的顶点的位置
        graph->edge[i][j] = w;
    }
}
void printGraph(struct Graph *graph)
{
    printf("邻接矩阵：\n");
    for (int i = 0; i < graph->vertexNum; i++)
    {
        printf("  \t%s ", graph->vertexs[i]);
    }
    printf("\n");
    for (int i = 0; i < graph->vertexNum; i++)
    {
        printf("%s ", graph->vertexs[i]);
        for (int j = 0; j < graph->vertexNum; j++)
        {
            printf("\t%d ", graph->edge[i][j]);
        }
        printf("\n");
    }
}

void test01()
{
    struct Graph graph;
    createGraph(&graph);
    printGraph(&graph);
    
}
int main()
{

    test01();
    system("pause");
    return 0;
}