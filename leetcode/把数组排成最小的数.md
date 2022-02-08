`排序 贪心`
这里的排序正确性证明：

>需要证明排序规则满足反对称性与传递性。反对称性，a + b >= b + a,并且b + a >= a + b,那么a + b == b + a，由于a + b与b + a的位数一样，那么字典序大小就是字符串对应数值大小，得证。传递性，a + b < b + a, b + c < c + b,假设a,b,c的位数分别为n, m, k,那么![](https://img2022.cnblogs.com/blog/1743182/202201/1743182-20220128123251078-963267789.png)

 `时间复杂度：`O(nlogn),n为最终返回值的字符数目，内置排序是一个[introsort](https://www.cnblogs.com/johnwu/p/3344935.html)，平均时间复杂度为O(nlogn)。
`空间复杂度：`O(n),需要数组存储所有字符串。
**[为什么要保证严格弱序](https://www.cnblogs.com/RookieSuperman/p/12375563.html)**

```
class Solution {
public:

    static bool cmp(string &a, string &b){
        return a + b < b + a;//需要注意，这里不能写成<=，不然会违反sort元素严格弱序的要求
    }
    string minNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto c : nums){
            ans.push_back(to_string(c));
        }
        sort(ans.begin(), ans.end(), cmp);
        string s;
        for(auto i : ans){
            s += i;
        }
        return s;
    }
};
```

# 