#include "iostream"
using namespace std;

int atk=1000;
void test01()
{
    int atk=2000;
    cout<<"atk="<<atk<<endl;
    cout<<"atk="<<::atk<<endl;
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}