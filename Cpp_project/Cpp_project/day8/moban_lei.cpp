#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class t,class t1,class t2=int>
class person
{
public:
    person(t high,t1 name,t2 age)
    {
        this->m_high=high;
        this->m_name=name;
        this->m_age=age;
    }
    t m_high;
    t1 m_name;
    t2 m_age;
};

void test01()
{
    //person p1("Tom",12);//类模版不可以进行自动类型识别
    person< int,string> p1(10,"Tom",12);//类模版实例化,需要知道数据类型
    cout<<p1.m_name<<endl;
    cout<<p1.m_age<<endl;
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}