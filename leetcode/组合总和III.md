`dfs 回溯` 

方法一：

temp就是我写的t![img](https://img2022.cnblogs.com/blog/1743182/202202/1743182-20220211165223357-1636464960.png)

方法二：

![](https://img2022.cnblogs.com/blog/1743182/202202/1743182-20220211165239961-179998349.png)

M里取k个数


```cpp
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> t;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> now;
        // dfs(now, k, n, 1);
        for(int i = 0; i < (1 << 9); ++i){
            check(i, k, n);
        }
        return ans;
    }

    void check(int i, int k, int n){
        t.clear();
        for(int k = 0; k < 9; ++k){
            if((i >> k) & 1){
                t.push_back(k + 1);
            }
        }
        if(t.size() == k && accumulate(t.begin(), t.end(), 0) == n){
            ans.emplace_back(t);
        }
    }
    // void dfs(vector<int>& now, int k, int n, int num){
    //     if(num > 10 || k < 0 || n < 0) return;
    //     if(k == 0 && n == 0){
    //         ans.push_back(now);
    //         return;
    //     }
        
    //     now.push_back(num);
    //     dfs(now, k - 1, n - num, num + 1);
    //     now.pop_back();

    //     dfs(now, k, n, num + 1);
    // }
};
```

