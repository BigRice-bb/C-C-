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
    int num;
    string s;  
    int left;
    int right; 
    while (cin>>num)
    {
        cin>>s;
        //全部翻转 
        for ( left = 0,right=s.size()-1; left < s.size()/2; left++,right--)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
        }
        //局部翻转
        for (left = 0,right=num-1; left < num/2; left++,right--)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
        }
        for (left = num,right=s.size()-1; left < (s.size()+num)/2; left++,right--)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
        }
        cout<<s<<endl;
    }
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}
