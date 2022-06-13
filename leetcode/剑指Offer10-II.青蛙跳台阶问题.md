```cpp
const int N = 1e9 + 7;
class Solution {
public:
    int numWays(int n) {
        // dp O(n) O(1)
        if(n == 1 || n == 0) return 1;
        int pre = 0, cur = 1;
        while(n --){
            long long t = (pre + cur) % N;
            pre = cur;
            cur = t;
        }

        return cur;
    }
};
```

