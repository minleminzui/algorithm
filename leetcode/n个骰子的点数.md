`线性dp`

- 方案一：

  - 递归计算n到6n这些和的方案总数

  - 方案总数和，每种和除以方案总数和
  - 不过会超时，n = 10, 11时

- 方案二：
  - dp\[i][j]表示掷了i个骰子，总和为j的方案数，那么dp\[i][j]与dp\[i][j - k]有关，k表示第i个骰子所投掷的点数，可以是1到min(j, 6)

`时间复杂度:`递归的时间复杂度为O(6^n), 而dp的时间复杂度为O(n^2),对于变量j，循环次数为6 + ... + (6 - 1) * n + 1,那么总的复杂度为O(6 * n * (6 + 5 * n + 1) / 2)
`空间复杂度:`递归的空间复杂度为O(6^n),而dp的空间复杂度为O(n^2)

```
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= 6 * i; ++j){
                for(int k = 1; k <= min(j, 6); ++k){
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        vector<double> ans;
        for(int i = n; i <= 6 * n; ++i) ans.push_back(dp[n][i]);
        double sum = accumulate(ans.begin(), ans.end(), 0);
        for(auto & i : ans) i /= sum;
        return ans;
    }


    // vector<double> dicesProbability(int n) {//递归会tle
    //     vector<double> ans;
    //     for(int i = n; i <= 6 * n; ++i) ans.push_back(dfs(n, i));
    //     double sum = accumulate(ans.begin(), ans.end(), 0);
    //     for(auto& i : ans) i /= sum;
    //     return ans;
    // }

    // int dfs(int n, int sum){
    //     if(sum < 0) return 0;
    //     if(n == 0) return !sum;

    //     int res = 0;
    //     for(int i = 1; i <= 6; ++i){
    //         res += dfs(n - 1, sum - i);
    //     }
    //     return res;
    // }
};
```