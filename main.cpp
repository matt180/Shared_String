#include <MyString.h>


int main()
{
    MyString str("hello");
    std::cout << str;
    auto str2 = str;
    std::cout << str2;
    std::cout << str;
    str2 += MyString(nullptr);
    std::cout << str;
    str2 = MyString("dfdss");
    std::cout << str2;
    auto str3 = str;
    std::cout << str3;
    str += str2;
    str += 'b';
    std::cout << str2;
    std::cout << str;
    std::cout << str3;
    MyString str4 = str + str2 + 'c';
    std::cout << str4;
    std::cout << str2;
    std::cout << str;
    std::cout << str3;
    std::cin >> str4;
    std::cout << str4;
    std::cout << str2[4];
    str = str3;
    str[1] = 'm';
    std::cout << str4;
    std::cout << str2;
    std::cout << str;
    std::cout << str3;
    return 0;
}
