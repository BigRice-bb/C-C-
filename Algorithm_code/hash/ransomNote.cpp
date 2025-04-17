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

//数组法
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if (ransomNote.size()>magazine.size())
            {
                return false;
            }
            int book[26]={0};
            //第一步先把magazine中的字母统计出来
            for(auto i:magazine)
            {
                book[i-'a']++;
            }
            //第二步ransomNote中的字母位置--,若小于0则返回false,代表不可表示
            for(auto i:ransomNote)
            {
                book[i-'a']--;
                if(book[i-'a']<0)
                {
                    return false;
                }
            }
            return true;
        }
    };

void test01()
{
    string ransomNote="aac";
    string magazine="aab";
    Solution s;
    bool res=s.canConstruct(ransomNote,magazine);
    if (res==true)
    {
        cout<<"可以表示"<<endl;
    }
    else
    {
        cout<<"不可以表示"<<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}