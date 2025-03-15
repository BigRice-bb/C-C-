//电脑组装案例 cpu+显卡+内存

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class cpu
{
public:
    virtual void caculate()=0;
};
class videocard
{
public:
    virtual void display()=0;
};
class memory
{
public:
    virtual void storage()=0;
};

class computer 
{
public:
    computer(cpu* c,videocard* v,memory* m)
    {
        this->m_cpu=c;
        this->m_videocard=v;
        this->m_memory=m;
    }
    cpu* m_cpu;
    videocard* m_videocard;
    memory* m_memory;
    void work()
    {
        m_cpu->caculate();
        m_videocard->display();
        m_memory->storage();
    }
    ~computer()
    {
        cout<<"computer析构函数调用"<<endl;
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }
        if(m_videocard!=NULL)
        {
            delete m_videocard;
            m_videocard=NULL;
        }
        if(m_memory!=NULL)
        {
            delete m_memory;
            m_memory=NULL;
        }
    }
};

class intercpu:public cpu
{
public:
    void caculate()
    {
        cout<<"inter的CPU进行计算"<<endl;
    }
};

class intervideocard:public videocard
{
public:
    void display()
    {
        cout<<"inter的videocard进行显示"<<endl;
    }
};
class intermemory:public memory
{
public:
    void storage()
    {
        cout<<"inter的memory进行存储"<<endl;
    }
};


void test01()
{
    computer xiaoxin(new intercpu,new intervideocard,new intermemory);
    xiaoxin.work();
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}