#include <iostream>
using namespace std;

//定义自己的异常基抽象类
class base_myexception
{
public:
    virtual void type_error()=0;//纯虚函数构建抽象类
};
class null_pointer:public base_myexception
{
public:
    virtual void type_error()//对父类纯虚函数进行重写
    {
        cout<<"空指针异常..."<<endl;
    }
};
class other_error:public base_myexception
{
public:
    virtual void type_error()//对父类纯虚函数进行重写
    {
        cout<<"其他异常..."<<endl;
    } 
};

void dowork()
{
    throw null_pointer();//抛出某种类型的异常
}
void test01()
{
    try
    {
        dowork();
    }
    catch( base_myexception & e)//父类引用接收子类指针,构成多态
    {
        e.type_error();
    }
    
}

int main() {
    test01();
    system("pause");
    return EXIT_SUCCESS;
}