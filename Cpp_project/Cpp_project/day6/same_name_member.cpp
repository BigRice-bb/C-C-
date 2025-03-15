#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class base
{
public:
    base()
    {
        this->m_a=10;
    }
    int m_a;
    void func()
    {
        cout<<"父类func调用"<<endl;
    }
    void func(int a)
    {
        cout<<"父类中的有参函数成员调用"<<endl;
    }
};

//子类与父类同名的成员，访问会优先选择子类中的成员，
//若想要访问父类中继承的成员，需要加上父类的作用域
class son:public base
{
public:
    son()
    {
        this->m_a=20;
    }
    int m_a;
    void func()
    {
        cout<<"子类func调用"<<endl;
    }
};
//若子类中重定义了父类的成员函数--重载，则父类中的所有重载版本会被隐藏，若想调用父类中的重载版本需要加作用域！！
void test01()
{
    son s1;
    cout<<s1.m_a<<endl;
    cout<<s1.base::m_a<<endl;
    
}
void test02()
{
    son s2;
    s2.func();
    s2.base::func();    
    //s2.func(10);
    s2.base::func(10);
}

int main()
{
    test02();
    return EXIT_SUCCESS;
}