#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <iostream>
#include <cstring>
#include <exception>

class MyString {
    private:
        void destruct() noexcept;

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

        MyString(MyString&& other) noexcept;

        size_t size() const noexcept {
            return len_;
        }

        MyString& operator=(const MyString& other);

        MyString& operator=(MyString&& other) noexcept;

        MyString& operator+=(const MyString& other);

        MyString& operator+=(const char c);

        char operator[](int ind) const {
            if (ind < 0 || (size_t)ind >= len_) {
                throw std::out_of_range("tulindexeles");
            }
            return str_[ind];
        }

        char& operator[](int ind);

        ~MyString() noexcept;

        friend std::ostream& operator<<(std::ostream& os, const MyString& my_str);

        friend std::istream& operator>>(std::istream& is, MyString& my_str);

    private:

        size_t len_{0};
        char* str_{nullptr};
        int* refcount_{nullptr};
};

MyString operator+(MyString lhs, const char c);

MyString operator+(MyString lhs, const MyString& rhs);

#endif // MYSTRING_H_INCLUDED
