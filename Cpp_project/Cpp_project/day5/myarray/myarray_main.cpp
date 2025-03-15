#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "my_array.h"

void test01()
{
    myarray arr1;
    cout<<"arr1的容量为"<<arr1.getcapacity()<<endl;
    for(int i=0 ; i<10 ; i++)
    {
        arr1.pushback(i);
    }
    cout<<"此时arr1的size为"<<arr1.getsize()<<endl;
    for(int i=0 ; i<10 ; i++)
    {
        cout<<arr1.getdata(i)<<endl;
    }

    myarray arr2(arr1);
    for(int i=0 ; i<10 ; i++)
    {
        cout<<arr2.getdata(i)<<endl;
    }
    cout<<"arr1的第一个元素为："<<arr1[0]<<endl;
    cout<<"arr2的第五个元素为："<<arr2[4]<<endl;
    cout<<"---------"<<endl;
    arr1[0]=10000;
    cout<<arr1[0]<<endl;
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}