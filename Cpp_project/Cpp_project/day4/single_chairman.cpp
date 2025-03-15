#define _CRI_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

class chairman
{
    public:
    static chairman *getinstance()
    {
        return c1; 
    }

    private://私有化接口
    static chairman *c1;

    private:
    chairman()
    {
        cout<<"构造函数"<<endl;
    }
    chairman(const chairman&){}
};
chairman *chairman::c1=new chairman;

void test01()
{
    chairman*c2=chairman::getinstance(); 

}

int main()
{
    test01();
    system ("pause");
    return EXIT_SUCCESS;
}