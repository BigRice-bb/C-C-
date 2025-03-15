#include <iostream>
using namespace std;

//定义自己的异常类
class myexpection
{
public:
    myexpection()
    {
        cout<<"默认构造函数调用"<<endl;
    }
    void printerror()
    {
        cout<<"我自己的异常"<<endl;
    }
    // myexpection(myexpection &e)
    // {
    //     cout<<"拷贝构造函数调用"<<endl;
    // }
    ~myexpection()
    {
        cout<<"析构函数调用"<<endl;
    }
};

void test01()
{
    
    //throw myexpection();//匿名对象抛出异常数据类型
    //用指针接收就必须抛出实际对象
    // myexpection e;
    // throw  &e;
    throw  myexpection();
    
}

int main() {
    try
    {
        test01();
    }
    //抛出throw myexception();catch(myexception e)会调用拷贝构造函数,效率降低
    //直接用引用接收,效率高
    catch(myexpection e)
    //catch (myexpection *e) //throw的myexception会被提前释放,不能再进行操作
    {
        e.printerror();
        //delete e;
    }
    
    
    system("pause");
    return EXIT_SUCCESS;
}