//多态案例---计算器
//纯虚函数--抽象类--无法实例化对象
//抽象类的子类必须重写纯虚函数，否则也属于纯虚函数
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//首先是一个普通的计算器
class caculator 
{
public:
    int getresult(string sign)
    {
        if(sign=="+")
        {
            return m_a+m_b;
        }
        else if(sign=="-")
        {
            return m_a+m_b;
        }
        else if(sign=="*")
        {
            return m_a*m_b;
        }
        else cout<<"error"<<endl;
        return 0;
    }
    int m_a;
    int m_b;
};

//利用多态实现计算器，不修改源码的前提下添加功能
class  abstractcaculator
{
public:
//父类中什么也不做，构建虚函数，用子类重写来具体实现特定功能
//实现多态，方便代码阅读和拓展和管理
    // virtual int getresult()
    // {
    //     return 0;
    // }
    //纯虚函数
    virtual int getresult()=0;
    int m_a;
    int m_b;
};
//加法实现
class add:public abstractcaculator
{
public:
    int getresult()
    {
        return m_a+m_b;
    }
};
//减法实现
class sub:public abstractcaculator
{
public:
    int getresult()
    {
        return m_a-m_b;
    }
};


void test01()
{
    caculator c1;
    c1.m_a=10;
    c1.m_b=10;
    cout<<c1.getresult("+")<<endl;
}
void test02()
{
    add addcaculator;
    addcaculator.m_a=10;
    addcaculator.m_b=10;
    cout<<addcaculator.getresult()<<endl;

    //父类指针接收子类对象
    abstractcaculator* subcaculator=new sub;
    subcaculator->m_a=100;
    subcaculator->m_b=10;
    cout<<subcaculator->getresult()<<endl;
}
int main()
{
    test02();
    //abstractcaculator ABC; 纯虚函数无法实例化对象
    return EXIT_SUCCESS;
}