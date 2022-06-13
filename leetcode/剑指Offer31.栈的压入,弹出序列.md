```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 单调栈 hash表 O(n) O(n)
        int n = pushed.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[pushed[i]] = i;
        }

        // 4 5 3 2 1
        stack<int> s;
        int M = 0;
        for (auto i : popped) {
            while (s.size()) {
                if (m[i] > s.top()) {
                    if (m[i] < M) return false;
                    s.pop();
                } else {
                    break;
                }
            }
            M = max(m[i], M);
            s.emplace(m[i]);
        }
        
        
        return true;
        
    }
};
```

