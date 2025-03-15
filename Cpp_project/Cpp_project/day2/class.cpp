#include <iostream>
using namespace std;

const double PI=3.14;

class circle 
{
    public:
        int m_r;//成员变量/属性
        double cal_zc()//成员函数
        {
            return 2*PI*m_r;
        }
};
class student
{
    public:

    string name;
    string id_number;
    void setname(string name1)
    {
        name=name1;
    }
    void setid_number(string id)
    {
        id_number=id;
    }
    void show()
    {
        cout<<name<<endl;
        cout<<id_number<<endl;
    }
};
void test02()
{
    student s1;
    s1.setname("王波");
    s1.setid_number("202422280823");
    s1.show();
}

void test01()
{
    circle c1;
    c1.m_r=10;
    double zc=c1.cal_zc();
    cout<<"圆的周长为："<<zc<<endl;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
} 