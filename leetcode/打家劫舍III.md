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
    
    // unordered_map<pair<TreeNode*, int>, int> m{};
public:
    int rob(TreeNode* root) {
        // if(!root) return 0;
        // dfs(root);
        // return max(m[{root, 0}], m[{root, 1}]);

        // 后序遍历，时间复杂度为O(n),因为递归栈的存在，但是省去了hash表，因为每次只需要自己的孩子节点的值
        // 空间复杂度为O(n)
        auto ans = dfs(root);
        return max(ans.first, ans.second); 
    }

    pair<int, int> dfs(TreeNode* r){
        if(!r){
            return {0, 0};
        }
        pair<int, int> ans = {0, 0};
        auto left = dfs(r -> left);
        auto right = dfs(r -> right);
        ans.first += left.second + right.second + r -> val;// 选自己
        ans.second += max(left.first, left.second) + max(right.first, right. second);// 不选自己

        return ans;
    }
    // void dfs(TreeNode* r){
    //     if(!r) return;
    //     m[{r, 1}] = r -> val;

    //     dfs(r -> left);
    //     dfs(r -> right);

    //     if(r -> left){
    //         m[{r, 1}] += m[{r -> left, 0}];
    //         m[{r, 0}] += max(m[{r -> left, 0}], m[{r -> left, 1}]);
    //     }
    //     if(r -> right){
    //         m[{r, 1}] += m[{r -> right, 0}];
    //         m[{r, 0}] += max(m[{r -> right, 0}], m[{r -> right, 1}]);
    //     }
    // }
};
```

