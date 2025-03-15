#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 创建动态数组的结构体
typedef struct dynamic_arr
{
    void **pAddr;   // 存储数组的堆区指针
    int m_capacity; // 数组所能容纳的最大元素个数
    int m_size;     // 当前数组有效元素的个数
} D_Arr;
// 初始化动态数组
D_Arr *D_ArrInit(int capacity)
{ 
    // 创建动态数组结构体
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
        return NULL; // 判断是否开辟成功
    }
    pArr->m_capacity = capacity;
    pArr->m_size = 0;
    printf("动态数组初始化成功\n"); 
    return pArr;
}
//移动元素的函数
void arrMove(D_Arr* parr,int pos)
{
    for (int i = parr->m_size; i >pos; i--)
    {
        parr->pAddr[i] = parr->pAddr[i - 1];
    }
    
}
//插入元素到动态数组
void D_ArrInsert(D_Arr *pArr, int pos, void *data)
{
    if (pArr == NULL)
    {
        return;
    }
    if (data== NULL)
    {
        return;
    }
    if (pos<0 || pos>pArr->m_size)//如果位置超出末尾,进行尾插
    {
        pos=pArr->m_size;
    }
    //判断数组是否已满,如果满了,进行扩容
    if (pArr->m_size>=pArr->m_capacity)
    {
        //开辟新的空间
        int new_capacity=pArr->m_capacity*2;
        void **new_pAddr = (void **)malloc(sizeof(void *) * new_capacity);
        //将原空间copy给新空间
        memcpy(new_pAddr, pArr->pAddr, sizeof(void *) * pArr->m_capacity);
        //释放原空间
        free(pArr->pAddr);
        //改变动态数组指向
        pArr->m_capacity=new_capacity;
        pArr->pAddr = new_pAddr;
    }
    //进行插入pos<size的位置  pos>=size--size
    if (pos==pArr->m_size)
    {
        pArr->pAddr[pArr->m_size] = data;
        pArr->m_size++;
    }
    else if (pos<pArr->m_size)
    {
        //pos位置开始的元素往后移一位
        arrMove(pArr,pos);
        pArr->pAddr[pos] = data;
        pArr->m_size++;
    }  
}
//测试
struct Person
{
    char name[64];
    int age;
};
//用户自定义打印函数 比如现在是int 
void my_print(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("%s %d \n", p->name, p->age);
}
//动态数组遍历
void D_ArrPrint(D_Arr *pArr,void (*myPrint)(void *))
{
    if (pArr == NULL)
    {
        return;
    }
    for (int i = 0; i < pArr->m_size; i++)
    {
        //调用回调函数,用户自己处理
        my_print(pArr->pAddr[i]);
    }
    printf("\n");
}

//按位置删除元素
void D_ArrErase_pos(D_Arr *pArr, int pos)
{
    if (pArr == NULL)
    {
        return;
    }
    if (pos<0 || pos>pArr->m_size-1)//size位置也取不到
    {
        return;
    }
    for (int i = pos+1; i < pArr->m_size; i++)
    {
        pArr->pAddr[i-1] = pArr->pAddr[i];
    }
    pArr->m_size--;
}
void mydatatype_person(D_Arr *pArr,void *value)
{
    struct Person* p=(struct Person*)value;
    struct Person** p1=(struct Person**)pArr->pAddr;
    int j=pArr->m_size;
    for (int i = 0; i < j; i++)
    {  
        if (p1[i]->age==p->age && strcmp(p1[i]->name,p->name)==0)
        {
            D_ArrErase_pos(pArr, i);
            i--;
            j--;
        }
        
    }  
}
//按元素的值删除元素
void D_ArrErase_value(D_Arr *pArr, void * value,void (*mydatatype)(D_Arr*,void *))
{
    if (pArr == NULL)
    {
        return;
    }
    mydatatype(pArr,value);
}

//销毁数组
void D_ArrDestroy(D_Arr *pArr)
{
    if (pArr== NULL)
    {
        return ;
    }
    if (pArr->pAddr != NULL)
    {
        free(pArr->pAddr);
        pArr->pAddr = NULL;
    }
    if (pArr!=NULL)
    {
        free(pArr);
        pArr = NULL;
    } 
}
void test01()
{ 
    // 初始化动态数组
    D_Arr *pArr = D_ArrInit(5);
    if (pArr != NULL)
    {
        printf("开辟成功: 容量-%d 元素个数-%d\n",pArr->m_capacity,pArr->m_size);
    }
    else
    {
        printf("开辟失败\n");
    }
    printf("插入数据前:  容量-%d  大小-%d\n",pArr->m_capacity,pArr->m_size);
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"eee", 50};
    struct Person p4 = {"ccc", 30};
    struct Person p5 = {"ddd", 40};
    struct Person p6 = {"eee", 50};
    struct Person p7 = {"fff", 60};
    struct Person p8 = {"eee", 50};
    D_ArrInsert(pArr, 0, &p1);
    D_ArrInsert(pArr, 1, &p2);
    D_ArrInsert(pArr, 2, &p3);
    D_ArrInsert(pArr, 3, &p4);
    D_ArrInsert(pArr, 4, &p5);
    D_ArrInsert(pArr, 5, &p6);
    D_ArrInsert(pArr, 6, &p7);
    D_ArrInsert(pArr, 7, &p8);

    //自定义打印函数
    D_ArrPrint(pArr,my_print);
    //ddd 40 bbb 20 eee 50 aaa 10 ccc 30 fff 60
    printf("插入数据后:  容量-%d  大小-%d\n",pArr->m_capacity,pArr->m_size);
    D_ArrErase_pos(pArr, 0);
    D_ArrPrint(pArr,my_print);
    printf("删除第0位数据后:  容量-%d  大小-%d\n",pArr->m_capacity,pArr->m_size);
    D_ArrErase_value(pArr, &p6,mydatatype_person);
    D_ArrPrint(pArr,my_print);
    printf("删除eee数据后:  容量-%d  大小-%d\n",pArr->m_capacity,pArr->m_size);

}

int main()
{

    test01();
    system("pause");
    return 0;
}
