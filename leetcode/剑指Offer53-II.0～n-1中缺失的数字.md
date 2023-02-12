<!--
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-02-12 18:54:26
-->
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 二分 O(logn) O(1)
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (m == nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return nums[l] == l ? l + 1 : l;
    }
};
```