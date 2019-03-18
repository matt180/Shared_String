#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <iostream>
#include <cstring>

class MyString {
    private:
        void destruct();

    public:
        explicit MyString(const char* str = "");

        MyString(const MyString& other)
            : len_(other.len_)
            , str_(other.str_)
            , refcount_(other.refcount_) {
                if (str_) {
                    ++(*refcount_);
                }
        }

        MyString(MyString&& other);

        size_t size() const {
            return len_;
        }

        MyString& operator=(const MyString& other);

        MyString& operator=(MyString&& other);

        MyString& operator+=(const MyString& other);

        ~MyString();

        friend std::ostream& operator<<(std::ostream& os, const MyString& my_str);

    private:

        size_t len_{0};
        char* str_{nullptr};
        int* refcount_{nullptr};
};

MyString operator+(MyString lhs, const MyString& rhs);

#endif // MYSTRING_H_INCLUDED
