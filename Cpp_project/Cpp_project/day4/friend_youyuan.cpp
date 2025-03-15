#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

//1.全局函数作为友元
class home
{
    //利用friend关键字让可以访问私有成员
    friend void bestfriend(home &home);
public:
    home()
    {
        this->m_sittingroom="客厅";
        this->m_bedingroom="卧室";
    }
    string m_sittingroom;
private:
    string m_bedingroom;
};

//好朋友的全局函数可以访问private属性
//全局函数作为友元
void bestfriend(home &home)
{
    cout<<"好朋友在访问"<<home.m_sittingroom<<endl;
    cout<<"好朋友在访问"<<home.m_bedingroom<<endl;
}


//2.类作为友元类
class build
{
    //加上友元类即可访问PRIVATE成员
    friend class goodgay;
public:
    build()
    {
        cout<<"build构造函数调用"<<endl;
        m_sittingroom="客厅";
        m_bedingroom="卧室";
    }
    string m_sittingroom;
private:
    string m_bedingroom;
};

class goodgay
{
public:
    goodgay()
    {
        cout<<"goodgay构造函数调用"<<endl;
        m_build=new build;
    }
    void visit();
    build * m_build;

};

void goodgay::visit()
{
    //不加友元无法访问build类的private成员
    cout<<"好朋友在访问"<<m_build->m_bedingroom<<endl;
    cout<<"好朋友在访问"<<m_build->m_sittingroom<<endl;
}

void test01()
{
    goodgay gg;
    gg.visit();
}


class building;
class bestgay
{
    public:
    bestgay();
    //building *m_building=new building;
    building *m_building;
    void visit();
    void can_visit();
};

class building
{
    friend void bestgay::can_visit();
public:
    building();
    string m_sittingroom;
private:
    string m_bedingroom;
};
//3.类中的成员函数作为友元
    //building *m_building=new building;
bestgay::bestgay()
    {
        this->m_building=new building ;
    }
void bestgay::visit()
    {
        //cout<<"好朋友在访问"<<m_building->m_bedingroom<<endl;
        cout<<"好朋友在访问"<<m_building->m_sittingroom<<endl;
    }
void bestgay::can_visit()
    {
        cout<<"好朋友在访问"<<m_building->m_bedingroom<<endl;
        cout<<"好朋友在访问"<<m_building->m_sittingroom<<endl;
    }


building::building()
    {
        cout<<"building构造函数调用"<<endl;
        m_sittingroom="客厅";
        m_bedingroom="卧室";
    }

void test02()
{
    building building;
    bestgay mm;
    mm.visit();
    mm.can_visit();
}
int main()
{
    test02();
    system("pause");
    return EXIT_SUCCESS;
}