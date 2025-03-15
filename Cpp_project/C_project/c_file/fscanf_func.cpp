#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


void test01()
{
    //先测试下sscanf函数
    char buf[32]="Tom 20 saaaa";
    char name[32];
    int age;
    sscanf(buf,"%s %d",name,&age);
    cout<<"name:"<<name<<" age:"<<age<<endl;

    //再测试下fscanf函数
    FILE *fp=fopen("test.txt","r");
    if(fp==NULL)
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    fscanf(fp,"name:%s age:%d",name,&age);
    cout<<"name:"<<name<<" age:"<<age<<endl;
    fclose(fp);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}