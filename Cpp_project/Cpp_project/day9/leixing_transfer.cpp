#include <iostream>
using namespace std;

//1.静态类型转换static_cast
void test01()
{
    char a='a';
    cout<<sizeof(a)<<endl;//1byte
    double b=static_cast<double>(a);
    cout<<sizeof(b)<<endl;//8byte
}
class base{
    virtual void func(){
        
    }

};
class son:public base{
    virtual void func(){
        
    }
};
class other{

};
void test02()
{
    base *base1=NULL;
    son* son1=NULL;
    //父转子
    son* son2=static_cast<son*>(base1);
    //子转父
    base* base2=static_cast<base*>(son1);
    //不同类间转换--不可以实现
    //other * other1=static_cast<other*>(son1);

    base base3;
    base & base4=base3;
    son son3;
    son& son4=son3;
    //只可以实现指针和引用的数据类型转换
    //son3=static_cast<son>(base3);
}
//dynamic_cast
void test03()
{
    //不可以进行内置数据类型转换
    //可完成类子转父的指针和引用转换
    //若想完成父转子,需要在创建父类指针或引用时指向子类类型
    //需要多态,即父类中有虚函数,子类中对其进行了重写
    son * son1;
    base* base1=new son;
    son* son2=dynamic_cast<son*>(base1);
}
int main() {
    
    test01();
    system("pause");
    return EXIT_SUCCESS;
}