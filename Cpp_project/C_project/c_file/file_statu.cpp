#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "sys/stat.h"

void test01()
{
    struct stat s1;
    stat("test.txt",&s1);
    cout<<s1.st_size<<endl;
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}