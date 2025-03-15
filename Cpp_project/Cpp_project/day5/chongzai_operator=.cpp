#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

//编译器默认会给一个类添加4个函数
//默认构造函数  析构函数  拷贝函数（浅拷贝，值拷贝）  operator=
class person
{
public:
    //person(){}
    person(int age,char* name)
    {
        m_age=age;
        m_name=new char[strlen(name)+1];
        strcpy(m_name,name);
    }
    //浅拷贝
    // person& operator=(const person &p)
    // {
    //     m_age=p.m_age;
    //     m_name=p.m_name;
    //     return *this;
    // }
    //深拷贝
    // person& operator=(const person &p)
    // {
    //     if(this->m_name != NULL)
    //     {
    //         delete [] this->m_name;
    //         this->m_name=NULL;
    //     }
    //     this->m_name=new char[strlen(p.m_name)+1];
    //     strcpy(this->m_name,p.m_name);
    //     this->m_age=p.m_age;
    //     return *this ;
    // }
    char* m_name;
    int m_age;
    ~person()
    {
        if(m_name)
        {
            delete  [] m_name;//字符串和数组delete时加[]
            m_name=NULL;
        }
        cout<<"析构函数调用"<<endl;
    }
    void print()
    {
        cout<<this->m_age<<" "<<this->m_name<<endl;
    }
    //利用拷贝构造进行p4=p3的操作
    person(const person& p)
    {
        this->m_name=new char[strlen(p.m_name)+1];
        strcpy(this->m_name,p.m_name);
        this->m_age=p.m_age;
    }
};

void test01()
{
    person p1(24,"Burger");
    // person p2(18,"Tom");
    // p2=p1;//要完成这个赋值操作需要对=进行重载
    // p2.print();
    // person p3(0," ");
    // p3=p2=p1;//完成连等操作需要重载=
    // p3.print();
    person p4=p1;
    p4.print();
}
//链式编程a=b=c
void test02()
{
    // int a=10,b=20;
    // int c;
    // c=a=b;
    // cout<<c<<a<<b<<endl;

}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}