//调制饮品
//咖啡-烧水-冲咖啡-加牛奶-搅拌
//泡茶-烧水-泡茶-加蜂蜜-沏茶
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class makedrink
{
public:
    virtual void startstep()=0;
    virtual void nextstep()=0;
    virtual void addfood()=0;
    virtual void laststep()=0;
    void make()
    {
        startstep();
        nextstep();
        addfood();
        laststep();
    }
};
class makecoffee:public makedrink
{
public:
    void startstep()
    {
        cout<<"第一步--烧水"<<endl;
    }
    void nextstep()
    {
        cout<<"第二步--冲咖啡"<<endl;
    }
    void addfood()
    {
        cout<<"第三步--加牛奶"<<endl;
    }
    void laststep()
    {
        cout<<"第四步--搅拌"<<endl;
    }
};

class maketee:public makedrink
{
public:
    void startstep()
    {
        cout<<"第一步--烧水"<<endl;
    }
    void nextstep()
    {
        cout<<"第二步--冲茶"<<endl;
    }
    void addfood()
    {
        cout<<"第三步--加蜂蜜"<<endl;
    }
    void laststep()
    {
        cout<<"第四步--沏茶"<<endl;
    }
};

void dobussiness(makedrink *kind)
{
    kind->make();
    delete kind;
}


void test01()
{
    dobussiness(new makecoffee);
    dobussiness(new maketee);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}

