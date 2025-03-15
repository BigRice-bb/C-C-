//问题描述：类模版作为函数的参数时
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//创建一个类模版
template<class t1,class t2>
class person
{
public:
    person(t1 name,t2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    void showPerson()
    {
        cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
    }
    t1 m_name;
    t2 m_age;
};
//将类模版作为参数传递给函数,不可以直接传
//普通函数定义时就会开辟内存，而类模版的数据类型不确定，无法开辟内存
//所以需要在函数定义时指定类模版的数据类型，函数才可以正确创建
//1.指定类模版数据类型
void dowork(person<string,int>&p)
{
    p.showPerson();
}
//2.参数模板化
template<typename T1, typename T2>
void dowork2(person<T1, T2>& p)
{
    p.showPerson();
}
//3.整个类模版化
template<typename T>
void dowork3(T& p)
{
    p.showPerson();
}

void test01()
{
    person<string,int>p("Tom",20);
    dowork(p);
    dowork2(p);
    dowork3(p);//p所有属性已经被完全指定
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}