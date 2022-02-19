```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // bfs，不过需要O(n)空间复杂度
        // 时间复杂度O(n),我们需要遍历这棵树上所有的点
        // queue<Node*> q;

        // if(root) q.emplace(root);

        // while(q.size()){
        //     int size = q.size();
        //     while(size --){
        //         auto t = q.front();
        //         q.pop();
        //         if(t -> left) q.emplace(t -> left);
        //         if(t -> right) q.emplace(t -> right);
   
        //         if(size > 0) t -> next = q.front();
        //         else t -> next = nullptr;
        //     }
        // }
        // return root;

        // O(1)的空间复杂度的方法
        if(root == nullptr) return root;
        auto father = root;
        Node* cur = nullptr;
        Node* firstleft = nullptr;
        while(father || firstleft){
            if(father == nullptr){
                father = firstleft;
                cur = nullptr;
                firstleft = nullptr;
            }else if(father -> left == nullptr && father -> right == nullptr){
                father = father -> next;
            }else{
                if(father -> left){
                    if(firstleft == nullptr){
                        firstleft = father -> left;
                        cur = firstleft;
                    }
                    else {
                        cur -> next = father -> left;
                        cur = cur -> next;
                    }
                }
                if(father -> right){
                    if(firstleft == nullptr){
                        firstleft = father -> right;
                        cur = firstleft;
                    }
                    else {
                        cur -> next = father -> right;
                        cur = cur -> next;
                    }
                }
                father = father -> next;
            }
        }
        return root;
    }
};
```

