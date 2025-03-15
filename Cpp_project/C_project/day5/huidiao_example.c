#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//需求:可以打印任意类型的数组
//提供查找功能,查找对应的元素是否存在
//提供一个查找函数,接收数组和目标值
void print_arr(void *arr,int size,int elesize,void(*myprint)(void *data))
{
    //获取每个元素的首地址
    char *p=(char*)arr;
    for (size_t i = 0; i < size; i++)
    {
        myprint(p+i*elesize);
    }
}
void myprint_int(void *data)
{
    int *p=(int*)data;
    printf("%d ",*p);

}
struct person
{
    char name[64];
    int age;
};
void myprint_person(void *data)
{
    struct person *p=(struct person *)data;
    printf("姓名:%s,年龄:%d\n",p->name,p->age);
    
}

//提供查找功能,查找对应的元素是否存在
int mycompare_stru(void *data,void *target)
{
    struct person *p=(struct person*)data;
    struct person *t=(struct person*)target;
    if(strcmp(p->name,t->name)==0&&p->age==t->age)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int find_ele(void *arr,void *target,int size,int elesize)
{
    //先找到每个元素首地址
    char *p=(char*)arr;
    for (size_t i = 0; i < size; i++)
    {
        if(mycompare_stru(p+i*elesize,target)==1)
        return 1;
    }
    return 0;
}

void test01()
{
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    print_arr(arr,size,sizeof(int),myprint_int);
    struct person parr[]=
    {
        {"张三",18},
        {"李四",28},
        {"王五",38}
    };
    print_arr(parr,sizeof(parr)/sizeof(parr[0]),\
        sizeof(struct person),myprint_person);
    struct person p1={"李四",48};
    if(find_ele(parr,&p1,sizeof(parr)/sizeof(parr[0]),sizeof(struct person)))
    printf("找到了\n");
    else
    {
        printf("没找到\n");
    }
}
int main()
{

    test01();
    system("pause");
    return 0;
}
