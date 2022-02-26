```cpp
// class Trie {
//     // vector<vector<int>> son(2010, vector<int>(26));// 这样会被当成函数声明
//     vector<vector<int>> son = vector<vector<int>>(4 * 1e4, vector<int>(26));
//     int idx{0};
//     vector<bool> count = vector<bool>(4 * 1e4);// 开数组花了大量的时间，😓
// public:
//     Trie() {
        
//     }
//     /* 这个做法是按照oi来的，初始化是O(1), 每次search，insert，startsWith操作时O(len),
//         len是word的长度,空间复杂度。。    
//     */ 
//     void insert(string word) {
//         int p = 0;
//         for(auto i : word) {
//             int u = i - 'a';
//             if(!son[p][u]) son[p][u] = ++idx;
//             p = son[p][u];
//         }
//         count[p] = true;
//     }
    
//     bool search(string word) {
//         int p = 0;
//         for(auto i : word) {
//             int u = i - 'a';
//             if(!son[p][u]) {
//                 return false;
//             }
//             p = son[p][u];
//         }
//         return count[p];
//     }
    
//     bool startsWith(string prefix) {
//         int p = 0;
//         for(auto i : prefix) {
//             int u = i - 'a';
//             if(!son[p][u]) {
//                 return false;
//             }
//             p = son[p][u];
//         }
//         return true;
//     }
// };

class Trie {
    vector<Trie*> children = vector<Trie*>(26);
    bool is_end = false;
public:
    Trie() {
        
    }
    // 这里用指针实现，O(len), len是word的长度，O(totLen * 26),
    // totLen是所有字符串的总长度每创建一个节点就会生成26个孩子
    void insert(string word) {
        Trie *p = this;
        for(auto i : word){
            int u = i - 'a';
            if(p -> children[u] == nullptr) {
                p -> children[u] = new Trie();
            }
            p = p -> children[u];
        }

        p -> is_end = true;
    }
    
    bool search(string word) {
        Trie* p = this;
        for(auto i : word) {
            int u = i - 'a';
            if(p -> children[u] == nullptr) {
                return false;
            }
            p = p -> children[u];
        }

        return p -> is_end;
    }
    
    bool startsWith(string prefix) {
        Trie* p = this;
        for(auto i : prefix) {
            int u = i - 'a';
            if(p -> children[u] == nullptr) {
                return false;
            }
            p = p -> children[u];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

