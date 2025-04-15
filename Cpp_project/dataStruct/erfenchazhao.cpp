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

//二分查找
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int size = nums.size();
            int start=0;
            int end=size-1;
            while(start<=end)
            {
                int mid = (start+end)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }
                else if(nums[mid]>target)
                {
                    end=mid-1;
                }
                else if(nums[mid]<target)
                {
                    start=mid+1;
                }
            }
            return -1;
        }
    };
void test01()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    cout<<"输入：nums = [-1,0,3,5,9,12], target = "<<target<<endl;
    Solution s;
    int result = s.search(nums, target);
    cout<<"输出："<<result<<endl;
    if (result == -1)
    {
        cout<<"解释："<<target<<"不存在nums中因此返回-1"<<endl;
    }
    else
    {
        cout<<"解释："<<target<<"出现在nums中且下标为"<<result<<endl;
    }
    {
        /* code */
    }
    
}

//搜索插入位置
class Solution1 {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int size = nums.size();
            int left = 0;
            int right = size - 1;
            while (left<=right)
            {
                int mid = (left+right)/2;
                if (nums[mid]==target)
                {
                    return mid;
                }
                else if (nums[mid]>target)
                {
                    right = mid - 1;
                }
                else if (nums[mid]<target)
                {
                    left = mid + 1;
                }
            }
            return left;
        }
    };
void test02()
{                                                                                               
    vector<int> nums = {1,3,5,6};
    int target = 0;
    cout<<"输入：nums = [1,3,5,6], target = "<<target<<endl;
    Solution1 s;
    int result = s.searchInsert(nums, target);
    cout<<"输出："<<result<<endl;

}
int main() 
{
    test02();
    system("pause");
    return EXIT_SUCCESS;
}