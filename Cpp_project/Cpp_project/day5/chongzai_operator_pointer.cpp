#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class person
{
public:
    person(int age)
    {
        cout<<"构造函数调用"<<endl;
        this->m_age=age;
    }

    int m_age;

    void showage()
    {
        cout<<this->m_age<<endl;
    }
    ~person()
    {
        cout<<"析构函数调用"<<endl;
    }
};

class smartpoint
{
public:
    smartpoint(person *p)
    {
        this->m_person=p;
    }
    person * operator->()//重载->运算符
    {
        return this->m_person;
    }

    person& operator*()//重载*运算符
    {
        return *(this->m_person);
    }

    ~smartpoint()
    {
        if(this->m_person)
        {
            delete this->m_person;
            this->m_person=NULL;
        }
    }
private:
    person *m_person;
};

void test01()
{
    smartpoint sp(new person(24));
    //下行应为sp->->showage();编译器优化了
    sp->showage();//需要在smartpoint中重载指针运算符
    (*sp).showage();//需要重载一下*运算符
//     person *p=new person(24);//堆区创建新的对象
//     p->showage();
//     delete p;//堆区数据需要手动释放
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}