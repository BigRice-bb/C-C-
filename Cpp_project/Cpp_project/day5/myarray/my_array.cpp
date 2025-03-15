#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "my_array.h"

myarray::myarray()
{
    cout<<"默认构造函数调用"<<endl;
    this->m_capacity=100;
    this->m_size=0;
    this->paddress=new int[this->m_capacity];
}
myarray::myarray(int capacity)
{
    cout<<"有参构造函数调用"<<endl;
    this->m_capacity=capacity;
    this->m_size=0;
    this->paddress=new int[this->m_capacity];
}
myarray::myarray(const myarray &arr)
{
    cout<<"拷贝构造函数调用"<<endl;
    this->m_capacity=arr.m_capacity;
    this->m_size=arr.m_size;
    this->paddress=new int[arr.m_capacity];
    for(int i=0;i<m_size;i++)
    {
        this->paddress[i]=arr.paddress[i];
    }
}
//尾插法
void myarray::pushback(int val)
{
    this->paddress[m_size]=val;
    (this->m_size)++;
    //cout<<"m_size++"<<endl;
}
//根据位置设置数据
void myarray::setdata(int pos,int val)
{
    this->paddress[pos]=val;
}
//根据位置获取数据
int myarray::getdata(int pos)
{
    return this->paddress[pos];
}
//获取数组容量
int myarray::getcapacity()
{
    return m_capacity;
}
//获取数组大小
int myarray::getsize()
{
    return m_size;
}
int * myarray::arr()
{
    return this->paddress;
}
int& myarray::operator[](int i)
{
    return this->paddress[i];
}
//析构函数
myarray::~myarray()
{
    cout<<"析构函数调用"<<endl;
    if(this->paddress!=NULL)
    {
        delete [] this->paddress;
        this->paddress=NULL;
    }
}