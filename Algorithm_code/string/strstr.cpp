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

class Solution
{
public:
    //KMP算法
    void getNext(string needle, vector<int> &next)
    {
        //初始化j
        int j=0;//前缀末尾
        next.resize(needle.size());
        next[0] = 0;
        for (size_t i = 1; i < needle.size(); i++)//i指向后缀末尾
        {
            //回退过程  
            while(j>0 && needle[i] != needle[j])
            {
                j = next[j - 1];//直到找到前后缀相同的j值  j还代表前后缀相同的位数
            }
            if (needle[i]== needle[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        vector<int> next;
        getNext(needle, next);
        int j = 0;//初始化 前缀末尾
        for (size_t i = 1; i < haystack.size(); i++)//后缀末尾
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == needle.size())
            {
                return i - needle.size() + 1;
            }
        }
        return -1;

    }
    // 暴力法O(m*n)
    int strStr1(string haystack, string needle)
    {

        if (needle.empty())
        {
            return 0;
        }
        if (haystack.size() < needle.size())
        {
            return -1;
        }

        int j;

        for (size_t i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            j = 0;
            for (; j < needle.size(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                if (j == needle.size() - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
void test01()
{
    Solution s;
    string s1 = "aabaabaaf";
    string s2 = "aabaaf";
    int ret=s.strStr(s1, s2);
    cout << ret << endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}