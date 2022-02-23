```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // 建立每行的数组，没过numRows转换方向，把s的字符放入不同的string数组中的每一行中
        // 除了第一个字符不算，每次遍历过numRows - 1个字符换方向
        // O(n), 遍历一遍s， O(n), 需要保存结果数据
        // if(numRows == 1) return s;

        // vector<string> buf(min((int)s.size(), numRows));
        // bool direction = true;
        // int i = 0, now = 0;
        // while(i < s.size()){
        //     buf[now] += s[i];
            
        //     if(i > 0 && (i) % (numRows - 1)== 0) direction = !direction;
        //     now += direction ? 1 : -1;
        //     ++i;
        // }

        // string res;
        // for(auto& i : buf){
        //     res += i;
        // }

        // return res;

        // 找规律，直接塞到结果中，按照zigzag遍历每一行 O(n), O(1),不需要额外辅助数组
        // 对于第0与第numRows - 1行，每个元素相隔2 * numRows - 2
        // 对于其他行，第i行 每隔2 * nuRows - 2元素之前还有一个元素, 
        int n = s.size();
        int cycle = 2 * numRows - 2;
        string res;
        if(numRows == 1) return s;
        for(int i = 0; i < numRows; ++i){
            for(int j = 0 ; i + j < n; j += cycle){
                res += s[i + j];
                if(i != 0 && i != numRows - 1 && i + j - 2 * i + cycle < n)
                    res += s[i + j - 2 * i + cycle];
            }
        }
        return res;
    }
};
```

