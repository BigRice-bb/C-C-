#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"
#include "mystring.h"

void test01()
{
    mystring t1("abcdefg");
    mystring t2(t1);
    t1.m_show();
    int t1size=t1.m_getsize();
    t2.m_show();
    int t2size=t2.m_getsize();
    //直接输出t1,需要重载<<运算符。
    cout<<t1<<endl;

    //cin>>输入
    cout<<"请重新给t1赋值"<<endl;
    cin>>t1;//需要重载>>操作符，
    cout<<"str新值为:"<<t1<<endl;
}

void test02()
{
    mystring str1="abc";
    mystring str2="";
    str2=str1;//这里进行了浅拷贝//在析构时会重复释放同一片内存出错
    //进行=的重载。=重载要在类内进行
    str1.m_show();
    str2.m_show();
    str2="aa";//直接传递字符串给str2赋值，需要先清空堆区内存，否则存在内存泄漏问题
    str2.m_show();
    cout<<str2[1]<<endl;//这里应该输出a第二个字符，但是需要对[]进行重载，类内重载
    str2[1]='b';//这里需要对[]进行重载，使其成为可被修改的左值
    cout<<str2[1]<<endl;
}

void test03()
{
    mystring str1="abc";
    mystring str2="def";
    mystring str3=str1+str2;//完成字符串的拼接,需要对+进行重载
    str3.m_show();
    mystring str4=str3+"";//重载+运算符
    str4.m_show();

    if(str3 == str4)//对==进行重载，
    {
        cout<<"两字符串相同"<<endl;
    }
    else 
    {
        cout<<"两字符串不同"<<endl;
    }

}

int main()
{
    test03();
    //test02();
    system("pause");
    return EXIT_SUCCESS;
}