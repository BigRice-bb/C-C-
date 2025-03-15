#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

// class news
// {
// public:
//     void header()
//     {
//         cout<<"公共头部"<<endl;
//     }
//     void fotter()
//     {
//         cout<<"公共的底部"<<endl;
//     }
//     void leftlist()
//     {
//         cout<<"公共的左侧列表"<<endl;
//     }
//     void center()
//     {
//         cout<<"新闻播报内容"<<endl;
//     }
    
// };

// class sport
// {
//     public:
//     void header()
//     {
//         cout<<"公共头部"<<endl;
//     }
//     void fotter()
//     {
//         cout<<"公共的底部"<<endl;
//     }
//     void leftlist()
//     {
//         cout<<"公共的左侧列表"<<endl;
//     }
//     void center()
//     {
//         cout<<"体育播报内容"<<endl;
//     }
// };
//接下来利用继承来实现
class basepage
{
public:
    void header()
    {
        cout<<"公共头部"<<endl;
    }
    void fotter()
    {
        cout<<"公共的底部"<<endl;
    }
    void leftlist()
    {
        cout<<"公共的左侧列表"<<endl;
    }
};
class news: public basepage
{
public:
    void center()
    {
        cout<<"新闻播报内容"<<endl;
    }
};
class sport: public basepage
{
public:
    void center()
    {
        cout<<"体育播报内容"<<endl;
    }
};

void test01()
{
    news new1;
    cout<<"新闻播报内容如下："<<endl;
    new1.header();
    new1.center();
    new1.fotter();
    new1.leftlist();

    sport sp;
    cout<<"体育播报内容如下："<<endl;
    sp.header();
    sp.center();
    sp.fotter();
    sp.leftlist();
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}