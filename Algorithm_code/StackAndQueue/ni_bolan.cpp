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
        int evalRPN(vector<string>& tokens) {
            stack<string> st;
            int a;
            int b;
            for (size_t i = 0; i < tokens.size(); i++)
            {
                if (tokens[i]== "+" || tokens[i]== "-"|| tokens[i]== "*"|| tokens[i]== "/")
                {
                    b = stoi(st.top());
                    st.pop();
                    a = stoi(st.top());
                    st.pop();
                    if (tokens[i]== "+")
                    {
                        st.push(to_string(a+b));
                    }
                    else if (tokens[i]== "-")
                    {
                        st.push(to_string(a-b));
                    }
                    else if (tokens[i]== "*")
                    {
                        st.push(to_string(a*b));
                    }
                    else if (tokens[i]== "/")
                    {
                        st.push(to_string(a/b));
                    }   
                }
                else
                {
                    st.push(tokens[i]);
                }
            }
            return stoi(st.top());
        }
    };
void test01()
{
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}