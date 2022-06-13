```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp O(n) O(1)
        int n = nums.size();
        int ans = nums[0];
        int now = nums[0];
        for (int i = 1; i < n; ++i) { 
            if (now > 0) {
                now += nums[i];
            } else {
                now = nums[i];
            }
            
            ans = max(now, ans);
        }

        return ans;
    }
};
```

