#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class myarray
{
public:
//构造函数
    myarray();
//有参构造
    myarray(int capacity);
//拷贝构造
    myarray(const myarray &arr);
//尾插法
    void pushback(int val);
//根据位置设置数据
    void setdata(int pos,int val);
//根据位置获取数据
    int getdata(int pos);
//获取数组容量
    int getcapacity();
//获取数组大小
    int getsize();
//获取数组指针
    int *arr();
//重载[]让可以直接arr[i]
    int& operator[](int i);
//析构函数
    ~myarray();

private:
    int m_capacity;//数组容量
    int m_size;//数组大小
    int* paddress;//维护数组的指针，真实在堆区开辟的数组的指针

};
