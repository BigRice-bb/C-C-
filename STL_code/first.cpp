#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void test01()
{
    //普通指针迭代器
    int arr[] = { 1, 2, 3, 4, 5 };
    int* p = arr; //指向数组首元素的指针
    for (int i = 0; i < 5; i++)
    {
        cout<<*(p+i)<<endl;
    } 
}
void myprint(int val)
{
    cout<<val<<endl;
}
//函数对象迭代器
void test02()
{
    vector<int> v;//创建一个空的vector容器  类比数组
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    //使用迭代器遍历vector容器
    //起始迭代器,指向容器中第一个数据
    //第一种写法
    // vector<int>::iterator itbegin = v.begin();
    // //结束迭代器,指向容器中最后一个元素的下一个位置
    // vector<int>::iterator itend = v.end();
    // //迭代器遍历容器数据
    // while (itbegin != itend)
    // {
    //     cout<<*itbegin<<endl;
    //     itbegin++;
    // }
    //第二种写法
    // for ( vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout<<*it<<endl;
    // }
    //第三种写法
    //回调函数 void (*name)(int)
    for_each(v.begin(), v.end(),myprint); 
}
//对于自定义数据类型的迭代器
class Person
{
public:
//初始化列表
    Person(string name,int age):m_name(name),m_age(age){}
    string m_name;
    int m_age;
};
void myprint_person(Person &p)  
{
    cout<<p.m_name<<" "<<p.m_age<<endl;
}
void test03()
{
    vector<Person> v;//容器类型为<Person>
    Person p1("张三", 18);
    Person p2("李四", 20);
    Person p3("王五", 22);
    Person p4("赵六", 25);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    //使用迭代器遍历vector容器
    //vector<Person>::iterator itbegin创建迭代器
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //*it==person
        cout<<it->m_name<<" "<<it->m_age<<endl;
    }
    //使用for_each函数遍历容器
    for_each(v.begin(), v.end(), myprint_person); 
}
//存放自定义数据类型的指针
void test04()
{
    vector<Person*> v;//容器类型为<Person*>
    Person p1("张三", 18);
    Person p2("李四", 20);
    Person p3("王五", 22);
    Person p4("赵六", 25);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    //使用迭代器遍历vector容器
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<(*it)->m_name<<" "<<(*it)->m_age<<endl;
    }
}
//容器嵌套容器
void test05()
{
    //大容器包含的是int类型的小容器
    vector<vector<int>> v;
    vector<int> v1;//初始化小容器
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    //给每个vector容器添加数据
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);//0 1 2 3 4
        v2.push_back(i+10);//10 11 12 13 14
        v3.push_back(i+20);//20 21 22 23 24
        v4.push_back(i+30);//30 31 32 33 34
    }
    //将每个vector小容器添加到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    //使用迭代器遍历大容器  it是指向小容器的指针
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //使用迭代器遍历小容器
        for (vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    test05();
    system("pause");
    return EXIT_SUCCESS;
}