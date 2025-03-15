#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class base1
{
public:
    base1()
    {
        this->m_a=10;
    }
    int m_a;
};

class base2
{
public:
    base2()
    {
        this->m_b=10;
    }
    int m_b;
};

class son:public base1,public base2
{
public:
    int m_c;
    int m_d;
};

void test01()
{
    son s1;
    cout<<s1.m_a<<s1.m_b<<endl;

}
int main()
{
    test01();
    return EXIT_SUCCESS;
}