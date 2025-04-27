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
    string s;
    int count = 0;
    int left;
    int right;
    while (cin>>s)
    {
        count = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i]<='9'&& s[i]>='0')
            {
                count++;
            }
        }
        cout<<count<<endl;
        left=s.size()-1;
        s.resize(s.size()+count*5);
        right = s.size()-1;
        while(left>=0)
        {
            if (s[left]>='0'&& s[left]<='9')
            {
                s[right--] = 'r';
                s[right--] = 'e';
                s[right--] = 'b';
                s[right--] = 'm';
                s[right--] = 'u';
                s[right--] = 'n';
                left--;
            }
            else
            {
                s[right--] = s[left--];
            }
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