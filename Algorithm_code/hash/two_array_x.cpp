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

class Solution {
    public:
    //使用unordered_set解决--数值可能无限大的情况
        vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> s;
            unordered_set<int> s1(nums1.begin(),nums1.end());//将nums1放入哈希表中
            for (size_t i = 0; i < nums2.size(); i++)
            {
                unordered_set<int>::iterator it =s1.find(nums2[i]);
                if (it != s1.end())//找到了
                {
                    s.insert(nums2[i]);
                }
            }
            vector<int> v(s.begin(),s.end());
            return v;
        }
    //对于数值有限--可以直接用数组哈希
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.resize(1001);
        unordered_set<int> s;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            v[nums1[i]]=1;
        }
        for (size_t i = 0; i < nums2.size(); i++)
        {
            if(v[nums2[i]]!=0)
            {
                s.insert(nums2[i]);
            }
        }
        vector<int> v1(s.begin(),s.end());
        return v1;
    }
    };
void test01()
{
    vector<int> nums1 = {1,2,2,3,4,5,6,2,1};
    vector<int> nums2 = {2,2,4,6,7};
    Solution s1;
    vector<int> ret = s1.intersection(nums1,nums2);
    for (size_t i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}