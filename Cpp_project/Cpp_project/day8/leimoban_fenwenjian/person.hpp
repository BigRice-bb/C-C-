#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//头文件只管声明
//类模版的声明
template <class T1,class T2>
class person
{
public:
    person(T1 name,T2 age);
    void showPerson();
    T1 m_name;
    T2 m_age;
};

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