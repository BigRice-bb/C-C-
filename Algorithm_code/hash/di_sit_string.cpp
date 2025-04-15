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

class Mycompare{
public:
    bool operator()(char v1,char v2)
    {
        return v1 > v2;//按降序排序
    }
};
class Solution {
    public:
    //STL容器sort算法解法
        bool isAnagram1(string s, string t) {
            string str1 = s;
            string str2 = t;
            sort(str1.begin(),str1.end());
            printf("%s\n",str1.c_str());
            sort(str2.begin(),str2.end());
            printf("%s\n",str2.c_str());
            return str1 == str2;
        }
        //数组  hash表解法
        bool isAnagram(string s, string t) {
            if (s.size()!= t.size())
            {
                return false;
            }
            int hash[26] = {0};
            for (int i = 0; i < s.size(); i++)
            {
                hash[s[i]-'a']++;//hash转换函数
                hash[t[i]-'a']--;
            }
            for (int i = 0; i < 26; i++)
            {
                if (hash[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
    };
void test01()
{
    string  s = "gramaan";
    string t = "nagaram";
    Solution s1;
    bool ret = s1.isAnagram(s,t);
    if(ret)
    {
        cout<<"是"<<endl;
    }
    else
    {
        cout<<"不是"<<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}