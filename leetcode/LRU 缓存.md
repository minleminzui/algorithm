  146. `链表`

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