#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <cstring>

class MyString {
    public:
        explicit MyString(const char* str = "");

        MyString(const MyString& other)
            : str_(other.str_)
            , refcount_(other.refcount_) {
                if (str_) {
                    ++(*refcount_);
                }
        }

        size_t size() const {
            return len_;
        }

    private:
        void destruct();

    public:
        MyString& operator=(const MyString& other);

        ~MyString();


    private:

        size_t len_{0};
        char* str_{nullptr};
        int* refcount_{nullptr};
};

#endif // MYSTRING_H_INCLUDED
