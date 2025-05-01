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
        vector<int> topKFrequent(vector<int>& nums, int k) {
            //使用map存储每个元素出现的频率
            unordered_map<int, int> map;
            for (size_t i = 0; i < nums.size(); i++)
            {
                map[nums[i]]++;
            }
            //使用优先队列存储频率最高的k个元素
            priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
            for (auto& e : map)
            {
                pq.push(make_pair(e.second, e.first));//fre:num
                if (pq.size() > k)
                {
                    pq.pop();//如果优先队列的大小大于k，则删除频率最低的元素
                }
            }
            vector<int> res;
            while (!pq.empty())
            {
                res.push_back(pq.top().second);//插入num
                pq.pop();
            }
            return res;
        }
    };
void test01()
{
    vector<int> nums = {1,1,1,2,2,1,4,4,4,4,5,5,5,5,5,3};
    int k = 3;
    Solution s;
    vector<int> res = s.topKFrequent(nums, k);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}