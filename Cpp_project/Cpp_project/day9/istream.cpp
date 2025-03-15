#include <iostream>
using namespace std;

void test01()
{//as 第一次a 第二次s 第三次换行 第四次等待输入
    char c=cin.get();
    cout<<"c="<<c<<endl;
    c=cin.get();
    cout<<"c="<<c<<endl;
    c=cin.get();
    cout<<"c="<<c<<endl;
    c=cin.get();
    cout<<"c="<<c<<endl;
}
void test02()
{
    //cin.get()读字符串
    //最后的回车换行符会遗留在缓存区
    char buf[1024];
    cin.get(buf,1024);
    char c=cin.get();
    if(c=='\n')
    {
        cout<<"换行符遗留"<<endl;
    }

    cout<<buf<<endl;
}

void test03()
{//cin.getline()获取字符串,换行符不会被取走,也不在缓存区,直接扔掉
    char buf[1024];
    cin.getline(buf,1024);
    char c=cin.get();
    if(c=='\n')
    {
        cout<<"换行符遗留"<<endl;
    }
    else{
        cout<<"换行符meiyou遗留"<<endl;
    }
    cout<<buf<<endl;
}
void test04()
{
    cin.ignore(2);//参数为几,就会忽略几个
    char c=cin.get();
    //cout<<"c="<<c<<endl;//输入as,输出s
    cout<<"c="<<c<<endl;
}
void test05()
{//输入as
    char c=cin.peek();//从缓存区偷看第一个字符,但不拿走,不移动指针
    cout<<"c="<<c<<endl;//a
    c=cin.get();
    cout<<"c="<<c<<endl;//a
    c=cin.get();    
    cout<<"c="<<c<<endl;//s
}
void test06()
{
    //cin.putback()
    char c=cin.get();
    cout<<"c="<<c<<endl;
    cin.putback(c);//放回到原位
    c=cin.get();
    cout<<"c="<<c<<endl;
}
//案例1:判断用户输入内容是字符串还是数字 并输出
void example01()
{
    //char buf[128];
    char c=cin.peek();
    //cin.getline(buf,1024);
    if(c>='0'&&c<='9')
    {
        char num[128];
        cin.get(num,128);
        cout<<"为数字:   "<<num<<endl;
    }
    else
    {
        char str[128];
        cin.get(str,128);
        cout<<"为字母:   "<<str<<endl;
    }

}
//案例二:要求用户输入0-10的数字,输入有误重新输入
void example02()
{
    int num;
    int flag;
    while(1)
    {
        cout<<"请输入一个0-10的数字:";  
        cin>>num;
        flag=cin.fail();
        if(flag==1)
        {
            cin.clear();
            cin.sync();
            cin.ignore();
            continue;
        }
        if(num>0 && num<10)
        {
            cout<<"输入正确: "<<num<<endl;
            break;
        }


        flag=cin.fail();
        
    }

}

int main() {
    //test06();
    example02();
    system("pause");
    return EXIT_SUCCESS;
}