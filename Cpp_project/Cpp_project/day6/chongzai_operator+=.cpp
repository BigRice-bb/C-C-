#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class logic_unit
{
public:
    logic_unit(bool flag)
    {
        this->m_flag=flag;
    }
    bool m_flag;

    //重载函数+=  和  &&
    logic_unit& operator+=(logic_unit &unit)
    {
        this->m_flag=this->m_flag+unit.m_flag;
        return *this;
    }

    bool operator&&(logic_unit &unit)
    {
        //logic_unit u(0);
        if(this->m_flag && unit.m_flag==0)
            return 0;
        else 
            return 1;
    }
};

void test01()
{
    logic_unit u1(0);
    logic_unit u2(1);
    //u1+=u2;
    //cout<<u1.m_flag<<endl;
    if(u1&&(u1+=u2))
    {
        cout<<"结果错误"<<endl;
    }
    else 
        cout<<"结果正确"<<endl;
}

int main()
{
    test01();
    //test02();
    system("pause");
    return EXIT_SUCCESS;
}