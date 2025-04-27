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

//由n4方的复杂度,降到了n2方
class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int , int> map;//用于存放前两个数组的元素和  key 和   value 出现次数
            int count=0;//统计结果
            for(int a: nums1)
            {
                for(int b: nums2)
                {
                    map[a+b]++;//map对应key值的value++
                }
            }
            for(int c: nums3)
            {
                for(int d: nums4)
                {
                    if(map.find(0-c-d)!=map.end())//需要找的目标值为0-c-d 
                    {
                        count+=map[0-c-d];
                    }
                }
            }
            return count;
        }
    };
void test01()
{
    vector<int> nums1={1,2};
    vector<int> nums2={-2,-1};
    vector<int> nums3={-1,2};
    vector<int> nums4={0,2};
    Solution s;
    int res=s.fourSumCount(nums1,nums2,nums3,nums4);
    cout<<res<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}