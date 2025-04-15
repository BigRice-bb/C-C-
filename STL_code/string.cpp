#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;

void test01()
{
    //string的构造函数
    string str1;//默认构造函数
    string str2("hello world");//字符串常量构造函数
    //string str3(str2);//拷贝构造函数
    string str3=str2;//拷贝构造函数
    string str4(10,'a');//重复字符构造函数
    string str5(str2,0,5);//字符串截取构造函数
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
}
//string的赋值操作
void test02()
{
    //string重载了赋值操作符= 三种方式
    //1.直接赋值 char* char& char
    //2.使用assign函数赋值 str.assign(str1) str.assign(str1,0,5) str.assign(10,'a')
    string str1;
    str1="hello world";
    cout<<str1<<endl;
    string str2;
    str2=str1;
    cout<<str2<<endl;
    string str3;
    str3.assign(str1);
    cout<<str3<<endl;
    string str4;
    str4.assign(str1,0,5);
    cout<<str4<<endl;
    string str5;
    str5.assign(10,'a');
    cout<<str5<<endl;
}
//string存取字符操作
void test03()
{
    //1,重载了[]操作符
    //2,使用at函数访问字符
    string str1="hello world";
    for (int i = 0; i < str1.size(); i++)
    {
        //cout<<str1[i];
        cout<<str1.at(i);
    }
    cout<<endl;
    //3,使用front函数访问第一个字符
    cout<<str1.front()<<endl;
    //4,使用back函数访问最后一个字符
    cout<<str1.back()<<endl;

    //[]和at的区别 []越界会直接报错 at越界会抛出异常
    try
    {
        //cout<<str1[100]<<endl;
        cout<<str1.at(100)<<endl;
    }
    catch(out_of_range& e)
    {
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"越界了"<<endl;
    }
}
//string的拼接和查找和替换
void test04()
{
    // //1,重载了+=操作符
    // //2,使用append函数拼接字符串 str.append(str1) str.append(str1,0,5) str.append(10,'a')
    // string str1="hello";
    // string str2="world";
    // // str1+=str2;
    // // cout<<str1<<endl;
    // str1.append(str2);
    // cout<<str1<<endl;

    //查找 字符串 find函数
    // string str3="hello world";
    // int pos = str3.find("ll");//返回字符串中第一个匹配的字符的位置
    // cout<<pos<<endl;//没找到返回-1
    // //rfind函数从右边开始查找
    // int pos2 = str3.rfind("ll");//返回字符串中第一个匹配的字符的位置
    // cout<<pos2<<endl;//没找到返回-1

    //替换replace函数
    string str4="hello world";
    str4.replace(0,5,"hi");//从0开始替换5个字符为hi
    cout<<str4<<endl;
}
//解析字符串
//www.itcast.com.cn  将子串截取到vector容器中
void test05()
{
    string str1="www.itcast.com.cn";
    vector<string> v;
    //使用find函数查找.的位置
    int pos = str1.find(".");
    while (pos != -1)
    {
        //使用substr函数截取子串
        string sub = str1.substr(0,pos);
        v.push_back(sub);
        str1 = str1.substr(pos+1);//从下一个位置开始截取
        cout<<str1<<endl;
        pos = str1.find(".");
    }
    //最后一个子串
    v.push_back(str1);
    //遍历容器
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<*it<<endl;
    }
}

//string 的比较操作
void test06()
{
    string str1="hello world";
    string str2="hello world";
    string str3="hello world!";
    //重载了== != < > <= >=操作符
    if (str1 == str2)
    {
        cout<<"str1 == str2"<<endl;
    }
    if (str1 != str3)
    {
        cout<<"str1 != str3"<<endl;
    }
    if (str1 < str3)
    {
        cout<<"str1 < str3"<<endl;
    }
    str1.compare(str2);
    cout<<str1.compare(str2)<<endl;//0相等 1 str1大于str2 -1 str1小于str2`
}
//string的插入和删除操作
void test07()
{
    string str1="hello world";
    //插入操作
    str1.insert(5,"123");//在5的位置插入123
    cout<<str1<<endl;
    //删除操作
    str1.erase(5,3);//从5开始删除3个字符
    cout<<str1<<endl;
}
//string和C风格字符串的转换
void test08()
{
    string str1="hello world";
    //string转const char*
    const char* cstr = str1.c_str();//返回一个指向字符串的常量指针
    cout<<cstr<<endl;
    //const char*转string
    const char* cstr2 = "hello world";
    string str2(cstr2);//使用构造函数转换
    cout<<str2<<endl;
}
int main() 
{
    test08();
    system("pause");
    return EXIT_SUCCESS;
}