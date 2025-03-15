//虚析构和纯虚析构
//虚析构--子类有存在堆区的数据，父类需要利用虚析构技术让子类正确释放
//含有纯虚析构的类，也属于抽象类，无法实例化对象
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

class animal
{
public:
    animal()
    {
        cout<<"animal的构造函数调用"<<endl;
    }
    virtual void speak()
    {
        cout<<"动物在说话"<<endl;
    }
    //如果子类中有在堆区的属性，父类的析构需要为虚析构，子类才可正确释放堆区内存
    // virtual ~animal()
    // {
    //     cout<<"animal的析构函数调用"<<endl;
    // }
    //纯虚析构-需要有申明，也需要有实现，类外实现
    virtual ~animal()=0;
};
animal::~animal()
{
    cout<<"animal的纯虚析构函数调用"<<endl;
}

class cat:public animal
{
public:
    virtual void speak()//这里子类的virtual可以省略
    {
        cout<<"小猫在说话"<<endl;
    }
    cat(char* name)//进行深拷贝给类内属性初始化
    {
        cout<<"cat有参构造调用"<<endl;
        this->m_name=new char[strlen(name)+1];
        strcpy(this->m_name,name);
    }
    ~cat()
    {
        cout<<"cat析构函数调用"<<endl;
        if(this->m_name!=NULL)
        {
            delete [] this->m_name;
            this->m_name=NULL;
        }
    }
    char* m_name;//cat`s name
};

void test01()
{
    animal *animal1=new cat("Tom");
    animal1->speak();
    //若将animal的析构函数改为虚析构，则cat会调用析构函数释放
    delete animal1;//不会有cat的析构函数调用
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}