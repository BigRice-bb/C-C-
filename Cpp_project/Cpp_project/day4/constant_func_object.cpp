#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class person
{
public:
    person(int age)
    {
        this->m_age=age;
    }
    int m_age;
    //常函数，修饰成员函数中的this指针，让指针指向的值不可以被修改
    void show_person() const//代表常量m_age不可修改
    {
        //m_age=100;//m_age成员变量可以被修改
        //如何让showperson函数只读权限，不可以写
        //this指针的本质： person * const this
        // const  person * const this,则指针指向的值也不可以修改，即为常量
        //const限制指针的指向
        cout<<"age="<<m_age<<endl;
    }
    //常函数中有些特殊的成员变量依然想修改，加上mutable，可修改
    mutable int m_a;//mutable可变的，m_a变为可修改

    void func()  
    {
        cout<<"func调用"<<endl;
    }
};

void test01()
{
    //常对象，加关键字const
    const person p1(20);
    p1.show_person();
    p1.m_a=10;//mutable可以改动
    //p1.m_age=100;//一般成员不可变
    //p1.func();//常对象只能调用常函数
}

int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}