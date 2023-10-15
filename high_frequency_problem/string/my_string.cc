/*
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-08-15 22:13:52
 */
#include <cstddef>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class MyString {
private:
  char *c_ptr_;

public:
  MyString(const char *initString) { // constructor

    if (initString != nullptr) {
      c_ptr_ = new char[strlen(initString) + 1];
      strcpy(c_ptr_, initString);
    } else {
      c_ptr_ = nullptr;
    }
  }

  MyString(const MyString &copySource) // Copy constructor
  {
    c_ptr_ = nullptr;
    if (copySource.c_ptr_ != nullptr) {
      c_ptr_ = new char[strlen(copySource.c_ptr_) + 1];

      strcpy(c_ptr_, copySource.c_ptr_);
    }
  }

  MyString &operator=(const MyString &copySource) {
    if ((this != &copySource) && (copySource.c_ptr_ != nullptr)) {
      if (c_ptr_ != nullptr) {
        delete[] c_ptr_;
      }

      c_ptr_ = new char[strlen(copySource.c_ptr_) + 1];

      strcpy(c_ptr_, copySource.c_ptr_);
    }

    return *this;
  }

  MyString &operator=(MyString &copySrc) {
    if (this != &copySrc && copySrc != nullptr) {
      if (c_ptr_ != nullptr) {
        delete[] c_ptr_;

        c_ptr_ = new char[strlen(copySrc.c_ptr_) + 1];
        strcpy(c_ptr_, copySrc.c_ptr_);
      }
    }

    return *this;
  }
  MyString &operator=(MyString &&moveSrc) {
    if (moveSrc.c_ptr_ != nullptr && this != &moveSrc) {
      delete[] c_ptr_;

      c_ptr_ = moveSrc.c_ptr_;
      moveSrc.c_ptr_ = nullptr;
    }

    return *this;
  }

  MyString(MyString &&moveSource) {
    if (moveSource.c_ptr_ != nullptr) {
      c_ptr_ = moveSource.c_ptr_;
      moveSource.c_ptr_ = nullptr;
    }
  }

  MyString operator+(const MyString &other) {
    MyString ret("");
    ret.c_ptr_ = new char[GetLength() + other.GetLength() + 1];

    strcpy(ret.c_ptr_, this->c_ptr_);
    strcat(ret.c_ptr_, other.c_ptr_);

    return ret;
  }

  void append(const MyString &other) {
    strcat(this->c_ptr_, other.c_ptr_);

    return;
  }

  void append(const char *c) {
    strcat(this->c_ptr_, c);
    return;
  }
  operator const char *() { return c_ptr_; } // 类型强转符号

  const char &operator[](size_t index) const {
    if (index < GetLength()) {
      return c_ptr_[index];
    }

    throw "out of index";
  }
  ~MyString(void) {
    if (c_ptr_ != nullptr) {
      delete[] c_ptr_;
    }
  }

  size_t GetLength() const { return strlen(c_ptr_); }

  const char *GetString() const { return c_ptr_; }
};

int main() {
  MyString string1("Hello ");
  MyString string2("World");
  string str = " abc";
  MyString string3 = string1 + string2;
  cout << string1 << string2 << str << endl;
  string1.append(string2);
  cout << string1;
}