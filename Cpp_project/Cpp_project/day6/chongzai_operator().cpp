#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

class myprint
{
public:
    void operator()(string text)
    {
        cout<<text<<endl;
    }
};

void myprint2(string text)
{
    cout<<text<<endl;
}

class myadd
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};

void test01()
{
    myprint hp;
    hp("qqqqqq");//仿函数，本质是一个对象 函数对象

    myprint2("pppppp");//普通函数
}

void test02()
{
    myadd cp;
    int result=cp(6,6);
    cout<<result<<endl;
    cout<<myadd()(2,6)<<endl;//匿名函数对象，当前行执行完，立即释放对象空间
}
int main()
{
    //test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
}