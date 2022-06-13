```cpp
class Solution{

public:
    int calculate(string s) {
        int preSign = '+';
        vector<int> sta;
        int num = 0;

        for(int i = 0; i < s.size(); ++i) {
            while(isdigit(s[i])) {
                // cout<<s[i]<<" "<<num<<endl;
                num = num * 10 + (s[i] - '0');// 得加括号， 不然"2147483647"会溢出
                // cout<<num<<endl;
                ++i;
            }
            // cout<<num;
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1){
                switch(preSign) {
                    case '+':
                        sta.emplace_back(num);
                        break;
                    case '-':
                        sta.emplace_back(-num);
                        break;
                    case '*':
                        sta.back() *= num;
                        break;
                    default:
                        sta.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }

        return accumulate(sta.begin(), sta.end(), 0);
    }
};

// acwing 151 表达式计算4
// #include<iostream>
// #include<stack>
// #include<string>
// #include<cstring>

// using namespace std;

// stack<int>nums;
// stack<char>ops;

// string ss;

// void cal()
// {
//     char c=ops.top(); ops.pop();
//     int a = nums.top();nums.pop();
//     int b = nums.top();nums.pop();

//     int d;
//     if(c == '+')
//     d=b+a;
//     if(c=='-')
//     d=b-a;
//     if(c=='*')
//     d=b*a;
//     if(c=='/')
//     d=b/a;
//     if(c=='^')
//     {
//         d=1;
//         while(a--)
//         d*=b;
//     }
//     nums.push(d);
// }

// int main()
// {

//     string str;
//     cin >>str;
//     string left;
//     for(int i=0;i<str.size();i++) left += '(';
//     str = left +str + ')';


//     // cout<<str;
//     for (int i=0;i<str.size();i++)
//     {
//         if(str[i]>='0' && str[i]<='9')
//         {
//             int j=i,t=0;
//             while(str[j]>='0'&&str[j]<='9')
//             {
//                 t = t*10 + str[j]-'0';
//                 j++;
//             }
//             i=j-1;
//             nums.push(t);
//         }
//         else 
//         {
//             char c = str[i];
//             if(c == '+' || c== '-')
//             {
//                 //(2+2)^(-(1+1)+2)
//                 //值得注意进行特判的是，这中情况算作减号应当 前面在加个0
//                 if(c=='-' && !(str[i-1]>='0'&&str[i-1]<='9' || str[i-1]==')'))
//                 {
//                     int j=i+1,t=0;
//                     while(str[j]>='0'&&str[j]<='9')
//                     {
//                         t = t*10 + str[j]-'0';
//                         j++;
//                     }
//                     i=j-1;
//                     nums.push(-t);

//                     //这就是对上面那种情况的特判！
//                     if(str[i+1]=='(')
//                     ops.push(c);
//                 }
//                 else
//                 {
//                     while(ops.top()!='(') cal();
//                     ops.push(c);
//                 }
//             }
//             else if(c=='*' || c=='/')
//             {
//                 while(ops.top() == '/'|| ops.top()=='*'||ops.top()=='^') cal();
//                 ops.push(c);
//             }
//             else if(c=='^')
//             {
//                 while(ops.top()=='^') cal();
//                 ops.push(c);
//             }
//             else if(c==')')
//             {
//                 while(ops.top() != '(') cal();
//                 ops.pop();
//             }
//             else if(c=='(') ops.push(c);
//         }
//     }

//     cout<<nums.top();



//     return 0;
// }
```

