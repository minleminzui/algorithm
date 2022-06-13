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
    TreeNode* mirrorTree(TreeNode* root) {
        // 二叉树 O(n) O(n)
        if (root == nullptr) return root;
        dfs(root); 
        return root;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        swap(root -> left, root -> right);
        dfs(root -> left);
        dfs(root -> right);
    }
};
```

