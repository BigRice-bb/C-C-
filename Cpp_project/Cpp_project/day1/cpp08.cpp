#include <iostream>
using namespace std;

struct person
{
    int age;
};
void allocateadd(person* &addp)
{
    addp=(person *)malloc(sizeof(person));
    addp->age=10;
}
void test01(person *p)
{
    allocateadd(p);
    cout<<p->age<<endl;
}

int main()
{
    person *p=NULL;
    test01(p);
    system("pause");
    return EXIT_SUCCESS;
}