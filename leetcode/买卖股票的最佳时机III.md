```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* dp, O(n), O(n)
        */
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));

        // for(int i = 0; i < n; ++i){
        //     dp[i][0][0] = 0;// 如果没有进行任何一次交易,且没有持有股票(当然了), 那么dp值为0
        //     dp[i][0][1] = 0;// 如果没有进行任何一次交易,且持有股票(这是不可能的), 那么dp值设置为INT_MIN
        // }
        // // 第一天做两次交易,初始化相关dp值
        // dp[0][1][0] = 0, dp[0][1][1] = -prices[0], dp[0][2][0] = 0, dp[0][2][1] = -prices[0];
        // for(int i = 1; i < n; ++i){
        //     dp[i][1][1] = max(dp[i - 1][1][1], -prices[i]);
        //     dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        //     dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
        //     dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);            
        // }

        // return dp[n - 1][2][0];

        /* 优化dp O(n) O(1)*/
        int n = prices.size();
        // //仅仅对于第一天,做两次交易,那么可以得到以下变量的初始值
        int hold1 = -prices[0], sell1 = 0, hold2 = -prices[0], sell2 = 0;
        for(int i = 1; i < n ; ++i){
            hold1 = max(hold1, -prices[i]);
            sell1 = max(sell1, hold1 + prices[i]);
            hold2 = max(hold2, sell1 - prices[i]);
            sell2 = max(hold2 + prices[i], sell2);
        }

        return sell2;
    }
};
```

