`回溯 dfs`

- 用三个数组记录每列。每个主对角线，反对角线是否存有皇后

`时间复杂度:`O(n!),n是皇后的个数
`空间复杂度:`O(n)，空间复杂度主要是递归层数与辅助数组的数量，都是O(n)

```
// C++
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

```rust
// Rust
impl Solution {
    pub fn total_n_queens(n: i32) -> i32 {
        let n = n as usize;
        let mut count = 0;
        let mut col = vec![false; n];
        let mut dia = vec![false; 2 * n];
        let mut back_dia = vec![false; 2 * n];
        Self::dfs(0, n, &mut count, &mut col, &mut dia, &mut back_dia);
        count
    }

    fn dfs(now: usize, n: usize, count: &mut i32, col: &mut Vec<bool>, dia: &mut Vec<bool>, back_dia: &mut Vec<bool>) {
        if now == n {
            *count += 1;
        } else {
            for i in 0..n {
                if !col[i] && !dia[i + now] && !back_dia[i + n - now] {
                    col[i] = true;
                    dia[i + now] = true;
                    back_dia[i + n - now] = true;
                    Self::dfs(now + 1, n, count, col, dia, back_dia);
                    col[i] = false;
                    dia[i + now] = false;
                    back_dia[i + n - now] = false;
                }
            }
        }
    }
}
```

