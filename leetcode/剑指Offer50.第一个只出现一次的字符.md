<!--
 * @Author: yitong 2969413251@qq.com
 * @Date: 2023-01-04 09:29:45
-->
```cpp
class Solution {
public:
    char firstUniqChar(string s) {
        // hash 表 O(n) O(∑) ∑表示字符集的个数
        unordered_map<char, int> um;

        for (auto & c : s) {
            um[c]++;
        }

        for (auto & c : s) {
            if (um[c] == 1) return c; 
        }

        return ' ';
    }
};
```