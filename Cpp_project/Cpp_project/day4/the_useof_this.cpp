#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class person
{
    public:
        //int m_age;//m代表成员，代表成员属性
        int age;
        person(int age)
        {
            //m_age=age;
            this->age=age;
            //this指针指向被调用的成员函数 所属的对象
            //this指针用途1.解决名称冲突
            //2.this指针隐式的加在每个成员函数的参数列表中
        }
        bool compare_age(person &p)
        {
            if(this->age==p.age)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //若将此处返回的结果由引用改为返回值person，返回的就是拷贝构造函数构造的新的对象了，不会累加到p1上
        person&  addage(person &p)
        //返回引用，一直都是对p1操作，不会拷贝新的对象 
        {
            this->age+=p.age;
            return *this;
        }
};

void test01()
{
    person p1(10);
    cout<<p1.age<<endl;
    person p2(10);
    cout<<p2.compare_age(p1)<<endl;
    p1.addage(p2).addage(p2).addage(p2);//链式编程
    cout<<p1.age<<endl;
}

int main()
{
    test01();
    system("pause");//windows系统下的系统命令，显示press any key to continue
    return EXIT_SUCCESS;//代表成功返回，一般为0；
}