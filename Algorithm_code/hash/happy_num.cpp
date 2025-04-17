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
#include <unordered_set>
using namespace std;

//获取每位的平方和
int getSum(int n)
{
    int sum=0;
    while (n!=0)
    {
        sum+=(n%10)*(n%10);
        n/=10;
    }
    return sum;
}
class Solution {
    public:
        bool isHappy(int n) {
            //int mid;
            unordered_set<int> res;
            while(1)
            {
                n=getSum(n);
                if (n==1)
                {
                    return true;
                }
                else if (res.find(n)!=res.end())
                {
                    return false;
                }
                else
                {
                    res.insert(n);
                }
            }
        }
    };
void test01()
{
    int n=19;
    Solution s;
    bool res=s.isHappy(n);
    if (res==true)
    {
        printf("是快乐数\n");
    }
    else 
    {
        printf("不是快乐数\n");
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}