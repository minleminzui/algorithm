```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 排序 O(nlogn) O(n)
        // 最大值和最小值之间的数字个数不能大于零的个数与在数组中它们之间的数的和
        sort(nums.begin(), nums.end());
        
        int i = 0;
        for (i = 0; i < 4; ++i) {
            if (nums[i] != 0 && nums[i] == nums[i + 1]) {
                return false;
            }
        }
        i = 0;
        while (i < 5 && nums[i] == 0) ++i;
        if (nums[4] - nums[i] - i  - 1 - (4 - i - 1) <= 0) {
            return true;
        }
        return false;
    }
};

// 2 4 5 7 9
```