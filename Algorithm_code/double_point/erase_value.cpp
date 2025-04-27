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
    // 二刷
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0;
        int slow = 0;
        for ( ; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;

            }
            
        }
        return slow;
        
    }
    // 一刷
    int removeElement1(vector<int> &nums, int val)
    {
        int size = nums.size();
        int flag = size;
        vector<int>::iterator fast = nums.begin();
        vector<int>::iterator slow = nums.begin();
        for (int i = 0; i < size; ++i)
        {
            if (*fast == val)
            {
                fast++;
                flag--;
                continue;
            }
            *slow = *fast;
            slow++;
            fast++;
        }

        return flag;
    }
};

void test01()
{
    Solution s;
    vector<int> nums = {0, 1, 2,3,3, 0, 4, 2};
    int val = 2;
    int ret = s.removeElement(nums, val);
    cout << ret << endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}