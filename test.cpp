#include "mystring.h"

int main()
{
    {//Constructors
        MyString str_empty{};
        std::cout << str_empty << " " << str_empty.get_refcount() << std::endl;
        MyString str{"alma"};
        std::cout << str << " " << str.get_refcount() << std::endl;
    }
    {//copy
        MyString str{"korte"};
        MyString str_copy = str;
        std::cout << str << " " << str_copy << " " << str.get_refcount() << std::endl;
        str = MyString{"hello"};
        std::cout << str << " " << str.get_refcount() << std::endl;
        std::cout << str_copy << " " << str_copy.get_refcount() << std::endl;
    }
    {//move
        MyString str{"move"};
        MyString str_move = std::move(str);
        std::cout << str_move << " " << str_move.get_refcount() << " " << str.get_refcount() << std::endl;
        str = std::move(str_move);
        std::cout << str << " " << str_move.get_refcount() << " " << str.get_refcount() << std::endl;
    }
    {//összefûzés
        MyString str1{"alma"};
        MyString str2{"fa"};
        MyString str3 = str2;
        MyString osszeg = str1 + str2;
        std::cout << osszeg << " " << osszeg.get_refcount() << std::endl;
        str1 += str2;
        std::cout << str1 << " " << str1.get_refcount() << std::endl;
        str2 += MyString{};
        std::cout << str2 << " " << str2.get_refcount() << std::endl;
        str2 += MyString{"haz"};
        std::cout << str2 << " " << str2.get_refcount() << std::endl;
        std::cout << str3 << " " << str3.get_refcount() << std::endl;
    }
    {//osszefûzés karakterrel
        MyString str1{"ab"};
        MyString str2 = str1;
        str1 += 'c';
        std::cout << str1 << " " << str1.get_refcount() << std::endl;
        std::cout << str2 << " " << str2.get_refcount() << std::endl;
        MyString abc = str2 + 'c';
        std::cout << abc << " " << abc.get_refcount() << std::endl;
        std::cout << str2 << " " << str2.get_refcount() << std::endl;
    }
    {//indexelés
        MyString str1{"hello"};
        MyString str2 = str1;
        str1[0] = 'b';
        std::cout << str1 << " " << str1.get_refcount() << std::endl;
        std::cout << str2 << " " << str2.get_refcount() << std::endl;
        const MyString const_str{"konstans"};
        std::cout << const_str[2] << std::endl;
        try {
            const_str[11];
        } catch(std::out_of_range& e) {
            std::cout << e.what() << " kivetel elkapva" << std::endl;
        }
    }
    {//input kérés és hossz lekérdezése
        MyString str;
        std::cin >> str;
        std::cout << str << " " << str.size() << std::endl;
    }
    return 0;
}
