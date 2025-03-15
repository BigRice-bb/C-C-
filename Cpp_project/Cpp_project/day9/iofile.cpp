#include <iostream>
using namespace std;
#include<fstream>//c++读写文件的头文件
#include<string>
void test01()
{
    ofstream  ofs;//向文件输出--写文件
    ofs.open("test.txt",ios::out);
    if(! ofs.is_open())
    {
        perror("open error");
        return;
    }
    ofs<<"hello world"<<endl;
    ofs<<"hello world"<<endl;
    ofs.close();//关闭文件
}

void test02()
{
    ifstream ifs("test.txt",ios::in);
    if(! ifs.is_open())
    {
        perror("open error");
        return;
    }
    char buf[128];
    // while(ifs>>buf)//读到" "或\n会结束
    // {
    //     cout<<buf<<endl;
    // }
    //第二种读的方式
    // while(ifs.getline(buf,sizeof(buf)))//完整的读出每一行,不包含\n
    // {
    //     cout<<buf<<endl;
    // }
    //第三种读的方式
    string str;
    while(getline(ifs,str))//利用全局函数读出,每次读出一行,不包括\n
    {
        cout<<str<<endl;
    }
    ifs.close();
}

int main() {
    test02();
    system("pause");
    return EXIT_SUCCESS;
}