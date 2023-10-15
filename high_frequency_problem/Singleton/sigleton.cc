/*
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-08-20 13:53:04
 */
#include <iostream>

// 线程不安全的懒汉式单例模型
// class Singleton {
// public:
//   static Singleton *GetInstance();
//   static void DeleteInstance();
//   // 将拷贝构造和拷贝赋值设置为delete
//   Singleton(const Singleton &obj) = delete;
//   Singleton &operator=(const Singleton &obj) = delete;

// private:
//   Singleton();
//   ~Singleton();

//   static Singleton *m_pObject;
// };

// 程序一运行，就立马初始化单例实例

class Singleton {
public:
  static Singleton &GetInstance();
  Singleton(const Singleton &obj) = delete;
  Singleton &operator=(const Singleton &obj) = delete;
  Singleton(const Singleton &&obj) = delete;
  Singleton &operator=(const Singleton &&obj) = delete;

private:
  Singleton();
  ~Singleton();
};

Singleton &Singleton::GetInstance() {
  static Singleton obj;

  return obj;
}