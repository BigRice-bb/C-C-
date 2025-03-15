#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class base
{
public:
    static int m_a; 
    static void func()//静态成员函数只可访问静态成员变量
    {
        cout<<"父类静态成员函数调用"<<endl;
        cout<<m_a;
    }
};

int base::m_a=10;//静态成员类外初始化

class son:public base
{
public:
    static int m_a;
    static void func()
    {
        cout<<"子类静态成员函数调用"<<endl;
        cout<<m_a<<endl;
        cout<<base::m_a<<endl;
    }
};
int son::m_a=20;//子类中的同名静态成员

void test01()
{
    //静态成员通过对象访问
    son s1;
    cout<<s1.m_a<<endl;//直接输出就近原则，会输出子类的m_a
    cout<<s1.base::m_a<<endl;//加上作用域输出父类的m_a
    //通过类名访问
    cout<<son::m_a<<endl;//静态成员特性，可以直接输出
    cout<<son::base::m_a<<endl;//静态成员特性，可以直接输出

    //直接通过类名访问
    son::func();
    son::base::func();
    //若子类重定义了父类中的成员函数，则父类中的所有重载版本就会被隐藏掉，必须加入作用域才可以访问
    
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}