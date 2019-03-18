#include <MyString.h>


int main()
{
    MyString str("hello");
    std::cout << str;
    auto str2 = str;
    std::cout << str2;
    std::cout << str;
    str2 = MyString("dgasdg");
    std::cout << str;
    std::cout << str2;
    auto str3 = str;
    std::cout << str3;
    str += str2;
    std::cout << str2;
    std::cout << str;
    std::cout << str3;
    MyString str4 = str + str2;
    std::cout << str4;
    std::cout << str2;
    std::cout << str;
    std::cout << str3;
    return 0;
}
