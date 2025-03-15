#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linklist.h"

void test01()
{
    linknode *head=init_linklist();
    show_linklist(head);
    insert_linknode(head,3,2);
    show_linklist(head);
    delete_linknode(head,3);
    show_linklist(head);
    clear_linklist(head);
    show_linklist(head);
}
void test02()
{
    linknode *head=init_linklist();
    show_linklist(head);
    head=reverse_linklist(head);
    show_linklist(head);
}

int main()
{

    test02();
    system("pause");
    return 0;
}