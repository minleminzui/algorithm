/*
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-09-27 16:48:31
 */
// https://zhuanlan.zhihu.com/p/50816420
template <typename T> T &&forward(T &param) { return static_cast<T &&>(param); }