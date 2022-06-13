```cpp
class Solution {
public:
    int sumNums(int n) {
        // 递归 O(n) O(n)
        return n == 1 ? 1 : n + sumNums(n - 1); 
        // 位运算
        // bool a[n][n + 1];
        // return sizeof(a) >> 1;
    }
};
```

