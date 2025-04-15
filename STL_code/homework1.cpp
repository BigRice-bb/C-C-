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

class Person
{
public:
    string name;
    int age;
    vector<int> scores;
    Person(string name, int age, vector<int> scores) : name(name), age(age), scores(scores) {}
    int findmax()//返回最高分位置
    {
        int t = 0;
        int max = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i] > max)
                max = scores[i];
                t = i;
        }
        return t;
    }
    int findmin()//返回最低分位置
    {
        int min = 100;
        int t = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i] < min)
                min = scores[i];
                t = i;
        }
        return t;
    }
    void eraseM()//删除最高分和最低分
    {
        scores.erase(scores.begin() + this->findmax());
        scores.erase(scores.begin() + this->findmin());
    }
    double average()//返回平均分
    {
        double sum = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            sum += scores[i];
        }
        return sum / scores.size();
    }
    void print()
    {
        cout << "姓名: " << name ;
        cout << "  年龄:" << age;
        cout << "  平均分:"<< this->average() << endl;
    }
};
void test01()
{
    vector<Person> v;
    vector<int> scores1 = { 100, 99, 98, 97, 96, 95, 94, 93, 92, 91 };
    vector<int> scores2 = { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81 };
    vector<int> scores3 = { 80, 79, 78, 77, 76, 75, 74, 73, 72, 71 };
    vector<int> scores4 = { 70, 69, 68, 67, 66, 65, 64, 63, 62, 61 };
    vector<int> scores5 = { 60, 59, 58, 57, 56, 55, 54, 53, 52, 51 };
    Person p1("A", 20, scores1);
    Person p2("B", 21, scores2);
    Person p3("C", 22, scores3);
    Person p4("D", 23, scores4);
    Person p5("E", 24, scores5);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        sort((*it).scores.begin(), (*it).scores.end());//完成排序
        for(vector<int>::iterator it1 = (*it).scores.begin(); it1 != (*it).scores.end(); it1++)
        {
            cout << *it1 << " ";
        }
        cout << endl;
        it->scores.erase(it->scores.begin());//删除最高分
        it->scores.erase(it->scores.end()-1);//删除最低分
        for(vector<int>::iterator it1 = (*it).scores.begin(); it1 != (*it).scores.end(); it1++)
        {
            cout << *it1 << " ";
        }
        it->print();//打印平均分
        cout << endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}