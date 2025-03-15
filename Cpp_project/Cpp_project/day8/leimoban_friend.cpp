#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T1,class T2>
class person;

template<class T1,class T2>
void showPerson2(person<T1,T2> &p);

//可以直接函数模版一块实现
template<class T1,class T2>
void showPerson3(person<T1,T2> &p)
{
    cout<<"name:"<<p.m_name<<" age:"<<p.m_age<<endl;
}

template<class T1,class T2>
class person
{
//1.友元函数类内实现
friend void showPerson(person &p)
{
    cout<<"name:"<<p.m_name<<" age:"<<p.m_age<<endl;
}
//2.友元函数类外实现--函数模板类外实现.
//先声明函数，最开始先申明类模板
//注意加<>,告诉编译器这是一个模版函数
friend void showPerson2<>(person<T1,T2> &p);

//3.友元函数类外实现
friend void showPerson3<>(person<T1,T2> &p);

public:
    person(T1 name, T2 age):m_name(name),m_age(age){};
private:
    T1 m_name;
    T2 m_age;
};

//2.友元函数类外实现--函数模板类外实现
template<class T1,class T2>
void showPerson2(person<T1,T2> &p)
{
    cout<<"name:"<<p.m_name<<" age:"<<p.m_age<<endl;
}

void test01()
{
    person<string,int> p("Tom",20);
    showPerson3(p);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}