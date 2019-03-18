#include <MyString.h>

MyString::MyString(const char* str) {
    if (str) {
        len_ = strlen(str);
        str_ = new char[len_ + 1];
        strcpy(str_, str);
        refcount_ = new int{1};
    }
}

MyString::MyString(MyString&& other)
    : len_(other.len_)
    , str_(other.str_)
    , refcount_(other.refcount_) {
    other.len_ = 0;
    other.str_ = nullptr;
    other.refcount_ = nullptr;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        destruct();
        len_ = other.len_;
        str_ = other.str_;
        refcount_ = other.refcount_;
        if (str_) {
            ++(*refcount_);
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    if (this != &other) {
        destruct();
        len_ = other.len_;
        other.len_ = 0;
        str_ = other.str_;
        other.str_ = nullptr;
        refcount_ = other.refcount_;
        other.refcount_ = nullptr;
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



MyString& MyString::operator+=(const MyString& other) {
    if (other.size() == 0) {
        return *this;
    }
    len_ = len_ + other.len_;
    char* tmp = new char[len_ + 1];
    strcpy(tmp, str_);
    strcat(tmp, other.str_);
    destruct();
    str_ = tmp;
    refcount_ = new int{1};
    return *this;
}

MyString operator+(MyString lhs, const MyString& rhs) {
    return MyString(lhs += rhs);
}

std::ostream& operator<<(std::ostream& os, const MyString& my_str) {
    return os << my_str.str_ << " " << *my_str.refcount_ << std::endl;
}
