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
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int , int> map;
            int mid;
            vector<int> res;
            for (size_t i = 0; i < nums.size(); i++)
            {
                mid=target - nums[i];
                auto it=map.find(mid);
                if (it!=map.end())
                {
                    res.push_back(it->second);
                    res.push_back(i);
                    return res;
                }
                else
                {
                    map.insert(make_pair(nums[i],i));
                }
            }
            return res;
        }
    };
void test01()
{
    vector<int> nums={2,7,11,15};
    Solution s;
    vector<int>res=s.twoSum(nums,223);
    for_each(res.begin(),res.end(),[](int val){cout<<val<<" "<<endl;});
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}