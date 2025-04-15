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

//找出最大值
//比较与target的大小
//比他大返回
//比他小减去
class Solution {
    public:
    //最短子序列
        int minSubArrayLen1(int target, vector<int>& nums) {
            int n = nums.size();
            vector<int> res;
            int sum=0;
            while(n>0)
            {
                int max=0;
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]>nums[max])
                    {
                        max=i;
                    }
                }
                //nums.erase(nums.begin()+max);
                if(nums[max]>=target)
                {
                    res.push_back(nums[max]);
                    nums.erase(nums.begin()+max);
                    for(auto i=res.begin();i!=res.end();i++)
                    {
                        printf("%d ",*i);
                        sum+=*i;
                    }
                    cout<<endl<<sum;
                    return res.size();
                }
                else
                {
                    target-=nums[max];
                    res.push_back(nums[max]);
                    nums.erase(nums.begin()+max);
                    n--;
                }
            }
            return 0;
        }
        //最短子数组--滑动窗口
        int minSubArrayLen(int target, vector<int>& nums) {
            int result = INT_MAX;
            int sum = 0;
            int left = 0;
            int subarrayLength = 0;
            for (int right = 0; right < nums.size(); ++right) {
                sum += nums[right];
                while (sum >= target) {
                    subarrayLength = right - left + 1;
                    result = result<subarrayLength?result:subarrayLength;
                    sum -= nums[left++];
                }
            }
            return result == INT_MAX ? 0 : result;

        }
    };

void test01()
{
    Solution solu;
    vector<int> nums={12,28,83,4,25,26,25,2,25,25,25,12};
    int target=213;
    int res=solu.minSubArrayLen(target,nums);
    cout<<"\r\n"<<res<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}