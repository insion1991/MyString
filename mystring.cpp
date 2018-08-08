#include "mystring.h"
#include <string.h>

MyString::MyString()
{
    m_len=0;
    m_p=new char[m_len+1];
    strcpy(m_p,"");
}
//带参数构造函数
MyString::MyString(const char* p)
{
    if (p== NULL)
    {
        m_len=0;
        m_p=new char[m_len+1];
        strcpy(m_p,"");
    }
    else
    {
        m_len =strlen(p);
        m_p=new char[m_len+1];
        strcpy(m_p,p);
    }
}
//拷贝构造函数
MyString::MyString(const MyString& obj)
{
    //m_len = strlen(obj.m_p);
    m_len = obj.m_len;
    m_p =new char[m_len+1];
    strcpy(m_p,obj.m_p);
}
//=号操作符重载(只能重载成类的成员函数)，是类的成员函数
MyString& MyString::operator=(const MyString& obj)
{   //检查是否是自赋值
    if (this == &obj)
    {
        return *this;
    }
    //释放旧的资源
    if (m_p !=NULL)
    {
        delete[] m_p;
        m_len=0;
    }
    m_len=obj.m_len;
    m_p=new char[m_len+1];
    strcpy(m_p,obj.m_p);

    return *this;  //注意
}
//使用情况str1="str3"; str1=NULL;
MyString& MyString::operator=(const char *p)
{
    if (m_p !=NULL)
    {
        delete[] m_p;
        m_len=0;
    }
    if (p ==NULL)  //要注意
    {
        m_len=0;
        m_p=new char[m_len+1];
        strcpy(m_p,"");
    }
    else
    {
        m_len = strlen(p);
        m_p=new char[m_len+1];
        strcpy(m_p,p);
    }
    return *this;
}
//<< 操作符重载，只能重载成全局友元函数，
ostream& operator<<(ostream& out,const MyString& s1)
{
    out<<s1.m_p;
    return out;
}

MyString& MyString::operator+=(const MyString& obj)
{
    char* temp=m_p;
    m_len=m_len+obj.m_len;
    m_p=new char[m_len+1];
    strcpy(m_p,temp);
    strcat(m_p,obj.m_p);
    delete[] temp;
    return *this;
}

MyString:: ~MyString()
{
    if (m_p != NULL)
    {
        delete[] m_p; //注意
        m_len=0;
        m_p=NULL;
    }
}
