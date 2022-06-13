```cpp
class CQueue {
public:
    stack<int> head, tail;
    CQueue() {

    }
    
    void appendTail(int value) {
        head.emplace(value);
    }
    
    int deleteHead() {
        // 栈 O(n) O(1)
        int ret;
        if (head.empty() && tail.empty()) {
            ret = -1;
        } else {
            if (tail.empty()) {
                while (head.size()) {
                    tail.emplace(head.top());
                    head.pop();
                }
            }
            ret = tail.top();
            tail.pop();
        } 

        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

