```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // 链表 O(n) O(1)
        ListNode *fast = head, *slow = head;

        for (int i = 0; i <= k; ++i) {
            if (fast == nullptr) return head;
            fast = fast -> next;
        } 
        
        while (fast) {
            fast = fast -> next;
            slow = slow -> next;
        }

        return slow -> next;

    }
};
```

