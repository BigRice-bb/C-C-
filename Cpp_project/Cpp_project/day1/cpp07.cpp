#include <iostream>
using namespace std;

struct person
{
    int age;
};

void allocateadd(person **p)
{
    *p=(person*)malloc(sizeof(person));
    (*p)->age=10;
}

void test01(person *p)
{
    allocateadd(&p);
    cout<<"p.age"<<p->age<<endl;
}

int main()
{
    person *p=NULL;
    test01(p);

    system("pause");
    return EXIT_SUCCESS;
}