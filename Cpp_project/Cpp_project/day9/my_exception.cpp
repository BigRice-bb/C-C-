//重写系统异常类exception
#include <iostream>
using namespace std;
#include <stdexcept>//系统标准异常的头文件

class myOutofrange:public exception
{
public:
    //构造函数,传递异常原因
    myOutofrange(string str)
    {
        this->m_error=str;
    }
    virtual const char* what() const noexcept
    //const代表该函数不会修改对象成员的值
    //noexception代表该函数不会抛出异常
    {
        return m_error.c_str();
        //string 不可以隐式转换为const char*
        //const char*可以隐式类型转换为string
    }
    string m_error;

};

void dowork()
{
    throw myOutofrange("aaaaaa异常....");
}
void test01()
{
    try
    {
        dowork();
    }
    catch(exception & e)
    {
        cout << e.what() << '\n';
    }
    
    
}
int main() {
    test01();
    system("pause");
    return EXIT_SUCCESS;
}