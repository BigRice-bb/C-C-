#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class person
{
    friend ostream& operator<<(ostream &cout,person &p);
public:
    person(int a,int b):m_a(a),m_b(b){}
private:
    int m_a;
    int m_b;
};

//利用全局函数实现左移运算符重载
ostream& operator<<(ostream &cout,person &p)//通过友元函数访问类私有成员
{
    cout<<p.m_a<<" "<<p.m_b;
    return cout;
}

void test01()
{
    person p(10,20);
    cout<<p<<endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}