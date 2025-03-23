#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//创建动态数组结构体
typedef struct dynamic_arr
{
    void **pAddr;   //存储数组的堆区指针
    int m_capacity; //数组所能容纳的最大元素个数
    int m_size;     //当前数组有效元素的个数
} D_Arr;
//初始化动态数组
D_Arr *D_ArrInit(int capacity)
{
    //创建动态数组结构体
    D_Arr *pArr = ((D_Arr *)malloc(sizeof(D_Arr)));
    if (pArr == NULL)
    {
        //free(pArr);
        return NULL;
    }
    pArr->pAddr = (void **)malloc(sizeof(void *) * capacity);
    if (pArr->pAddr == NULL)
    {
        free(pArr);
        pArr = NULL;
        return NULL; //判断是否开辟成功
    }
    pArr->m_capacity = capacity;
    pArr->m_size = 0;
    printf("动态数组初始化成功\n");
    return pArr;
}
//所有元素左移一位
void arrMove(D_Arr* parr)
{
    for (int i = 1; i <parr->m_size; i++)
    {
        parr->pAddr[i - 1] = parr->pAddr[i];
    }
    parr->m_size--;
}
//出队列
void* D_ArrPop(D_Arr *pArr)
{
    if (pArr == NULL)
    {
        return NULL;
    }
    if (pArr->m_size == 0)
    {
        return NULL;
    }
    void *ret = pArr->pAddr[0];//返回队头元素
    arrMove(pArr);//将队头元素出队
    return ret;
}
//入队列
void D_ArrPush(D_Arr *pArr, void *data)
{
    if (pArr == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    if (pArr->m_size >=pArr->m_capacity)
    {
        //开辟新的空间
        int new_capacity = pArr->m_capacity * 2;
        void **new_pAddr = (void **)malloc(sizeof(void *) * new_capacity);
        //将原空间copy给新空间
        memcpy(new_pAddr, pArr->pAddr, sizeof(void *) * pArr->m_capacity);
        //释放原空间
        free(pArr->pAddr);
        //改变动态数组指向
        pArr->m_capacity = new_capacity;
        pArr->pAddr = new_pAddr;
    }
    pArr->pAddr[pArr->m_size] = data;
    pArr->m_size++;
}
//销毁队列
void D_ArrDestroy(D_Arr *pArr)
{
    if (pArr == NULL)
    {
        return;
    }
    if (pArr->pAddr != NULL)
    {
        free(pArr->pAddr);
        pArr->pAddr = NULL;
    }
    free(pArr);
    pArr = NULL;
}

typedef struct person
{
    char name[64];
    int age;
}person;
//打印队列
void my_print(void *data)
{
    person *p = (person *)data;
    printf("%s %d \n", p->name, p->age);
}
void D_ArrPrint(D_Arr *pArr, void (*myPrint)(void *))
{
    if (pArr == NULL)
    {
        return;
    }
    for (int i = 0; i < pArr->m_size; i++)
    {
        myPrint(pArr->pAddr[i]);
    }
}
//测试



void test01()
{
    D_Arr *pArr = D_ArrInit(3);
    person p1 = { "aaa", 10 };
    person p2 = { "bbb", 20 };
    person p3 = { "ccc", 30 };
    person p4 = { "ddd", 40 };
    person p5 = { "eee", 50 };
    D_ArrPush(pArr, &p1);
    D_ArrPush(pArr, &p2);
    D_ArrPush(pArr, &p3);
    D_ArrPush(pArr, &p4);
    D_ArrPush(pArr, &p5);
    D_ArrPrint(pArr, my_print);
    printf("队列长度为: %d\n", pArr->m_size);
    D_ArrPop(pArr);
    D_ArrPop(pArr);
    D_ArrPop(pArr);
    D_ArrPop(pArr);
    D_ArrPop(pArr);
    D_ArrPop(pArr);
    D_ArrPrint(pArr, my_print);
    printf("队列长度为: %d\n", pArr->m_size);
    D_ArrDestroy(pArr);

}
int main()
{

    test01();
    system("pause");
    return 0;
}