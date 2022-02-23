```cpp
class Solution {
    unordered_map<string, bool> m;
    vector<string> ans;
    int n;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        n = s.size();
        // 这里用dp判断是否存在解
        // vector<bool> f(n + 1);
        // f[0] = true;

        

        // for(int i = 1; i <= n; ++i){
        //     for(auto &j : wordDict){
        //         int len = j.size();
        //         if(i >= len && s.substr(i - len, len) == j){
        //             f[i] = f[i] || f[i - len];
        //         }
        //     }
        // }
        
        // if(f[n] == false) return ans;
        // 时间复杂度上界为O(2 ^ n), 也就是选或者不选每个字母
        vector<vector<int>> dp(n);
        for(auto i : wordDict){
            m[i] = true;
        }
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                string sub = s.substr(i, j - i + 1);
                if(m[sub]){
                    dp[i].emplace_back(j);
                }
            }
        }
        vector<string> item;
        dfs(s, 0, dp, item);
        return ans;
    }

    void dfs(string s, int now, vector<vector<int>> &dp, vector<string> &item){
        if(now == n){
            string solution;
            for(int i = 0; i < item.size(); ++i){
                solution += item[i] + " ";
            }
            solution.pop_back();
            ans.emplace_back(solution);
            return;
        }
        for(int i = 0; i < dp[now].size(); ++i){
            int len = dp[now][i] - now + 1;
            item.emplace_back(s.substr(now, len));
            dfs(s, now + len, dp, item);
            item.pop_back();
        }
    }
};

// y总的做法与我类似，但是是逆向来的，空间复杂度与代码复杂度小一些
// class Solution {
// public:
//     vector<string> ans;
//     unordered_map<string, int> dict;

//     vector<string> wordBreak(string s, vector<string>& wordDict) {

//         for (auto &word : wordDict) dict[word] = 1;
//         int n = s.size();
//         vector<bool>f(n + 1, true);
//         for (int i = 1; i <= n; i ++ )
//         {
//             f[i] = false;
//             for (int j = 0; j < i; j ++ )
//                 if (dict[s.substr(j, i - j)] && f[j])
//                 {
//                     f[i] = true;
//                     break;
//                 }
//         }

//         dfs(f, s, "", n);
//         return ans;
//     }

//     void dfs(vector<bool>&f, string &s, string path, int u)
//     {
//         if (!u)
//         {
//             ans.push_back(path.substr(0, path.size() - 1));
//             return ;
//         }

//         for (int i = 0; i < u; i ++ )
//             if (dict[s.substr(i, u - i)] && f[i])
//                 dfs(f, s, s.substr(i, u - i) + ' ' + path, i);
//     }
// };
```

