#include"zhan_shunxu_category.h"


//栈的初始化
SeqStack init_SeqStack()
{
    SStack* stack = (SStack*)malloc(sizeof(SStack));//堆区创建一个栈
    if (stack== NULL)
    {
        return NULL;
    }
    stack->size = 0;
    memset(stack->data,0,sizeof(void*)*MAX);
    return (void*)stack;
}
//入栈
void push_SeqStack(SeqStack stack, void* data)
{
    if (stack== NULL)
    {
        return;
    }
    if (data== NULL)
    {
        return;
    }
    SStack* mystack = (SStack*)stack;//数据类型转换
    if (mystack->size==MAX)
    {
        printf("栈已满，无法入栈\n");
        return;
    }
    mystack->data[mystack->size] = data;
    mystack->size++;
}
//出栈
void pop_SeqStack(SeqStack stack)
{
    SStack* mystack = (SStack*)stack;
    if (mystack==NULL)
    {
        return ;
    }
    
    if (mystack->size == 0)
    {
        return ;
    }
    else
    {
        mystack->size--;
    }
}
//返回栈顶元素
void* top_SeqStack(SeqStack stack)
{
    if (stack==NULL)
    {
        return NULL;
    }
    
    SStack* mystack = (SStack*)stack;
    return mystack->data[mystack->size-1];

}
//返回栈的大小
int size_SeqStack(SeqStack stack) 
{
    if (stack==NULL)
    {
        return -1;
    }
    
    SStack* mystack = (SStack*)stack;
    return mystack->size;
}
//销毁栈
void destroy_SeqStack(SeqStack stack)
{
    if (stack==NULL)
    {
        return;
    }
    SStack* mystack = (SStack*)stack;
    free(mystack);
    mystack = NULL;
}

// struct person
// {
//     char name[64];
//     int age;
// };

// void test01()
// {
//     SeqStack stack = init_SeqStack();
//     struct person p1 = {"aaa",10};
//     struct person p2 = {"bbb",20};
//     struct person p3 = {"ccc",30};
//     struct person p4 = {"ddd",40};
//     struct person p5 = {"eee",50};
//     push_SeqStack(stack, &p1);
//     push_SeqStack(stack, &p2);
//     push_SeqStack(stack, &p3);
//     push_SeqStack(stack, &p4);
//     push_SeqStack(stack, &p5);
//     printf("栈的大小为：%d\n", size_SeqStack(stack));
//     while (size_SeqStack(stack)>0)
//     {
//         struct person* p = (struct person*)top_SeqStack(stack);
//         printf("姓名：%s 年龄：%d\n",p->name,p->age);
//         pop_SeqStack(stack);
//     }
//     destroy_SeqStack(stack);

// }
// int main()
// {

//     test01();
//     system("pause");
//     return 0;
// }
