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
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> matrix(n, vector<int>(n, 0));//创建n*n的矩阵
            int startx = 0, starty = 0;//起始坐标
            int loop=n / 2;//循环次数
            int count=1;//当前数字
            int offset=n-1;//偏移量

            int i=0, j=0;//当前坐标
            while (loop--)
            {
                j = startx;
                i = starty;
                for ( i ; i < offset; i++)//上行从左到右
                {
                    matrix[j][i]= count++;
                }
                for ( j ; j < offset; j++)//右行从上到下
                {
                    matrix[j][i] = count++;
                }
                for ( i ; i > startx; i--)//下行从右到左
                {
                    matrix[j][i] = count++;
                }
                for ( j ; j > starty; j--)//左行从下到上
                {
                    matrix[j][i] = count++;
                } 
                startx++;
                starty++;
                offset -= 1;//偏移量每次减2
            }
            if (n % 2 != 0)//如果n是奇数，填充中间的数字
            {
                matrix[n / 2][n / 2] = count;
            }
            return matrix;  
        }
    };

void test01()
{
    Solution s;
    vector<vector<int>> res = s.generateMatrix(5);
    for (auto &i : res)
    {
        for (auto &j : i)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
}
int main() 
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}