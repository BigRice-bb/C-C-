#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class animal
{
public:
    int m_age;
};

class sheep:virtual public animal//虚继承，只有一份数据
{

};
//vbptr 虚基类指针 指向一个vbtable 虚基类表
//虚基类表中记录了偏移量，通过偏移量找到唯一m_age
class tuo:virtual public animal//实际继承的为一个偏移量指针，指向同一个m_age
{

};
class yangtuo:public sheep,public tuo
{

};
//利用虚继承，每个对象只会有一个年龄m_age，都继承与动物animal
void test01()
{
    yangtuo y1;
    //加上作用域可以解决不明确问题
    y1.m_age=10;//来自两个父类，不明确
}
//虚基类工作逻辑解释
void test02()
{
    yangtuo y2;
    y2.m_age=20;

    cout<<*((int*)*(int *)&y2+1)<<endl; //(int* 指明数据步长为4byte)，*解引用到vbtable

}
int main()
{
    test02();
    return EXIT_SUCCESS;
}