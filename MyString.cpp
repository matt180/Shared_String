#include <MyString.h>

MyString::MyString(const char* str) {
    if (str) {
        len_ = strlen(str) + 1;
        str_ = new char[len_];
        refcount_ = new int{1};
    }
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        destruct();
        len_ = other.len_;
        str_ = other.str_;
        if (str_) {
            ++(*refcount_);
        }
    }
    return *this;
}

void MyString::destruct() {
    if (str_) {
        --(*refcount_);
        if (*refcount_ == 0) {
            delete refcount_;
            delete str_;
        }
    }
}

MyString::~MyString() {
    destruct();
}
