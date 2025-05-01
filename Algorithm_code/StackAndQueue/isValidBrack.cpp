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
        bool isValid(string s) {
            stack<char> st;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push(s[i]);
                }
                else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    switch (s[i])
                    {
                    case ')':
                        if (st.empty() || st.top() != '(')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                        case ']':
                        if (st.empty() || st.top() != '[')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                        case '}':
                        if (st.empty() || st.top() != '{')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
            return st.empty();
        }
    };

void test01()
{
    Solution s;
    string str = "{[[]{}()]}";
    bool ret = s.isValid(str);
    cout << ret << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}