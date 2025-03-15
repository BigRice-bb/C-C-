#include "iostream"
using namespace std;


//int a; 1，c++比c语言增强了变量重定义检测
int a=10;

//2.c语言函数返回值不检查，实参个数不检查
int getrects(int w,int h)
{
    return w*h;
}

void test01()
{
    cout<<getrects(10,10)<<endl;
}
//3.类型转换检测增强char *p=(char *)malloc(64)
//4.c语言下结构体不可以有函数，结构体变量申明必须加struct关键字
  //c++结构体内部可以放函数，创建时也可以省区关键字
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}