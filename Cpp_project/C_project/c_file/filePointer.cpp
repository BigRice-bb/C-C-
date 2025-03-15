#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


typedef struct student{
    int age;
    char name[10];
    int num;
}stu_t;


void test01()
{
    stu_t student[3]={
        18,"aaa",1,
        19,"bbb",2,
        20,"ccc",3
    };
    FILE*fp=fopen("test.txt","w+");
    if (fp == NULL)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    fwrite(student,1,sizeof(stu_t)*3,fp);
    fseek(fp,20,SEEK_SET);
    stu_t s1;
    fread(&s1,1,sizeof(stu_t),fp);
    cout<<s1.age<<" "<<s1.name<<" "<<s1.num<<endl;

    rewind(fp);
    fseek(fp,0,SEEK_END);
    int size=ftell(fp);
    cout<<"当前文件大小为:"<<size<<endl;
    fclose(fp);
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}