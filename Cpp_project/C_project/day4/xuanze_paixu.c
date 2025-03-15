#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mysort(char **arrs,int num)
{
    for (size_t i = 0; i < num-1; i++)
    {
        int min=i;
        for (size_t j = i+1; j < num; j++)
        {
            if (strcmp(*(arrs+i),*(arrs+j))>0)
            {
                min=j;
            }
        }
        char* t=*(arrs+i);
        *(arrs+i)=*(arrs+min);
        *(arrs+min)=t;
    }
    for (size_t i = 0; i < num; i++)
    {
        printf("%s ",*(arrs+i));
    }
    
}
void test01()
{
    //创建一个指针数组
    char *arrs[]={"aaa","bbb","ccc","ddd"};//大小为4的指针数组
    //对指针数组进行排序--选择排序
    printf("%d ",sizeof(arrs));
    mysort(arrs,4);
}
//选择排序
void test02()
{
    int arr[]={2,6,3,7,3,87,2,6,2,34};//无序数组
    //利用选择排序从小到大排序
    int min;//最小项
    for (size_t i = 0; i < sizeof(arr)/sizeof(int)-1; i++)
    {
        min=i;
        for (size_t j = i+1; j < sizeof(arr)/sizeof(int); j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
            {
                int t=arr[i];
                arr[i]=arr[min];
                arr[min]=t;
            }
    }
    for (size_t i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{

    test01();
    system("pause");
    return 0;
}