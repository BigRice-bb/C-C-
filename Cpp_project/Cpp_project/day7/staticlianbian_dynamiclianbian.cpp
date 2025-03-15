//静态联编和动态联编
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//动态多态的条件
//有继承关系
//父类中有虚函数，子类中又对该函数的重写
//父类的指针或引用指向的是子类的对象
class animal
{
public:
    virtual void speak()//普通成员函数不分配内存
    {
        cout<<"动物在说话"<<endl;
    }
    virtual void eat()//普通成员函数不分配内存
    {
        cout<<"动物在吃饭"<<endl;
    }
};
class cat:public animal
{
public:
    void speak()
    {
        cout<<"小猫在说话"<<endl;
    }
    void eat()
    {
        cout<<"小猫在吃饭"<<endl;
    }
};
class dog:public animal
{
public:
    void speak()
    {
        cout<<"小狗在说话"<<endl;
    }
};

void dospeak(animal &animal)//父类的引用接受子类的传参可以
{
    animal.speak();//地址在函数定义时就绑定好，属于静态联编
}
void test01()
{
    cat c1;
    dospeak(c1);//是动物说话111，还是小猫说话呢
    //如果想调用小猫说话，函数的地址绑定需在程序运行时绑定
    //属于晚地址绑定，也是动态联编
    //在类中函数头部加入关键字virtual 虚函数
    dog g1;
    dospeak(g1);//由于父类的多态，直接调用dog类的函数

}

void test02()
{
    cout<<sizeof(animal)<<endl;//不加virtual 结果为1，空类
    //若animal中的成员函数加virtual 则输出8
    animal *animal=new cat;//创建animal指针接受cat对象没有问题
    animal->speak();//调用speak函数，由于animal中的speak为virtual虚函数
    //cat中对speak进行了重写，vftable中的函数入口被覆盖为cat中的speak入口
    //((void(*)() )(*((int*)*(int *)animal+1)))();//函数指针,调用
}
int main()
{
    //test01();
    test02();
    return EXIT_SUCCESS;
}