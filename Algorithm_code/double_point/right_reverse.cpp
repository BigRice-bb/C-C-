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

void test01()
{
    int num;//需要右旋的位数
    string str;//需要右旋的字符串
    while (cin>> num)
    {
        cin>> str;
        //第一步全部翻转
        reverse(str.begin(), str.end());
        //第二步翻转前num位
        reverse(str.begin(), str.begin()+num);
        //第三步翻转后num位
        reverse(str.begin()+num, str.end());
        cout<< str<< endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}