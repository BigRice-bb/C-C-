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
#include <functional>
using namespace std;


// void myprint(int val)
// {
//     cout<<val<<endl;
// }
class myprint:public binary_function<int,int,void>
{
    public:
        void operator()(int val,int start) const
        {
            cout<<val+start<<endl;
        }
};
//函数对象适配器
void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout<<"input start number: "<<endl;
    int start;
    cin>>start;
    for_each(v.begin(),v.end(),bind2nd(myprint(),start));//适配器  将两个东西绑定为一个
}
//取反适配器
class grater5:public unary_function<int,bool>
{
    public:
        bool operator()(int val)const
        {
            return val > 5;
        }
};
void test02()
{
    vector<int> v;
    for(size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(),v.end(),not1(grater5()));
    if(it == v.end())
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"find it:"<<*it<<endl;
    }
}


int main() 
{
    test02();
    system("pause");
    return EXIT_SUCCESS;
}