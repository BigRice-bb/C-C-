#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

//关系运算符==
class person
{
public:
    person(char *name,int age):m_name(name),m_age(age){}
    char *m_name;
    int m_age;
    bool operator==(const person &p)
    {
        if(this->m_age==p.m_age && !strcmp(this->m_name,p.m_name))
        {
            return 1;
        }
        else 
            return 0;
    }
    bool operator!=(const person &p)
    {
        if(this->m_age==p.m_age && !strcmp(this->m_name,p.m_name))
        {
            return 0;
        }
        else 
            return 1;
    }
    ~person()
    {
        cout<<"析构函数调用"<<endl;
    }
};

void test01()
{
    person p1("burger",24);
    person p2("burger",18);
    if(p1==p2)
    {
        cout<<"p1和p2相同"<<endl;
    }
    else
    {
        cout<<"p1和p2不相同"<<endl;
    }
    if(p1!=p2)
    {
        cout<<"p1和p2不相同"<<endl;
    }
    else
    {
        cout<<"p1和p2相同"<<endl;
    }
}


int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}