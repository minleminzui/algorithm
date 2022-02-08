# [剑指 Offer 20. 表示数值的字符串](./leetcode/表示数值的字符串.md)
#  [剑指 Offer 41. 数据流中的中位数](./leetcode/数据流中的中位数)
# [剑指 Offer 56 - I. 数组中数字出现的次数](./leetcode/数组中数字出现的次数)

# [剑指 Offer 45. 把数组排成最小的数](./leetcode/把数组排成最小的数)
# [剑指 Offer 62. 圆圈中最后剩下的数字](./leetcode/圆圈中最后剩下的数字)
# 剑指 Offer 67. 把字符串转换成整数
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
# 剑指 Offer 63. 股票的最大利润
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
# 剑指 Offer 66. 构建乘积数组
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
# 92.反转链表II
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
# 61. 旋转链表
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

# 143. 重排链表
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

# 147. 对链表进行插入排序
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

# 138. 复制带随机指针的链表
`链表`
两种方法，第一种迭代+拆分，第二种哈希。
`时间复杂度：`第一种是O(n),第二种是O(n)。
`空间复杂度：`第一种是O(1),第二种是O(n)。
<details>
<summary>点击查看代码</summary>

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        for(Node *node = head; node; node = node -> next -> next){
            Node *t = new Node(node -> val);
            t -> next = node -> next;
            node -> next = t;
        }
        for(Node *node = head; node; node = node -> next -> next){
            node -> next -> random = (node -> random == nullptr) ? nullptr : node -> random -> next;
        }
        Node *ans = head -> next;
        for(Node *node = head; node; node = node -> next){
            Node *t = node -> next;
            node ->next = node -> next -> next;
            t -> next = (t -> next == nullptr) ? nullptr : t -> next -> next;
        }
        return ans;
        // if(!head) return head;
        // unordered_map<Node*, Node*> m;
        // Node* nHead = new Node(head -> val), *move = head -> next;
        // Node *dummy = nHead;
        // m[head] = nHead;
        // m[nullptr] = nullptr;
        // while(move){
        //     Node *t = new Node(move -> val);
        //     m[move] = t;
        //     nHead -> next = t;
        //     nHead = t;
        //     move = move -> next;
        // }

        // nHead = dummy, move = head;
        // while(dummy){
        //     dummy -> random = m[move -> random];
        //     dummy = dummy -> next;
        //     move = move ->next;
        // }
        // return nHead;


    }
};
```
</details>

# 剑指 Offer 65. 不用加减乘除做加法
`位运算`
- a与b的加法运算的非进位和为a^b
- a与b的加法进位为a&b
- a + b = a^b + (a&b)<<1,注意到这里又有一次加法，那么需要将a^b与(a&b)<<1赋值给a与b，重复前两个步骤，知道进位为0。
- 证明循环一定会结束，当b最右边没有零时，每次做&运算不会改变其右边零的数量，并且还会左移一位，那么又会增加一个零，所以至多需要32次运算。
- `int c = (unsigned)(a & b) << 1;`，leetcode不允许负数左移。

`时间复杂度：`O(1), 最多执行32次运算。
`空间复杂度：`O(1)。
<details>
<summary>点击查看代码</summary>

```
class Solution {
public:
    int add(int a, int b) {
        while(b){
            int c = (unsigned)(a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};
```
</details>

# 146. LRU 缓存
`链表`
- 把`新鲜的数据`用splice放到list的表头,新鲜的数据:新的PII,或则刚被修改,被访问,`splice`的作用:将一个 list 容器中的元素插入到另一个容器的指定位置。
- map中保存<key, 链表节点的指针>,这样查找节点就不用遍历了
- 过期键直接 pop_back()，链表节点越往后，越陈旧。

`时间复杂度:`题目要求`get`与`put`为O(1)
`空间复杂度:`O(capacity),map最多存capacity个元素

<details>
<summary>点击查看代码</summary>

```
typedef pair<int,int> PII;
class LRUCache {
public:

    list<PII> buffer;
    unordered_map<int, list<PII>::iterator> kToN;
    int cap, size = 0;
    LRUCache(int capacity) : cap(capacity) {

    }
    
    int get(int key) {
        auto it = kToN.find(key);
        if(it == kToN.end()) return -1;
        buffer.splice(buffer.begin(), buffer, it -> second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        
        auto it = kToN.find(key);
        if(it != kToN.end()){
            buffer.splice(buffer.begin(), buffer, it -> second);
            it->second->second = value;
            return;
        }
        buffer.emplace_front(key, value);//记住不能有大括号
        // buffer.push_front({key, value});
        kToN[key] = buffer.begin();
        ++size;
        if(size > cap){
            kToN.erase(buffer.back().first);
            buffer.pop_back();
            --size;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
</details>





# [面试题19. 正则表达式匹配 `二维dp`](./leetcode/正则表达式匹配.md)

