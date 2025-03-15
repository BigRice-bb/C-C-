//对char或int数组进行排序
//冒泡排序   选择排序
//template<typename T>等价于template<class T>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//需求：对任意类型的数组进行排序。排序的规则是从大到小

//交换函数
template<typename T>
void myswap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

//排序函数
//template<typename T>等价于template<class T>
template<typename T>
void mysort(T *arr, int size)
{
    //冒泡排序
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]<arr[j])
            {
                myswap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//选择排序
template<typename T>
void mysort2(T *arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int max=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[max]<arr[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            myswap(arr[i],arr[max]);
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void test01()
{
    char  charArray[]="helloWorld";
    int  intArray[]={0,4,1,5,0,2,1,0};
    mysort2(charArray, sizeof(charArray) - 1); // exclude null terminator
    mysort2(intArray, sizeof(intArray) / sizeof(intArray[0]));
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}