#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//插入排序,从小到大排序
void insertSort(int *arr, int len)
{
    int j;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int t=arr[i];
            for ( j = i-1; j >=0 && arr[j] > t; j--)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1]=t;
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
void test01()
{
    int nums[10]={2,4,5,6,7,1,3,8,9,10};
    insertSort(nums,10);
}
int main()
{
    test01();
    system("pause");
    return 0;
}