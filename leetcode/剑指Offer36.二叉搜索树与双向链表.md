```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head = nullptr, *pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        // 中序遍历 O(n) O(n)
        if (root == nullptr) return root;

        dfs(root);

        auto mov = head;
        while (mov -> right) {
            mov = mov -> right;
        }

        head -> left = mov;
        mov -> right = head;

        return head;
    }

    void dfs(Node *root) {
        if (root == nullptr) return;

        dfs (root -> left);

        if (head == nullptr) head = root;

        root -> left = pre;
        if (pre) pre -> right = root;
        pre = root;

        dfs(root -> right); 
    }
};
```

