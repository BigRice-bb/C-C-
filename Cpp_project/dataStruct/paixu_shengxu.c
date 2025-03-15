#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void test01(int *arr)
{
    //两个数组 一个接受奇数  一个接受偶数
    int odd[10];
    int even[10];
    int o=0,e=0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i]%2!=0)
        {
            odd[o]=arr[i];
            o++;
        }
        else
        {
            even[e]=arr[i];
            e++;
        }
    }//o,e代表奇偶数的个数
    //对奇偶数进行排序 
    //奇数--冒泡排序
    for (int i = 0; i < o-1; i++)
    {
        for (int j = i+1; j < o; j++)
        {
            if (odd[i]>odd[j])
            {
                int temp=odd[i];
                odd[i]=odd[j];
                odd[j]=temp;
            }
        } 
    }
    //偶数--选择排序
    for (int i = 0; i < e-1; i++)
    {
        int min=i;
        for (int j =i+1; j < e; j++)
        {
            if (even[min]>even[j])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            int temp=even[i];
            even[i]=even[min];
            even[min]=temp;
        } 
    }
    //将数组整合进arr
    for (int i = 0; i < o; i++)
    {
        arr[i]=odd[i];
    }
    for (int i = o; i <10 ; i++)
    {
        arr[i]=even[i-o];
    }
}
int main()
{
    printf("pelase input your array:");
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d ",&arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    test01(arr);//对数组进行排序
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    system("pause");
    return 0;
}