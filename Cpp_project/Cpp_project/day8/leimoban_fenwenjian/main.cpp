#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "person.hpp"


void test01()
{
    person <string,int> p("Tom",20);
    p.showPerson();
}
int main()
{
    test01();
    return EXIT_SUCCESS;
}