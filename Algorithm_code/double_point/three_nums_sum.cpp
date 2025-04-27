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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return {};
        }
        // 第一步排序
        sort(nums.begin(), nums.end()); // 平均O(nlogn)
        vector<vector<int>> res;
        int sum;
        // 遍历第一个数字
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            // 第一个数字去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // 双指针开始头尾遍历
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {

                sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left])
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
        return res;
    }

    // 一刷
    vector<vector<int>> threeSum1(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end()); // 第一步排序
        vector<vector<int>> res;
        int sum;                                     // 用于存放中间值
        int left;                                    // 用于存放左值
        int right;                                   // 用于存放右值
        for (size_t i = 0; i < nums.size() - 2; i++) // 固定第一个数
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            } // 去重
            left = i + 1;
            right = nums.size() - 1; //
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});   // 找到了一组
                    while (left < right && nums[left] == nums[left + 1]) // 去重
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) // 去重
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
void test01()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, 5, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
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