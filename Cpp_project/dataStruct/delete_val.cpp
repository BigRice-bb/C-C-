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
        int removeElement1(vector<int>& nums, int val) {
            int size = nums.size();
            vector<int>::iterator it = nums.begin();
            //vector<int>::iterator it2 = it;
            while(it != nums.end())
            {
                if(*it == val)
                {
                    it = nums.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            return nums.size();
        }

        int removeElement(vector<int>& nums, int val) {
            int size = nums.size();
            int flag = size;
            vector<int>::iterator fast = nums.begin();
            vector<int>::iterator slow = nums.begin();
            for (int i = 0; i < size; ++i)
            {
                if (*fast == val)
                {
                    fast++;
                    flag--;
                    continue;
                }
                *slow = *fast;
                slow++;
                fast++;
            }

            return flag;
        }
    };


void test01()
{
    vector<int> nums = {};
    int val = 0;
    cout<<"输入：nums = {}, val = "<<val<<endl;
    Solution s;
    int result = s.removeElement(nums, val);
    for (int i = 0; i < result; ++i)
    {
        cout<<nums[i]<<" ";
    }
    cout << "新数组大小为: "<<result<<endl;
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}