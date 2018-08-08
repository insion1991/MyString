#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <ostream>
using namespace std;

class MyString
{
public:
    MyString(); //无参构造函数
    MyString(const char *p);  //带参数构造函数
    MyString(const MyString& obj); //拷贝构造函数
        ~MyString();

public:  //操作符重载
    MyString& operator=(const MyString& obj);
    MyString& operator=(const char *p);
     //=号只能重载成成员函数，不能重载成友元全局函数
    //friend MyString& operator=(MyString& s1,const MyString& s2);

    //+号操作符重载，可以重载成类的成员函数，也可以重载成类的友元函数
    MyString& operator+=(const MyString& obj);
    //friend MyString& operator+(MyString& s1,const MyString& s2);

    //<<号操作符重载，可以重载成类的友元函数,但不能重载成类的成员函数
    //ostream& operator<<(ostream& out ,const MyString& obj);
    friend ostream& operator<<(ostream& out,const MyString& s1);

    bool operator==(const MyString& obj);
    bool operator!=(const MyString& obj);

    bool operator>(const MyString& obj);
    bool operator<(const MyString& obj);

    //返回对象指针
    const char* c_str()
    {
        return m_p;
    }
    int length()
    {
        return m_len;
    }

private:
    int m_len;
    char * m_p;
};

#endif // MYSTRING_H
