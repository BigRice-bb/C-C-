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

        //暴力法
        vector<int> sortedSquares1(vector<int>& nums) {

            for( vector<int>::iterator it = nums.begin();\
            it!=nums.end();++it)
            {
                *it = (*it) * (*it);
            }
            sort(nums.begin(), nums.end());
            return nums;
        }

        //双指针法
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int>::iterator front = nums.begin();
            vector<int>::iterator back = nums.end()-1;
            vector<int> res(nums.size(), 0);
            int index = nums.size()-1;
            while(front<=back)
            {
                if(*front**front > *back * *back)
                {
                    res[index--]=(*front * *front);
                    front++;
                }
                else
                {
                    res[index--]=(*back * *back);
                    back--;
                }
            }
            return res;
        }

    };

void test01()
{
    vector<int> nums = {-4,-1,0,3,10};
    Solution solu;
    vector<int> res = solu.sortedSquares(nums);
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}