<!--
 * @Author: yitong 2969413251@qq.com
 * @Date: 2022-12-20 22:34:34
-->
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // dfs O(nm),有可能需要多次拿A树的节点与B比较 O(n)
        if (A == nullptr || B == nullptr) {
            if (A == nullptr && B == nullptr) {
                return true;
            } else {
                return false;
            }
        }
        bool pa = false;
        if (A -> val == B -> val) {
            pa = help(A, B);
        }

        return pa || isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }

    bool help(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            if (A == nullptr && B != nullptr) {
                return false;
            } else {
                return true;
            }
        } 
        bool l = help(A -> left, B -> left);
        bool r = help(A -> right, B -> right);

        return A -> val == B -> val && l && r;
    }
};
```