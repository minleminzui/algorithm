/*
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-08-16 19:14:00
 */
#include <cstddef>
#include <iostream>
using namespace std;

class share_count {
public:
  share_count() : _count(1) {}
  void add_count() { ++_count; }
  size_t reduce_count() { return --_count; }
  size_t get_count() const { return _count; }

private:
  size_t _count;
};

template <typename T> class smart_ptr {
public:
  smart_ptr(T *ptr = nullptr) : m_ptr(ptr) {
    if (ptr) {
      m_share_count = new share_count;
    }
  }

  ~smart_ptr() {
    if (m_ptr && !m_share_count->reduce_count()) {
      delete m_ptr;
      delete m_share_count;
    }
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  operator bool() const { return m_ptr; }

  size_t use_count() const {
    if (m_ptr) {
      return m_share_count->get_count();
    }
  }
  smart_ptr(const smart_ptr &rhs) noexcept {
    m_ptr = rhs.m_ptr;
    m_share_count = rhs.m_share_count;
    m_share_count->add_count();
  }

  smart_ptr &operator=(const smart_ptr &rhs) noexcept {
    m_ptr = rhs.m_ptr;
    m_share_count = rhs.m_share_count;
    m_share_count->add_count();
    return *this;
  }
  smart_ptr(smart_ptr &&rhs) noexcept {
    m_ptr = rhs.m_ptr;
    rhs.m_ptr = nullptr;
  }

  smart_ptr &operator=(smart_ptr &&rhs) noexcept {
    m_ptr = rhs.m_ptr;
    rhs.m_ptr = nullptr;
    return *this;
  }

private:
  T *m_ptr;
  share_count *m_share_count;
};

class Type {
public:
  int a = 1;
};

int main() {
  smart_ptr<Type> sptr(new Type);
  cout << "sptr's share_count：" << sptr.use_count() << endl;

  smart_ptr<Type> sptr2(sptr);
  cout << "sptr's share_count：" << sptr2.use_count() << endl;

  smart_ptr<Type> sptr3;
  sptr3 = sptr2;
  cout << "sptr's share_count：" << sptr3.use_count() << endl;
  return 0;
}
