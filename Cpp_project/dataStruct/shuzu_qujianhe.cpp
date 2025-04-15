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

// 暴力解法
class Solution
{
public:
    // 暴力解法
    // void getadd(void)
    // {
    //     int u = 0;
    //     cout << "input nums:";
    //     cin >> u;
    //     vector<int> a(u);
    //     int x = 0;
    //     while (u--)
    //     {
    //         cout << "input a[" << x << "]:";
    //         cin >> a[x++];
    //     }
    //     int m, n;
    //     int sum = 0;
    //     while (cin >> m >> n)
    //     {
    //         sum = 0;
    //         if (m > n || m < 0 || n < 0 || m >= a.size() || n >= a.size())
    //         {
    //             cout << "error" << endl;
    //             continue;
    //         }
    //         for (int i = m; i <= n; i++)
    //         {
    //             sum += a[i];
    //         }
    //         cout << sum << endl;
    //     }
    // }
    // 前缀和解法
    void getadd(int)
    {
        int n, a, b;
        cout << "input nums:";
        cin >> n;
        vector<int> arr(n, 0);
        vector<int> sum(n, 0);
        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            cout << "input a[" << i << "]:";
            cin >> arr[i];
            pre += arr[i];
            sum[i] = pre;
        }
        cout << "input m and n:";
        while (cin >> a >> b)
        {
            if (a > b || a < 0 || b < 0 || a >= arr.size() || b >= arr.size())
            {
                cout << "error" << endl;
                continue;
            }
            if (a == 0)
            {
                cout << sum[b] << endl;
            }
            else
            {
                cout << sum[b] - sum[a - 1] << endl;
            }
        }
    }
};

void test01()
{
    Solution s;
    s.getadd(1);
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}