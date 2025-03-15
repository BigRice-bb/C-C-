//fprintf函数--类似printf函数,将结果输出到文件中
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void test01()
{
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fprintf(fp, "name:%s age:%d\n", "Tom", 20);
    fclose(fp);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}