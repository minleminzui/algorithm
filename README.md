 [剑指 Offer 20. 表示数值的字符串](./leetcode/表示数值的字符串.md)

 [剑指 Offer 41. 数据流中的中位数](./leetcode/数据流中的中位数)

[剑指 Offer 56 - I. 数组中数字出现的次数](./leetcode/数组中数字出现的次数)

[剑指 Offer 45. 把数组排成最小的数](./leetcode/把数组排成最小的数)

[剑指 Offer 62. 圆圈中最后剩下的数字](./leetcode/圆圈中最后剩下的数字)
 剑指 Offer 67. 把字符串转换成整数
`模拟`

`时间复杂度：`由于只扫描了一边字符串，所以为O(n)。
`空间复杂度：`O(1)

```
class Solution {
public:
    int strToInt(string str) {
        int i = 0, j = str.size();
        while(str[i] == ' ') ++i;//去掉首空格
        if(i >= j) return 0;
        bool minus = false;
        if(str[i] == '-'){
            minus = true;
            ++i;
        } else if(str[i] == '+'){
            ++i;
        }
        long long  ans = 0;
        while(i < j){
            if(isdigit(str[i])){
                ans *= 10;
                ans += str[i] - '0';
                ++i;
            }else break;
            // if(minus && ans * -1 < (1 << 31)) return (1 << 31);//判断是否越界
            // else if(!minus && ans > (unsigned (1 << 31) - 1)) return (unsigned (1 << 31) - 1);
            if(minus && ans * -1 < INT_MIN) return INT_MIN;//判断是否越界
            else if(!minus && ans > INT_MAX) return INT_MAX;
        }
        if(minus) ans *= -1;
        return ans;
        
    }
};
```
 剑指 Offer 63. 股票的最大利润
`动态规划`
假设dp[i]表示第i - 1天的最大利润，那么dp[i] = max(dp[i - 1], prices[i] - min(cost, prices[i])),继续优化dp数组之前的数据不用保持了，用一个profit变量保存即可，profit = max(profit, prices[i] - min(cost, prices[i])), cost = min(prices[i], cost)。
`时间复杂度：`O(n)。
`空间复杂度：`O(1)
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int cost = INT_MAX, profit = 0;
        for(auto i : prices){
            profit = max(i - price, profit);
            cost = min(i, cost);
        }
        return profit;
    }
};
```
 剑指 Offer 66. 构建乘积数组
`前后缀分解`
分两步计算ans数组![](https://img2022.cnblogs.com/blog/1743182/202201/1743182-20220128182756005-1621769213.png)
`时间复杂度：`O(n)
`空间复杂度：`O(1)
```
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int s = a.size();
        vector<int> ans(s, 1);
        for(int i = 1; i < s; ++i)
            ans[i] = ans[i - 1] * a[i - 1];
        int t = 1;
        for(int i = s - 1; ~i ; --i){
            ans[i] *= t;
            t *= a[i];
        }
        return ans;
    }
};
```
 92.反转链表II
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
 61. 旋转链表
`链表`
先接成环，再找到对应的头节点,**但是注释里头的方法会有`ERROR: AddressSanitizer: heap-use-after-free on address`,没搞明白**
`时间复杂度：`O(n)
`空间复杂度：`O(1)
<details>
<summary>点击查看代码</summary>

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
    ListNode* rotateRight(ListNode* head, int k) { 
        if(head == nullptr) return head;     
        ListNode *dummy = new ListNode, *move;
        // dummy -> next = head;
        int cnt = 1;
        // move = dummy -> next;
        move = head;
        while(move -> next != nullptr){
            ++cnt;
            move = move -> next;
        }
        move -> next = head;
        // move -> next = dummy -> next;
        k = k % cnt;
        k = cnt - k;
        move = head;
        // move = dummy;
        k--;
        while(k --){
            move = move -> next;
        }

        head = move -> next;
        move -> next = nullptr;
        return head;
        // dummy -> next = move -> next;

        // return dummy -> next;
        
    }
};
```
</details>

 143. 重排链表
`链表`
先找到中点，反转后半个链表，再与前半个链表合并。
`时间复杂度：`由于只需要线性的扫描链表，所以是O(n)
`空间复杂度：`用了常数个辅助遍量所以是O(1)
<details>
<summary>点击查看代码</summary>

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
    void reverse(ListNode *head){
        ListNode *cur = head -> next, *pre = nullptr;
        while(cur){
            ListNode * t = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = t;
        }
        head -> next = pre;
    }
    void reorderList(ListNode* head) {
        if(head -> next == nullptr || head -> next -> next == nullptr) return;
        ListNode *dummy = new ListNode;
        dummy -> next = head;
        ListNode *fast = dummy, *slow = dummy;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        reverse(slow);
        fast = head;
        ListNode *mid = slow;
        slow = slow -> next;
        mid -> next = nullptr;//这个mid是最后一个节点
        while(fast && slow){
            ListNode * nexts = slow -> next, *nextf = fast -> next;
            fast -> next = slow;
            fast = nextf;
            slow -> next = fast;
            slow = nexts;
        }
        
    }
};
```
</details>

 147. 对链表进行插入排序
`链表`
插入排序。
`时间复杂度：`插入排序的扫描链表，所以是O(n^2)
`空间复杂度：`用了常数个辅助遍量所以是O(1)
<details>
<summary>点击查看代码</summary>

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
    ListNode* insertionSortList(ListNode* head) {
        if(head -> next == nullptr) return head;
        ListNode *dummy = new ListNode;
        ListNode *move = head, *t, *pre, *cur;
        while(move){
            t = move -> next;
            pre = dummy, cur = dummy -> next;
            while(cur != nullptr){
                if(move -> val > cur -> val){
                    pre = pre -> next;
                    cur = cur -> next;
                }else break;
            }

            move -> next = pre -> next;
            pre -> next = move;
            move = t;
        }

        return dummy -> next;
    }
};
```
</details>

  138. [复制带随机指针的链表 `链表`](./leetcode/复制带随机指针的链表.md)

 [剑指 Offer 65. 不用加减乘除做加法 `位运算`](./leetcode/不用加减乘除做加法.md) 

[LRU 缓存 `链表`](./leetcode/LRU 缓存.md)

[面试题19. 正则表达式匹配 `二维dp`](./leetcode/正则表达式匹配.md)

[剑指 Offer 60. n个骰子的点数 `线性dp`](./leetcode/n个骰子的点数.md)

[电话号码的字母组合 `回溯 dfs`](./leetcode/电话号码的字母组合.md)



