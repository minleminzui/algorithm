```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        // O(n) O(n)
        // 二叉树， 回溯
        vector<vector<int>> ans;
        vector<int> now;
        dfs(ans, now, root, target, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &now, TreeNode* root, int target, int now_sum) {
        if (root == nullptr) return;
        if (root -> left != nullptr || root -> right != nullptr) {
            now.emplace_back(root -> val);
            if (root -> right != nullptr) {
                dfs(ans, now, root -> right, target, now_sum + root -> val);
            }
            if (root -> left != nullptr) {
                dfs(ans, now, root -> left, target, now_sum + root -> val);
            }
            now.pop_back();
        } else {
            if (now_sum + root -> val == target) {
                now.emplace_back(root -> val);
                ans.push_back(now);
                now.pop_back();
            }
        }
    }
};
```