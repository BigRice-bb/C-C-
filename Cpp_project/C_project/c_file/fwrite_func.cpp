#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//创建结构体变量
typedef struct student
{
    int age;
    char name[10];
    int num;
}stu_t;


void write()
{
    stu_t student[3]={
        18,"aaa",1,
        19,"bbb",2,
        20,"ccc",3
    };
    FILE* fp=fopen("test.txt","w");
    if(!fp)
    {
        perror("open error");
        return;
    }
    int ret=fwrite(student,1,sizeof(stu_t)*3,fp);
    if(ret==0)
    {
        cout<<"error"<<endl;
        return;

    }
    printf("ret=%d",ret);
    //输出为乱码,因为写入是二进制写入的

    fclose(fp); 
}
void read()
{
    stu_t student[3];
    FILE* fp=fopen("test.txt","r");
    if(!fp)
    {
        perror("open error");
        return;
    }
    int ret=fread(student,1,sizeof(stu_t)*4,fp);
    cout<<ret<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<student[i].age<<student[i].name<<student[i].num<<endl;
    }
    fclose(fp);
}

int main()
{
    write();
    read();
    return EXIT_SUCCESS;
}