#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    MyString str1;
    MyString str2("str2");
    MyString str3=str2; //拷贝构造函数

    str1=str2;   //=操作符重载
    str1=NULL;
    str1="str3";

    cout<<str1<<endl;
    cout<<str2.c_str()<<endl;
    //str1+=str2;
    str1+=str1;
    cout<<str1<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
