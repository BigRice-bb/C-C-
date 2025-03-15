
#include <iostream>
using namespace std;
#include<iomanip>

//1.通过流成员函数格式化输出
void test01()
{
    int num=99;
    cout.width(20);//指定宽度为20
    cout.fill('*');//填充空位置
    cout.setf(ios::left);//输出向左对齐
    cout.unsetf(ios::dec);//卸载十进制的配置
    cout.setf(ios::hex);//安装十六进制的配置--99-63
    cout.setf(ios::showbase);//显示基数
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);
    cout<<num<<endl;//常规输出
}
//2.使用控制符格式化输出 #include<iomanip>
void test02()
{
    int num=99;
    cout<<setw(20)
        <<setfill('*')
        <<setiosflags(ios::showbase)
        <<setiosflags(ios::left)
        <<hex
        <<num<<endl;
}
int main() {
    test02();
    system("pause");
    return EXIT_SUCCESS;
}