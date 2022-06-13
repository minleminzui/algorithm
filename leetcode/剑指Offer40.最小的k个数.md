```cpp
class Solution {
public:

    void quick_sort(vector<int> &arr, int l, int r, int k) {
        if (l == r) return;

        int i = l - 1, j = r + 1, m = arr[(l + r) >> 1];

        while (i < j) {
            while (arr[++i] < m);
            while (arr[--j] > m);

            if (i < j) swap(arr[i], arr[j]);
        }

        if (j - l + 1 >= k) quick_sort(arr, l, j, k);
        else quick_sort(arr, j + 1, r, k - (j - l + 1));

    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr, 0, arr.size() - 1, k);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = arr[i];
        }

        return ans;
    }
};
```

