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

class myqueue{
    public:
        deque<int> q;
        void push(int value){
            //插入函数--每次插入比较value和队首元素的大小
            //如果value大于队首元素，则删除队首元素，直到value小于等于队首元素
            while (!q.empty()&& value> q.back())//注意这里要和q.back()比较
            {
                q.pop_back();
            }
            q.push_back(value);
        }

        void pop(int value){
            //如果value等于队首元素 则删除队首元素
            //如果value不等于队首元素，则不删除队首元素
            if (!q.empty()&& value== q.front())
            {
                q.pop_front();
            }
        }

        int front(){
            //返回队首元素
            return q.front();
        }
};

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> result;
            myqueue q;
            //队列中插入前k个元素
            for (int i = 0; i < k; i++)
            {
                q.push(nums[i]);
            }
            //将队首元素插入结果中
            result.push_back(q.front());
            //从第k个元素开始遍历
            for (size_t i = k; i < nums.size(); i++)
            {
                q.pop(nums[i-k]);
                q.push(nums[i]);
                result.push_back(q.front());
            }
            return result;
        }
    };
void test01()
{
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    Solution s;
    vector<int> result = s.maxSlidingWindow(nums,k);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}