#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <ctime>

//第一步创建随机数,写入文件
void write_rand()
{
    //生成随机数
    FILE *fp=fopen("test.txt","w");
    srand((unsigned int) time(NULL));//当前时间为随机数种子
    for(int i=0;i<10;i++)
    {
        fprintf(fp,"%d\n",rand()%100) ;//生成0-99的随机数
    //rand函数返回0-326767之间的随机数
    //将该随机数写入文件
    }
    fclose(fp);
}
//第二步读取文件中的随机数
void read_rand(int * arr)
{
    FILE *fp=fopen("test.txt","r");
    if(fp==NULL)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    for(int i=0;i<10;i++)
    {
        fscanf(fp,"%d\n",&arr[i]);
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }
    fclose(fp);
}
//第三步对文件中的随机数进行排序
void sort_rand(int *arr)
{
    int min;
    for(int i=0;i<9;i++)
    {
        min=i;
        for(int j=i+1;j<10;j++)
        {
            if(arr[j]<arr[i])
            {
                min=j;
                int t;
                t=arr[i];
                arr[i]=arr[min];
                arr[min]=t;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    } 
}
//写入到文件
void write_fp(int *arr)
{
    FILE *fp=fopen("test.txt","a+");
    fputs("排序后:\n",fp);
    for(int i=0;i<10;i++)
    {
        fprintf(fp,"%d\n",arr[i]);
    } 
    fclose(fp);
}



void test01()
{
    int *arr=new int[10];
    read_rand(arr);
    sort_rand(arr);
    write_fp(arr);
    //write_rand();
    //cout<<RAND_MAX<<endl;
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}