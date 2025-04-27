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
        string reverseStr(string s, int k) {
            int len=s.size();
            for (int i=0;i<len;i+=2*k)
            {
                if(i+k<=len)
                {
                    reverse(s.begin()+i,s.begin()+i+k);
                    continue;
                }
                else
                {
                    reverse(s.begin()+i,s.end());
                }
            }
            return s;
        }
    };
void test01()
{
    Solution s;
    string str="abcdefg";
    str=s.reverseStr(str,2);
    cout<<str<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}