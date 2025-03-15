#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;


class person
{
public:
//1.静态成员变量
//静态成员变量，在编译阶段就分配内存
    static int m_a;//只定义，为分配内存
    int m_c;
//2.静态成员函数
    static void func01()
    {
        m_a=10000;//静态成员函数可以访问静态成员变量
       //_c=100;静态成员函数bu不可以访问动态成员变量
        cout<<"func调用"<<endl;
    }

private:
    static int m_b;//私有权限类外不可以直接访问
    static void func02()
    //无论是成员变量还是函数，只要作用域是私有的，类外就不可以直接访问
    {
        cout<<"func02调用"<<endl;
    }


};
//person::m_b;

int person::m_a=0;//为静态成员变量初定义，分配内存。。后面的所有对象都是只这个内存，这个变量

void test01()
{
    //1.通过对象进行访问
    person p1;
    cout<<p1.m_a<<endl;    
    
    person p2;
    p2.m_a=100;
    cout<<p1.m_a<<endl;

    //2..通过类名直接访问
    person::m_a=1000;
    cout<<person::m_a<<endl;

    person::func01();
}
void test02()
{
    person p1;
    p1.func01();
    cout<<p1.m_a<<endl;
    //person::func02();
}


int main()
{
    test01();
    test02();
    system ("pause");
    return EXIT_SUCCESS;
}
