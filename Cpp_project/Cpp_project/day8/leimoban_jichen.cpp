#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//用类模版，创建父类
template<class T>
class Base
{
public:
    T m;
};
//创建子类继承父类--若直接继承会出现问题
// class Son:public Base
// {
// };
//1.必须指明出父类的T的类型，才能给子类分配内存，不然在创建子类对象时，无法分配内存
class Son:public Base<int>
{

};
//2.继续用模版定义子类，子类也可以定义模版类型
template<class T2,class T3>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout<<"T3的类型为："<<typeid(T3).name()<<endl;
    }
    T3 m2;
};

void test01()
{
    Son2 <int,string> s2;
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}