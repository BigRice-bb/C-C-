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
void fast_sort(vector<int> &arr,int l,int r) 
{
    if(l>=r)
        return;
    int left=l;
    int right=r;
    int key=arr[left];//比ke小的放左边  比key大的放右边
    while(left<right)
    {
        while(left<right && arr[right]>=key)
        {
            right--;
        }//找到右边比key小的数
        if(left<right)
        {
            arr[left]=arr[right];
        }
        while(left<right && arr[left]<=key)
        {
            left++;
        }
        if(left<right)
        {
            arr[right]=arr[left];
        }
        
    }
    arr[left]=key;
    fast_sort(arr,l,left-1);
    fast_sort(arr,left+1,r);
}
void test01()
{
    vector<int> arr={1,3,5,2,4,6};
    fast_sort(arr,0,arr.size()-1);
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}