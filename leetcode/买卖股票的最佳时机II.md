```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*  未优化dp, dp[i][0]表示第i天未持有股票的最大收益,i从0开始
            dp[i][1]表示第i天未持有股票的最大收益,转移方程可以是:
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]) 也就是卖或者不卖
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]) 也就是买或者不买
            
            最后的结果是dp[n - 1][0],不能持有股票
            O(n) O(n)
        */
        // auto n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2));
        // dp[0][1] -= prices[0], dp[0][0] = 0;
        // for(int i = 1; i < n; ++i){
        //     dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        //     dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        // }
        // return dp[n - 1][0];

        /* 优化dp,注意到dp[i][0]与dp[i][1]只需要使用到i - 1的状态,不需要使用i - 2,i - 3...的状态
            故可以把空间复杂度优化为O(1)       
        */
        // int n = prices.size();
        // int hold = -prices[0], sell = 0;
        // for(int i = 1; i < n; ++i){
        //     int newsell = max(sell, hold + prices[i]);
        //     int newhold = max(hold, sell - prices[i]); 
        //     sell = newsell;
        //     hold = newhold;
        // }

        // return sell;

        /* 贪心, 只在股票上升段买卖股票 O(n) O(1)*/
        int n = prices.size();
        int ans = 0;
        for(int i = 1; i < n; ++i){
            ans += max(0, prices[i] - prices[i - 1]);
        }

        return ans;
    }
};
```

