`回溯 dfs`

- 用三个数组记录每列。每个主对角线，反对角线是否存有皇后

`时间复杂度:`O(n!),n是皇后的个数
`空间复杂度:`O(n)，空间复杂度主要是递归层数与辅助数组的数量，都是O(n)

```
class Solution {
private:
    vector<bool> col, dia, back_dia;
    int ans, n;
public:
    int totalNQueens(int n) {
        col.resize(n), dia.resize(n * 2), back_dia.resize(n * 2);//注意对角线的数量是2 * n - 1，但是resize为n的时候，居然没有数组越界
        this -> n = n;
        dfs(0);
        return ans;
    }

    void dfs(int num){
        if(num == n){
            ++ans;
            return;
        }

        for(int i = 0; i < n; ++i){
            if(!col[i] && !dia[num + i] && !back_dia[n + i - num]){
                col[i] = dia[num + i] = back_dia[n + i - num] = true;
                dfs(num + 1);
                col[i] = dia[num + i] = back_dia[n + i - num] = false;
            }
        }
    }
};
```