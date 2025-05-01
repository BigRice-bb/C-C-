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

class MyQueue
{
public:
    stack<int> stin;
    stack<int> stout;
    MyQueue(){};

    void push(int x)
    {
        stin.push(x); // 直接入队
    }

    int pop()
    { // 判断 stout是否为空 若空stin全部导入到stout  若非空直接pop
        int ret;
        if (stout.empty())
        {//将stin全部导入到stout
            while (!stin.empty())
            {
                stout.push(stin.top());
                stin.pop();
            }
            //返回栈首元素 出栈
            ret=stout.top();
            stout.pop();
            return ret;
        }
        else
        {
            ret = stout.top();
            stout.pop();
            return ret;
        }
    }
    int peek()
    {
        int ret;
        if (stout.empty())
        {
            while (!stin.empty())
            {
                stout.push(stin.top());
                stin.pop();
            }
            return stout.top();
        }
        return stout.top();
    }

    bool empty()
    {
        if(stin.empty() && stout.empty())
        {
            return true;
        }
        return false;
    }
};

void test01()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    cout<< q.pop() << endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}