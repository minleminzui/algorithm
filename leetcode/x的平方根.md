```cpp
class Solution {
public:
    int mySqrt(int x) {
        // O(1), O(1) 由于数据大小有限，我们可以二分限定次
        // long long m, l = 0, r = INT_MAX;
        // for(int i = 0; i < 31; ++i) {
        //     m = (l + r + 1) >> 1;
        //     if(m * m > x) r = m - 1; 
        //     else l = m;
        // }

        // return (int)l;

        // O(logx) O(1)
        // long long m, l = 0, r = INT_MAX;
        // while(l < r){
        //     m = (l + r + 1) >> 1;
        //     if(m * m > x) r = m - 1;
        //     else l = m;
        // }

        // return (int)l;

        // 牛顿迭代 O(logx),此法二次收敛，比二分更快， O(1)
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);

    }
};
```

