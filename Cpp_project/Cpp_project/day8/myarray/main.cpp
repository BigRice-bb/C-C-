#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "myarray.hpp"

void test01()
{
    myarray<int> arr1(10);
    for(int i=0;i<10;i++)
    {
        arr1[i]=i;
    }
    myarray<int> arr2(arr1);
    for(int i=0;i<10;i++)
    {
        cout<<arr2[i]<<endl;
    }

}

void test02()
{
    myarray<char> arr1(10);
    for(char i='a';i<'a'+10;i++)
    {
        arr1.pushback(i);
    }
    cout<<"arr1的容量为:"<<arr1.getCapacity()<<endl;
    cout<<"arr1的大小为:"<<arr1.getSize()<<endl;
    // for(int  i=0;i<arr1.getSize();i++)
    // {
    //     cout<<arr1[i]<<endl;
    // }
    showarray(arr1);
    myarray<char> arr2(arr1);
    showarray(arr2);
    // for(int i=0;i<arr2.getSize();i++)
    // {
    //     cout<<arr2[i]<<endl;
    // }
    myarray <char> arr3(10);
    arr3=arr1;
    showarray(arr3);
    // for(int i=0;i<arr3.getSize();i++)
    // {
    //     cout<<arr3[i]<<endl;
    // }
   
}
class person
{
public:
    person(string name,int age):m_name(name),m_age(age){};
    string m_name;
    int m_age;
};
int main()
{
    //test02();
    person p("Tom",20);
    //cout<<p<<endl;类对象不可以直接输出
    return EXIT_SUCCESS;
}