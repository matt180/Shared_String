#include <iostream>
#include <MyString.h>


int main()
{
    MyString str("hello");
    auto str2 = str;
    str2 = MyString("dgasdg");
    return 0;
}
