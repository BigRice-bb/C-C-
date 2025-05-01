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

class MyStack {
    public:
        queue<int> q1;
        queue<int> q2;
        MyStack() {}//默认构造
        
        void push(int x) {
            q1.push(x);
        }
        
        int pop() {
            while (q1.size() > 1)
            {
                q2.push(q1.front());//将前n-1个元素导入q2
                q1.pop();                               
            }
            int ret = q1.front();
            q1.pop();
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();//还原现场
            } 
            return ret;
        }
        
        int top() {
            return q1.back();
        }
        
        bool empty() {
            return q1.empty();
        }
    };

void test01()
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    cout << s.pop() << endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}