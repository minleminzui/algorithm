<!--
 * @Author: yitong 2969413251@qq.com
 * @Date: 2022-12-22 21:31:30
-->
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口 O(n) O(n)
        unordered_map<char, int> um;
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        while (j < n) {
            um[s[j]]++;
            while (um[s[j]] == 2) {
                um[s[i++]]--;
            }
            ans = max(j - i + 1, ans);
            ++j;
        }

        return ans;
    }
};
```