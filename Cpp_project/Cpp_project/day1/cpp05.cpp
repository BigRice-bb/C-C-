#include "iostream"
using namespace std;

namespace kingglory
{
    int sunwukongid = 10;
}

int main()
{
    //int sunwukongid = 20;
    //重复声明会导致错误
    using kingglory::sunwukongid;
    cout<<sunwukongid<<endl;
    system("pause");
    return EXIT_SUCCESS;
}