```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        /*Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. 
        O(n) O(1)*/
        int n = nums.size();
        if(n == 1) return nums[0];
        int pre1 = 0, pre2 = nums[0], ans = nums[0];
        for(int i = 1; i < n - 1; ++i){// 计算1到n - 1
            ans = max(pre2, pre1 + nums[i]);
            pre1 = pre2;
            pre2 = ans;
        }
        pre1 = 0, pre2 = nums[1];
        int ans1 = nums[1];
        for(int i = 2; i < n; ++i){// 计算2到n
            ans1 = max(pre2, pre1 + nums[i]);
            pre1 = pre2;
            pre2 = ans1;
        }
        return max(ans, ans1);
    }
};
```

