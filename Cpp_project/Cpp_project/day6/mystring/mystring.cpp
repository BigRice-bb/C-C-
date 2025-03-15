#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"
#include "mystring.h"

mystring::mystring(char *str)
{
    this->m_pstring=new char[strlen(str)+1];
    strcpy(this->m_pstring,str);
    this->m_size=strlen(this->m_pstring);
    cout<<"有参构造调用"<<endl;
}
mystring::mystring(const mystring &mystr)
{
    this->m_pstring = new char[strlen(mystr.m_pstring)+1];
    strcpy(this->m_pstring,mystr.m_pstring);
    this->m_size=mystr.m_size;
    cout<<"拷贝函数构造"<<endl;
}

void mystring::m_show()
{
    cout<<"字符串为："<<this->m_pstring<<endl;
    cout<<"大小为："<<this->m_size<<endl;
}

int mystring::m_getsize()
{
    cout<<this->m_size<<endl;
    return this->m_size;
}

mystring &mystring::operator=(const char *str)
{
    //先清空堆区空间，一会重新分配
    if(this->m_pstring!=NULL)
    {
        delete [] this->m_pstring;
        this->m_pstring=NULL;
    }
    this->m_pstring=new char[strlen(str)+1];
    strcpy(this->m_pstring,str);
    this->m_size=strlen(str);
    return *this;
    // TODO: 在此处插入 return 语句
}

mystring &mystring::operator=(const mystring &str)
{
    //先清空堆区空间，一会重新分配
    if(this->m_pstring!=NULL)
    {
        delete [] this->m_pstring;
        this->m_pstring=NULL;
    }
    this->m_pstring=new char[strlen(str.m_pstring)+1];
    strcpy(this->m_pstring,str.m_pstring);
    this->m_size=str.m_size;
    return *this;
    // TODO: 在此处插入 return 语句
}

char& mystring::operator[](int num)
{
    return this->m_pstring[num];
}

mystring mystring::operator+(const mystring &str2)
{
    //先开辟空间，再把字符放进去；
    int len=strlen(this->m_pstring)+strlen(str2.m_pstring);
    char *buf=new char[len+1];
    memset(buf,0,len+1);
    strcat(buf,this->m_pstring);
    strcat(buf,str2.m_pstring);
    mystring str=buf;
    delete [] buf;
    return str;
    // TODO: 在此处插入 return 语句
}

mystring mystring::operator+(const char *str)
{
    int len=strlen(this->m_pstring)+strlen(str);
    char *buf=new char[len+1];
    memset(buf,0,len+1);
    strcat(buf,this->m_pstring);
    strcat(buf,str);
    mystring str1=buf;
    delete [] buf;
    return str1;
}

bool mystring::operator==(const mystring str)
{
    if(!strcmp(this->m_pstring,str.m_pstring))
    {
        return true;
    }
    return false;
}

mystring::~mystring()
{
    if(this->m_pstring !=NULL)
    {
        delete[] this->m_pstring;
        this->m_pstring=NULL;
    }
    cout<<"析构函数调用"<<endl;
}

ostream &operator<<(ostream &cout, mystring &str)
{
    cout<<str.m_pstring<<endl;
    return cout;
    // TODO: 在此处插入 return 语句
}

istream& operator>>(istream &cin,mystring &str)
{
    if(str.m_pstring != NULL)
    {
        delete [] str.m_pstring;
    }

    char buffer[1024];
    cin>>buffer;
    str.m_pstring=new char[strlen(buffer)+1];
    strcpy(str.m_pstring,buffer);
    str.m_size=strlen(buffer);
    return cin;
}
