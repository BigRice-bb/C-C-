#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

class father
{
public:
    father()
    {
        cout<<"father的构造函数调用"<<endl;
    }
    ~father()
    {
        cout<<"father的析构函数调用"<<endl;
    }
};

class other
{
public:
    other()
    {
        cout<<"other的构造函数调用"<<endl;
    }
    ~other()
    {
        cout<<"other的析构函数调用"<<endl;
    }
};

class son:public father
{
    //子类的创建会先构造父类。。
public:
    son()
    {
        cout<<"son的构造函数调用"<<endl;
    }
    ~son()
    {
        cout<<"son的析构函数调用"<<endl;
    }
    other o;
};
class a
{
public:
    a(int c)
    {
        cout<<"a的构造函数调用"<<endl;
        this->m_a=c;
    }
    int m_a;
};
class b:public a
{
public:
    b(int c=100):a(c)
    {
        cout<<"b的构造函数调用"<<endl;
    }
};

void test01()
{
    son son1;
}
void test02()
{
    b b1;
    cout<<b1.m_a<<endl;
}
int main()
{
    test02();
    return EXIT_SUCCESS;
}