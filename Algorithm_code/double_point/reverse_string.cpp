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

class Solution {
    public:
        void reverseString(vector<char>& s) {
            int left = 0;
            int right = s.size() - 1;
            while (left<right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
    };
void test01()
{
    vector<char> s = {'h','e','l','l','o'};
    Solution solu;
    solu.reverseString(s);
    for_each(s.begin(), s.end(), [](char c){cout << c<<" ";});
    cout << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}