#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"

class mystring
{
    friend ostream &operator<<(ostream &cout, mystring &str);
    friend istream& operator>>(istream &cin,mystring &str);
public:
    mystring(char *str);
    mystring(const mystring & mystr );
    void m_show();
    int m_getsize();
    mystring& operator=(const char* str);
    mystring& operator=(const mystring &str);
    char& operator[](int num);
    mystring operator+(const mystring &str2);
    mystring operator+(const char * str);
    bool operator==(const mystring str);

    ~mystring();

private:
    char *m_pstring;
    int m_size;
};
//重载左移运算符
ostream& operator<<(ostream &cout, mystring &str);
//重载右移操作符
istream& operator>>(istream &cin,mystring &str);