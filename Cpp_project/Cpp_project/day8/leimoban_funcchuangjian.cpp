//问题描述：在类模版中定义函数时，并不知道类模版的数据类型
//所以类模版中的函数的创建时机是一个需要注意的问题

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class person1
{
public:
    void showPerson1()
    {
        cout<<"person1 show"<<endl;
    }
};
class person2
{
public:
    void showPerson2()
    {
        cout<<"person2 show"<<endl;
    }
};
template<class T>
class myclass
{
public:
    void func1()
    {
        p.showPerson1();
    }
    void func2()
    {
        p.showPerson2();
    }
    T p;//并不确定p的类型，所以类内函数尚不明确无法定义
};


void test01()
{
    myclass<person1> m;//实例化模版类对象时，才会根据p的类型创建函数
    m.func1();
    //m.func2();//error
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}