#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
// 创建员工类
class Employee
{
public:
    Employee(string name, int wage)
    {
        this->name = name;
        this->wage = wage;
    }
    string name;
    int wage;
};
class Mycompare{
public:
    bool operator()(const pair<int,int> &e1, const pair<int,int> &e2) const
    {
        if(e1.first!=e2.first)
        {
            return e1.first < e2.first;
        }
        else
        return e1.second < e2.second;
    }
};
//招聘5名员工,分给不同部门(key值区分),分部门打印员工信息
void test01()
{
    multimap<pair<int,int>,string,Mycompare> m;
    Employee e1("张三", 10000);
    Employee e2("李四", 12000);
    Employee e3("王五", 15000);
    Employee e4("赵六", 18000);
    Employee e5("田七", 20000);
    m.insert(make_pair(make_pair(1,e1.wage),e1.name));
    m.insert(make_pair(make_pair(1,e2.wage),e2.name));
    m.insert(make_pair(make_pair(2,e3.wage),e3.name));
    m.insert(make_pair(make_pair(2,e4.wage),e4.name));
    m.insert(make_pair(make_pair(3,e5.wage),e5.name));
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "部门:" << it->first.first << " ";
        cout << "姓名:" << it->second << " 工资:" << it->first.second << endl;
    }

}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}