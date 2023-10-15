/*
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-09-27 18:40:29
 */
#include <bits/stdc++.h>
#include <condition_variable>
#include <mutex>

using namespace std;
// condition variable
condition_variable cv;
mutex mtx;

int ready = 0;

int main() {
  thread t1([&]() {
    for (int i = 0; i < 10; ++i) {
      unique_lock<mutex> lock(mtx);
      while (ready != 0)
        cv.wait(lock); // 如果ready != 0,不停的释放锁，并且阻塞
      cout << "A";
      ready = 1;
      cv.notify_one();
    }
  });
  thread t2([&]() {
    for (int i = 0; i < 10; ++i) {
      unique_lock<mutex> lock(mtx);
      while (ready != 1)
        cv.wait(lock); // 如果ready != 1,不停的释放锁，并且阻塞
      cout << "B";
      ready = 0;
      cv.notify_one();
    }
  });
  // thread t3([&]() {
  //   for (int i = 0; i < 10; ++i) {
  //     unique_lock<mutex> lock(mtx);
  //     while (ready != 2)
  //       cv.wait(lock); // 如果ready != 2,不停的释放锁，并且阻塞
  //     cout << "C";
  //     ready = 0;
  //     cv.notify_all();
  //   }
  // });
  t1.join();
  t2.join();
  // t3.join();
  return 0;
}