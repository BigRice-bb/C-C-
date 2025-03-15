#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class myinter
{
    friend ostream & operator<<(ostream &cout,const myinter &inter);
public:
    myinter()
    {
        m_num=0;
    }
    
//前置++重载//返回引用，一直对同一块地址空间操作
    myinter& operator++()
    {
        this->m_num+=1;
        return *this;
    }
//后置++//返回的是值，不能进行链式了
    myinter operator++(int)
    {
        //先记录初始状态
        myinter t;
        t.m_num=this->m_num;
        this->m_num++;
        return t;
    }
private:
    int m_num;
};

//<<重载，让cout可以直接输出类
ostream & operator<<(ostream &cout,const myinter &inter)
{
    cout<<inter.m_num;
    return cout;
}

// void test01()
// {
//     myinter inter;
//     cout<<++inter<<endl;
// }

void test02()
{
    myinter inter1;
    cout<<(inter1++)<<endl;
    cout<<inter1<<endl;
}

int main()
{
    test02();
    system("pause");
    return EXIT_SUCCESS;
}