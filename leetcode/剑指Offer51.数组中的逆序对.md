```cpp
class Solution {
public:
    int ans = 0;
    vector<int> temp;
    void merge(vector<int> &nums, int l, int r) {
        if (l >= r) return;

        int m = (l + r) >> 1;

        merge(nums, l, m), merge(nums, m + 1, r);
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) {
            if (nums[i] > nums[j]) {
                temp[k++] = nums[j++];
                ans += m - i + 1;
            } else {
                temp[k++] = nums[i++];
            }
        }

        while (i <= m) temp[k++] = nums[i++];
        while (j <= r) temp[k++] = nums[j++];

        for (int i = l; i <= r; ++i) nums[i] = temp[i];
    }
    int reversePairs(vector<int>& nums) {
        // 归并排序 O(nlogn) O(n)
        temp = vector<int>(nums.size());
        merge(nums, 0, nums.size() - 1);

        return ans;
    }
};
```

