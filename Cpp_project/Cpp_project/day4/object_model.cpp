#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class person
{
    public:
        int m_a;
        void func()
        {}
        static int m_b;
        double m_c;//存在内存对齐，故double为8字节，int为4字节，最后输出为16字节
        
};

void test01()
{
    person p1;
    cout<<sizeof(p1)<<endl;//空类地址空间为1,原因：每个对象都应该在内存上有独一无二的地址，因此给空类分配1字节空间
    //1.空对象大小为1
    //2.非空之后，就是成员变量的空间
    //3.类成员函数和成员变量分开存储，成员函数空间不会归到sizeof中
    //4.静态成员变量和静态成员函数也都不属于类对象
    //5.只有非静态的成员变量属于类对象地址空间
}

int main()
{
    test01();
    system ("pause");
    return EXIT_SUCCESS;
}