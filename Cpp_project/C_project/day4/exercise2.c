//二级指针嵌套练习
//一个老师 带三个学生  ,共三个老师
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//老师类
typedef struct student{
    char*name;
    int age;
}student;
//学生类
typedef struct teacher{
    char* name;
    student **stu;//二级指针负责存放三个学生
}teacher;
teacher** space_allo(int len)
{
    //1.开辟存放三个老师的空间
    teacher **team=(teacher**)malloc(sizeof(teacher*)*len);
    //2.为每个老师开辟空间
    for (size_t i = 0; i < len; i++)
    {
        team[i]=(teacher*)malloc(sizeof(teacher));
        team[i]->name=(char*)malloc(16);
        sprintf(team[i]->name,"teacher_%d",i);//为老师的姓名开辟空间
        //为每个老师的三个学生开辟空间
        team[i]->stu=(student **)malloc(sizeof(student*)*3);
        for (size_t j = 0; j < 3; j++)
        {
            team[i]->stu[j]=(student*)malloc(sizeof(student));
            team[i]->stu[j]->age=15+i+j;
            team[i]->stu[j]->name=(char*) malloc(16);
            sprintf(team[i]->stu[j]->name,"%d_student_%d",i,j);
        }
    }
    return team;
}
void printer(teacher **team,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("老师姓名: %s\n",team[i]->name);
        for (size_t j=0; j< 3; j++)
        {
            printf("学生%d: %s %d\n",j,team[i]->stu[j]->name\
                ,team[i]->stu[j]->age);
        } 
        printf("\n");
    }
}
void free_space(teacher** team,int len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            free(team[i]->stu[j]->name);
            free(team[i]->stu[j]);
        }
        free(team[i]->name);
        free(team[i]->stu);
        free(team[i]);
    }
    free(team);
}
void test01()
{
    teacher **team=NULL;//三个老师
    team=space_allo(5);
    printer(team,5);
    free_space(team,5);
}
int main()
{

    test01();
    system("pause");
    return 0;
}