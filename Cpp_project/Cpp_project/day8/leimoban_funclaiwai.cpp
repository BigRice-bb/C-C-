//类模版中成员函数的类外实现
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//创建类模版
template<class T1,class T2>
class person
{
public:
    //类内实现
    person(T1 name,T2 age);
    // {
    //     this->m_name=name;
    //     this->m_age=age;
    // }
    void showPerson();
    // {
    //     cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
    // }
    T1 m_name;
    T2 m_age;
};
//类外实现也必须加上模版参数列表，不然编译器不认
template<class T1,class T2>
person<T1,T2>::person(T1 name,T2 age)
{
    this->m_name=name;
    this->m_age=age;
}
template<class T1,class T2>
void person<T1,T2>::showPerson()
{
    cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
}


void test01()
{
    person <string,int> p("Tom",20);
    p.showPerson();
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}