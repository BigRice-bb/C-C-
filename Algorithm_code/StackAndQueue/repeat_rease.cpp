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

// string erases(string s)
// {
//     for (size_t i = 0; i < s.size()-1; i++)
//     {
//         if (s[i] == s[i + 1])
//         {
//             s.erase(i, 2);
//             i--;
//         }
//     }
    
    
// }

class Solution {
    public:
    //用棧解決
    string removeDuplicates(string s) {
        string ret;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (ret.empty() || s[i] != ret.back())
            {
                ret.push_back(s[i]);
            }
            else
            {
                ret.pop_back();
            }
        }
        return ret;
        
    }



    //暴力法
        string removeDuplicates1(string s) {
            string ret=s;
            size_t i = 0;
            while(i < ret.size()-1 )
            {
                if (ret.size()<2)
                {
                    return ret;
                }
                
                if (ret[i] == ret[i + 1])
                {
                    ret.erase(i, 2);
                    if (i>0)
                    {
                        i--;
                    }
                    else
                    {
                        i = 0;
                    }
                }
                else
                {
                    i++;
                }
            }
            return ret;
        }
    };

void test01()
{
    Solution ss;
    string s1="abbaca";
    s1=ss.removeDuplicates(s1);
    cout<<s1<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}