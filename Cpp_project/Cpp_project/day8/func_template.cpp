//template模板 
//1.模版可以自动类型推导，通用数据类型T实现，template<typename T>
//2.给定模版指定的类型，省去模版验证参数的过程
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//整形的交换函数
void int_swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//浮点型的交换函数
void float_swap(float &a,float &b)
{
    float temp=a;
    a=b;
    b=temp;
}
//只有数据类型不同，其他逻辑相同的函数，可以利用函数模板来实现
template<typename T>//T代表一个通用数据类型，告诉编译器后面代码中T是一个数据类型
//模版的自动类型推导
//函数模板
void my_swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<typename T>
//void my_swap2(){};
//模版不能单独使用，必须指定出T才可以使用
//模版使用必须指定T，并紧接着定义模版函数
void my_swap2()
{
    T a;//T的类型不确定，无法分配内存
}

void test01()
{
    int a=10;
    int b=20;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    my_swap(a,b);//自动类型推导。只有数据类型一致时才可以继续运行
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    float c=1.1;
    float d=2.2;
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;
    my_swap<float>(c,d);//为函数模版指定数据类型
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;
}
// void test02()
// {
//     my_swap2<int>();
// }
int main()
{
    test01();
    return EXIT_SUCCESS;
}