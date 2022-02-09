`回溯 dfs`

两个方法都需要排序

- 方案一：

  - 用二进制位state标记位置是否可以放元素，保证某个位置只能够放置同样的元素一次，也就是说如果nums中存在两个相同的元素a与a，那么第二个a必须放到第一个a的后面去。
  - 我们选择对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」，排序能够保证相同的数字的相对顺序不变
- 方案二：
  - 任然需要排序，这次的思想是，每次固定最左边的一个数，之后在递归固定右边子序列的最左边的数，如果不排序，一个反例是，1 2 1 2，那么数字1可以出现在第一个位置两次，而如果排序了数字1就只会出现在第一个位置一次

`时间复杂度:`O(n * n!),n!个叶节点，每次还需要复制到ans数组中，需要O(n)的时间
`空间复杂度:`O(n)，递归深度为O(n)

```
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        path.resize(nums.size());
        dfs(nums, 0, 0, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int start, int u, int state){
        if(u == nums.size()){
            ans.push_back(path);
            return;
        }
        if(!u || nums[u] != nums[u - 1]) start = 0;
        for(int i = start; i < nums.size(); ++i){
            if(!(state >> i & 1)){
                path[i] = nums[u];
                dfs(nums, i + 1, u + 1, state + (1 << i));
            }
        }
    }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     // int size = nums.size();
    //     if(nums.size() == 0) return ans;
    //     sort(nums.begin(), nums.end());
    //     dfs(nums, 0);
    //     return ans;
    // }

    // void dfs(vector<int> nums, int d){
    //     if(d == nums.size() - 1){
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for(int i = d; i < nums.size();++i){
    //         if(i != d && nums[i] == nums[d]) continue;
    //         swap(nums[i], nums[d]);
    //         dfs(nums, d + 1);
    //     }
    // }
};
```