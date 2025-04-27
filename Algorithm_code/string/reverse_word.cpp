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

class Solution {
    public:
        string reverseWords(string s) {
            //第一步去除多余空格
            int fast=0;
            int slow=0;
            for (; fast< s.size(); fast++)
            {
                if (s[fast]!=' ')//fast找到了一个字母
                {
                    if(slow!=0)
                    {
                        s[slow++]=' ';//如果slow不是起始位置  加一个' '
                    }
                    while (s[fast]!=' '&&fast<s.size())
                    {
                        s[slow++]=s[fast++];
                    }
                }
            }
            s.resize(slow);
            //第二步翻转字符串
            reverse(s.begin(),s.end());
            //第三步翻转每个单词
            int start=0;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i]==' ')
                {
                    reverse(s.begin()+start,s.begin()+i);//左闭右开,不包含' '
                    start=i+1;
                }
            }
            reverse(s.begin()+start,s.end());//翻转最后一个单词
            return s;
        }
    };
void test01()
{
    Solution s;
    string s1="    the sky   is   blue  ";
    s1=s.reverseWords(s1);
    cout<<s1<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}