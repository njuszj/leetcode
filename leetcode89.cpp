// 格雷编码
// 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异
// 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种
// 格雷编码序列必须以 0 开头

// 这一题通过找规律反而更好做, 使用递归解决这个问题
// n位的格雷编码能利用n-1位编码的结论，即将n-1位编码的结果倒序连到n位编码的后n-1位即可，这个规律是由格雷编码的特性决定的

# include "leetcode.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0){
            return {0};
        }
        if(n == 1){
            vector<int> res = {0, 1};
            return res;
        }
        else if(n == 2){
            vector<int> res = {0, 1, 3, 2};
            return res;
        }
        else{
            vector<int> res = grayCode(n-1);
            int size = res.size();
            for(int i=size-1; i>=0; i--){
                int val = ( 1 << (n-1) ) + (res[i]);
                res.push_back(val);
            }
            return res;
        }
    }
};

int main() {
    Solution s;
    vector<int> res = s.grayCode(3);
    printVector(res);
}