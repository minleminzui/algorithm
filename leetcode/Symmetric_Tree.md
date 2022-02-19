```cpp
class Solution {
public:
    // bool isSymmetric(TreeNode* root) {
    //     return isSame(root -> left, root -> right);
    // }

    // bool isSame(TreeNode* l, TreeNode* r){
    //     if(l == nullptr && r == nullptr) return true;
    //     else if(l == nullptr && r != nullptr) return false;
    //     else if(l != nullptr && r == nullptr) return false;
    //     return l -> val == r -> val && isSame(l -> right, r -> left) && isSame(r -> right, l -> left);
    // }
    bool isSymmetric(TreeNode* root) {
        // 迭代
        // 时间复杂度为O(n),空间复杂度为O(n),这里需要用一个队列来维护节点，每个节点最多进队一次，出队一次，队列中最多不会超过 n 个点，故渐进空间复杂度为 O(n)。
        queue<TreeNode*> q;
        q.push(root), q.push(root);
        while(q.size()){
            auto u = q.front(); q.pop();
            auto v = q.front(); q.pop();

            if(!u && !v) continue;
            if(!u && v) return false;
            if(u && !v) return false;
            if(u -> val != v -> val) return false;
            
            q.push(u -> right), q.push(v -> left), q.push(u -> left), q.push(v -> right);
        }
        return true;
    }
    // 递归法,时间复杂度O(n)遍历了整棵树, 空间复杂度O(n),递归栈的层数不超过n
    // bool isSymmetric(TreeNode* root) {
    //     return isSame(root -> left, root -> right);
    // }

    // bool isSame(TreeNode* l, TreeNode* r){
    //     if(l == nullptr && r == nullptr) return true;
    //     else if(l == nullptr && r != nullptr) return false;
    //     else if(l != nullptr && r == nullptr) return false;
    //     return l -> val == r -> val && isSame(l -> right, r -> left) && isSame(r -> right, l -> left);
    // }
};
```

