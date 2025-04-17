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

//给定一个数组,找出所有和为0的三元组,要求没有重复的三元组
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;//结果
            int sum;
            if (nums.size()<3)
            {
                return res;
            }
            sort(nums.begin(),nums.end());//第一步进行排序
            for (int i = 0; i < nums.size()-2; i++)
            {
                if (nums[i]>0)
                {
                    break; //a>0,则后面的数都大于0,不可能存在和为0的三元组
                }
                else if(i>0&&nums[i]==nums[i-1])//去重 前一个找过了 下一个找的必然相同
                {
                    continue;
                }
                //到这里固定了第一个元素
                int left=i+1;
                int right=nums.size()-1;
                //双指针法找后两个元素
                while(left<right)
                {
                    int sum=nums[i]+nums[left]+nums[right];
                    if (sum>0)//需要缩小
                    {
                        right--;
                    }
                    else if(sum<0)//需要增大
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back({nums[i],nums[left],nums[right]});//找到结果
                        //去重--为防止出现重复的三元组
                        while(left<right&&nums[left]==nums[left+1])//注意,元素已经排过序了
                        {
                            left++;
                        }
                        while(left<right&&nums[right]==nums[right-1])
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
    vector<int> nums={-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> res=s.threeSum(nums);
    for (auto v:res)
    {
        for (auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}