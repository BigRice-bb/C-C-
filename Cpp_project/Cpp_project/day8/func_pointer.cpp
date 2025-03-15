#include <iostream>
using namespace std;

//创建一个打印整数的函数，这个整数需要通过另一个函数获取
//首先创建函数指针
typedef void (*myfunc)(int);
//定义一个获取整数的函数
void getNum(int num)
{
    cout<<"num="<<num<<endl;
}
//获取整数的函数
void printnum(myfunc getNum,int num)
{
    getNum(num);
}

void test01()
{
    printnum(getNum,100);
}
int main() {
    // Your code here
    test01();
    return 0;
}