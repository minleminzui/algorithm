`链表`
找到left节点的前一个节点，运用头插法反转链表。当然也可以使用函数反转子链表后，在拼接，又叫穿针引线法。
`时间复杂度：`扫描一遍链表，所以是O(n)
`空间复杂度：`O(1)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *dummy = new ListNode;//dummy的设置对于处理边界条件很有效
        dummy -> next = head;
        ListNode *l, *tail, *cur, *move = dummy;
        int cnt = 0;
        while(move){
            ++cnt;
            if(cnt == left){//l指向left的前一个节点
                l = move;
                break;  
            } 
            move = move -> next;
        }
        
        move = move -> next;
        tail = move;
        while(move && cnt <= right){
            cur = move;
            move = move -> next;
            tail -> next = cur -> next;
            cur -> next = l -> next;
            l -> next = cur;
            ++cnt;
        }
        return dummy -> next;
    }
};
```

  61. 