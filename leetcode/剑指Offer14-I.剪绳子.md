```cpp
class Solution {
public:
    int cuttingRope(int n) {
    // You're making it pretty complicated.

    // If an optimal product contains a factor f >= 4, then you can replace it with factors 2 and f-2 without losing optimality, as 2*(f-2) = 2f-4 >= f. So you never need a factor greater than or equal to 4, meaning you only need factors 1, 2 and 3 (and 1 is of course wasteful and you'd only use it for n=2 and n=3, where it's needed).

    // For the rest I agree, 3*3 is simply better than 2*2*2, so you'd never use 2 more than twice.
        // 数学 O(1) O(1)
        if (n <= 3) {
            return n - 1;
        }
        int remainder = n % 3;
        int quotient = n / 3;
        
        if (remainder == 0) {
            return (int)pow(3, quotient);
        } else if(remainder == 1) {
            return (int)pow(3, quotient - 1) * 4;
        } else {
            return (int)pow(3, quotient) * 2;
        }
    }
};
```