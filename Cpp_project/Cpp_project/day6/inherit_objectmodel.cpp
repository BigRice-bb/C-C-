#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

class base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

class son1:public base//public继承，继承除private外的其他属性
{
public:
    int m_d;
};//继承后子类不可访问父类的私有属性，但是会继承下来，所以会占空间

void test01()
{
    cout<<"son1子类的大小为多少字节"<<sizeof(son1)<<endl;
}

int main()
{
    test01();
    return EXIT_SUCCESS;
}