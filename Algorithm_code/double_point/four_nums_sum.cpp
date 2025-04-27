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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }
        long long sum;
        vector<vector<int>> res;
        //第一步排序
        sort(nums.begin(), nums.end());
        int left, right;
        //确定第一个数字
        for (size_t i = 0; i < nums.size() - 3; i++)
        {
            //第一个数字去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            //确定第二个数字
            for (size_t j = i+1; j < nums.size() - 2; j++)
            {
                //第二个数字去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                //双指针开始头尾遍历
                left = j + 1;
                right = nums.size() - 1;
                while (left < right)
                {
                    sum = (long long)(nums[i] + nums[j] + nums[left] + nums[right]);
                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]}); 
                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
        
    }
};

void test01()
{
    Solution s;
    vector<int> nums = {-1, 0,0,0,0,-3, 1, 2, -1, -4};
    vector<vector<int>> res = s.fourSum(nums, 0);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}