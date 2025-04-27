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
string replaceNumber(string s)
{
    int oldindex=s.size()-1;//记录老末尾位置
    //遍历字符串 找出数字个数
    int count=0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            count++;
        }
    }
    //拓展字符串大小空间
    s.resize(s.size()+count*5);
    int newindex=s.size()-1;//记录新末尾位置
    //从后往前移动字符串
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[oldindex]>='0' && s[oldindex]<='9')
        {
            s[newindex--]='r';
            s[newindex--]='e';
            s[newindex--]='b';
            s[newindex--]='m';
            s[newindex--]='u';
            s[newindex--]='n';
        }
        else
        {
            s[newindex--]=s[oldindex];
        }
        oldindex--;
    }
    return s;
}

void test01()
{
    string s;
    while(cin>> s)
    {
        s=replaceNumber(s);
        cout<<s<<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}