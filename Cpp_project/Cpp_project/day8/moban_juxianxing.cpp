#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//下面模版实现比较函数
template<typename T>
bool compare(T &a,T &b)
{
    if(a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//person类是一个特殊数据类型，需要重载==操作符
class person
{
public:
    person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    string m_name;
    int m_age;
    //法1 对==操作符进行重载
    // bool operator==(person &p)
    // {
    //     if(this->m_name==p.m_name&&this->m_age==p.m_age)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};

//法2也可以使用具体化技术，对模版进行具体化定义
template<> bool compare(person &a,person &b)
{
    if(a.m_name==b.m_name&&a.m_age==b.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    person p1("Tom",12);
    person p2("Tom",10);    
    if(compare(p1,p2))
    {
        cout<<"p1==p2"<<endl;
    }
    else
    {
        cout<<"p1!=p2"<<endl;
    }
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}