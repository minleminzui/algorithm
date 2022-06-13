```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans, time;
    int kthLargest(TreeNode* root, int k) {
        // 逆中序遍历 O(n) O(n)
        time = k;
        dfs(root);

        return ans;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        
        dfs(root -> right);
        --time;
        if (time == 0) {
            ans = root -> val;
        }

        dfs(root -> left);
    }
};
```

