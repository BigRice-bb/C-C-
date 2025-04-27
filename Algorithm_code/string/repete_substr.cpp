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
    //kmp算法解法
    void getNext(string needle, vector<int> &next)
    {
        int j=0;//前缀末尾
        next.resize(needle.size());
        next[0] = 0;
        for (size_t i = 1; i < needle.size(); i++)//i指向后缀末尾
        {
            while (j>0 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (needle[i]== needle[j])
            {
                j++;
            }
            next[i] = j;  
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.empty())
        {
            return false;
        }
        vector<int> next;
        getNext(s, next);
        if (next[next.size()-1]!=0 && s.size()%(s.size()-next[s.size()-1])==0)
        {
            return true;
        }
        return false;
    }

    //移动匹配---最简单的方法
    bool repeatedSubstringPattern2(string s) {
        string s1=s+s;
        s1.erase(s1.begin());
        s1.erase(s1.end()-1);//去除首尾元素
        if (s1.find(s)!=string::npos)
        {
            return true;
        }
        return false;
        
    }

    //暴力解法 O(n^2)
        bool repeatedSubstringPattern1(string s) {
            int len= s.size();
            for(int i = 1 ; i<= len/2 ; i++)
            {
                if(len%i==0)
                {
                    int repete=len/i;
                    string subs=s.substr(0,i);
                    string res="";
                    for(int j=0;j<repete;j++)
                    {
                        res+=subs;
                    }
                    if(res==s)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };
void test01()
{
    Solution s;
    string s1="ababab";
    int ret=s.repeatedSubstringPattern(s1);
    cout << ret << endl;  
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}