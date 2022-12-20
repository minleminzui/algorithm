`回溯 dfs`

- 代码实现时，可以先将数组排序；选择数时，若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。


`时间复杂度:`O(n * 2 ^ n),所有子集为2 ^ n, 复制子集加入答案时间是O(n)
`空间复杂度:`O(n)，递归栈为O(n)，迭代中的临时数组O(n)

```
class Solution {
private:
    vector<vector<int>> ans;
    vector<bool> vis;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vis.resize(nums.size());
        vector<int> now;
        dfs(now, 0, nums);
        return ans;
    }

    void dfs(vector<int> &now, int level, vector<int>& nums){
        ans.push_back(now);

        for(int i = level; i < nums.size(); ++i){
            if(i && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            now.push_back(nums[i]);
            vis[i] = true;
            dfs(now, i + 1, nums);
            vis[i] = false;
            now.pop_back();
            
        }
    }
};
//利用二进制的更优解
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};

```

```go
type MyType []int

func (n MyType) Less(i, j int) bool {
    return n[i] < n[j]
}

func (n MyType) Len() int {
    return len(n)
}

func (n MyType) Swap(i, j int) {
    n[i], n[j] = n[j], n[i]
}

func subsetsWithDup(nums MyType) [][]int {
    sort.Sort(nums)

    var res [][]int
    var now []int
    vis := make([]bool, len(nums))
    help(now, nums, 0, &res, vis)
    return res
}

func help(now, nums []int, index int, res *[][]int, vis []bool) {
    temp := make([]int, len(now))
    copy(temp, now)
    *res = append(*res, temp)

    // 选或者不选
    for i := index; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i - 1] && !vis[i - 1] {
            continue
        }
        vis[i] = true
        now = append(now, nums[i])
        help(now, nums, i + 1, res, vis)
        vis[i] = false
        now = now[:len(now) - 1]
    }
}
```

