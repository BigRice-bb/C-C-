#include "iostream"
#include "game1.h"
#include "game2.h"
using namespace std;

namespace a
{
    int zz=10;
    namespace b
    {
        int zz=20;
    }

}

void test02()
{
    cout<<"a空间下的zz="<<a::zz<<endl;
    cout<<"b空间下的zz="<<a::b::zz<<endl;
}
void test01()
{
    kingglory::goAtk();
    lol::goAtk();
}

namespace a
{
    int zzz=100;
}
int main()
{
    test01();
    test02();
    cout<<a::zzz<<endl;
    system("pause");
    return EXIT_SUCCESS;
}