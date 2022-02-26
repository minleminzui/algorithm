```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 多次二分O(mlogn) O(1)
        int n = matrix.size(), m, l, r;
        for(int i = 0; i < n; ++i) {    
            l = 0, r = matrix[i].size() - 1;
            while(l < r) {
                m = (l + r + 1) >> 1;
                if(matrix[i][m] > target) r = m - 1;
                else l = m;
            }
            if(matrix[i][l] == target) return true;
        }

        return false;

        // Z字查找 O(n + m), O(1)
        // int n = matrix.size(), m = matrix[0].size();
        // int x = 0, y = m - 1; 
        // while(x < n && y >= 0) {
        //     while(y >= 0 && matrix[x][y] > target) --y;
        //     if(y >= 0 && matrix[x][y] == target) return true;
        //     ++x;
        // }

        // return false;
    }
};
```

