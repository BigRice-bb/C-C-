#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;//代表n*m的矩阵土地
    int sum=0;
    vector<vector<int>> land(n, vector<int>(m, 0));//初始化二维数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
            sum+=land[i][j];//前缀和的思想
        }
    }

    //分别求出每行和每列的元素和
    //行
    vector<int> row_sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            row_sum[i]+=land[i][j];
        }
    }
   //int sum1=sum;
    //列
    vector<int> col_sum(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            col_sum[i]+=land[j][i];
        }
    }

    //按行划分找到最小差
    int result=INT_MAX;
    int horizontal=0;
    for(int i=0;i<n;i++)
    {
        horizontal+=row_sum[i];
        result=min(result,abs(sum-horizontal-horizontal));
    }
    //按列划分找到最小差
    int vertical=0;
    for(int i=0;i<m;i++)
    {
        vertical+=col_sum[i];
        result=min(result,abs(sum-vertical-vertical));
    }
    cout<<result<<endl;
    
    system("pause");
    return EXIT_SUCCESS;
}

