#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 节点结构体
struct Node
{
    struct Node *next; // 前4个字节就地址域
};

// 队列结构体
typedef struct Queue
{
    struct Node *front; // 队头指针
    struct Node *rear;  // 队尾指针
    int size;           // 队列大小
} Queue;

// 队列初始化
Queue *QueueInit()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// 入队
void QueuePush(Queue *q, void *data)
{
    if (q == NULL || data == NULL)
    {
        return;
    }
    struct Node *node = (struct Node *)data;
    if (q->size == 0)
    {
        q->front = node;
        q->rear = node;
    }
    else
    {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

// 出队
void QueuePop(Queue *q)
{
    if (q == NULL || q->size == 0)
    {
        return;
    }
    struct Node *temp = q->front;
    if (q->size == 1)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
    //free(temp);
    q->size--;
}

struct Person // 定义结构体
{
    struct Node *next;
    char name[64];
    int age;
};
// 遍历回调函数
void QueuePrint(void *data)
{
    if (data == NULL)
    {
        return;
    }
    struct Person *p = (struct Person *)data;
    printf("%s %d\n", p->name, p->age);
}

// 遍历队列
void QueueTraverse(Queue *q, void (*callback)(void *))
{
    if (q == NULL || callback == NULL || q->size == 0)
    {
        return;
    }
    struct Node *cur = q->front;
    while (cur != NULL)
    {
        callback(cur);
        cur = cur->next;
    }
}

// 销毁队列
void QueueDestroy(Queue *q)
{
    if (q == NULL)
    {
        return;
    }
    // while (q->front != NULL)
    // {
    //     struct Node *temp = q->front;
    //     q->front = q->front->next;
    //     free(temp);
    // }
    free(q);
}

// 测试用例
void test01()
{
    Queue *q = QueueInit();
    struct Person p1 = {NULL, "aaa", 10};
    struct Person p2 = {NULL, "bbb", 20};
    struct Person p3 = {NULL, "ccc", 30};
    struct Person p4 = {NULL, "ddd", 40};
    struct Person p5 = {NULL, "eee", 50};
    QueuePush(q, &p1);
    QueuePush(q, &p2);
    QueuePush(q, &p3);
    QueuePush(q, &p4);
    QueuePush(q, &p5);
    QueueTraverse(q, QueuePrint);
    QueuePop(q);
    QueuePop(q);
    QueuePop(q);
    QueuePop(q);
    QueuePop(q);
    QueueTraverse(q, QueuePrint);
    QueueDestroy(q);
}

int main()
{
    test01();
    system("pause");
    return 0;
}