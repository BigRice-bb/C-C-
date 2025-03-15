#define _CRI_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>


class printer
{
    public:
        static printer *getinstance()
        {
            return hp;
        }
        void scan(string sth)
        {
            count++;
            cout<<sth<<endl;
        }
        int count;
    private:
        static printer *hp;
        printer(const printer &);
        printer() 
        {
            count=0;
            cout<<"构造函数调用"<<endl;
        };
};
printer *printer::hp=new printer ;

void test01()
{
    printer *hps40=printer::getinstance();
    hps40->scan("1");
    hps40->scan("2");
    hps40->scan("3");
    hps40->scan("4");
    cout<<hps40->count<<endl;
    printer *hps66=printer::getinstance();
    hps66->scan("1");
    cout<<hps66->count<<endl;
    //同一个count，hps40和hps66是同一个地址
}

int main()
{

    test01();
    system("pause");
    return EXIT_SUCCESS;
}