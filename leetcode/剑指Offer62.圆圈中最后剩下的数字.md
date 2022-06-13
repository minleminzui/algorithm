`约瑟夫环问题`
假设f(n,m)表示为从从n个元素中删除圆圈的第m个数，直到剩下最后一个元素为止的元素编号，那么可以推出f(n,m)=(f(n - 1, m) + m) % n。也就是说在数组长度为n - 1中元素编号为x的元素，它在数组长度为n的数组中的编号便为（x + m）% n。
`时间复杂度：`O(n)
`空间复杂度：`O(1)

```
class Solution {
public:
    int lastRemaining(int n, int m) {
        // if(n == 1) return 0;
        // else return (lastRemaining(n - 1, m) + m) % n;
        int ans = 0;
        for(int i = 2; i <= n; ++i){
            ans = (ans + m) % i;
        }
        return ans;
    }
};
```

