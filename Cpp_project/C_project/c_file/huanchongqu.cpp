#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void test01()
{
    FILE *fp=fopen("test.txt","w+");
    if(fp==NULL)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    char m=0;
    while(1)
    {
        scanf("%c",&m);
        if(m==':')
        {
            break;
        }
        fputc(m,fp);
        fflush(fp);//手动刷新文件缓冲
    }
    //当文件关闭时才会刷新缓冲区
    fclose(fp);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}