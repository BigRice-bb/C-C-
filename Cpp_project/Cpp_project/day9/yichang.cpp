//c++下异常处理机制,异常的基本处理语法
#include <iostream>
using namespace std;
//定义自己的异常类
class myexpection
{
public:
    void printerror()
    {
        cout<<"我自己的异常"<<endl;
    }

};


//定义除法函数
float mydivision(float a,float b)
{
    if(b==0)
    {
        throw myexpection();//匿名对象
        //throw 3.24;
        //throw 'a';//返回char数据类型的异常
        //throw  -1;//返回int类型的异常,不止-1,任何整数都可以
    }
    return a/b;
}

void test01()
{
    float a=10;
    float b=0;
    try
    {
        mydivision(a,b);
    }
    catch(int)//捕获int类型的异常
    {
        cout<<"int类型异常捕获"<<endl;
    }
    catch(char)
    {
        cout<<"char类型异常捕获"<<endl;
    }
    catch(myexpection e)
    {
        e.printerror();
        cout<<"char类型异常捕获"<<endl;
    }
    catch(...)
    {
        throw;//继续抛出异常,给下一级处理
        cout<<"其他类型异常捕获"<<endl;
    }
    
    
}
int main() {
    //异常的传递处理--最后仍然是test01中的异常处理函数进行处理
    try
    {
        test01();
    }
    catch(int)
    {
        cout<<"main int异常处理"<<endl;
    }
    catch(...)
    {
        cout<<"main 其他异常处理"<<endl;
    }
    system("pause");
    return EXIT_SUCCESS;
}