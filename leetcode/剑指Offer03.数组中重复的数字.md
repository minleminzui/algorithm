<!--
 * @Author: yitong 2969413251@qq.com
 * @Date: 2022-12-22 21:26:08
-->
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 原地交换 O(n) O(1)
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == i) continue;
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }

        return 0;
    }
};
```