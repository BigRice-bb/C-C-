#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class person
{
public:
    int m_age;
    void show_class()
    {
        cout<<"class name is person."<<endl;
    }
    void show_age()
    {
        if(this==NULL)
        {
            return;
        }
        m_age=0;//空指针访问不了成员变量，
        cout<<m_age<<endl;
    }
};

void test01()
{
    person *p=NULL;
    p->show_age();
    p->show_class(); 
}

int main()
{
    test01();
    system ("pause");
    return EXIT_SUCCESS;
}