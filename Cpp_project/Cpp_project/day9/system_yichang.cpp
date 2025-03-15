//c++的系统标准异常
#include <iostream>
using namespace std;
#include <stdexcept>//系统标准异常的头文件

class person
{
public:
    person(int age)
    {
        if(age<0 || age>150)
        {
            throw out_of_range("年龄不符合规定..");
        }
        else{
            this->m_age=age;
        }
    }
    int m_age;
};
void test01()
{
    try
    {
        person p(151);
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
int main() {
    test01();
    system("pause");
    return EXIT_SUCCESS;
}