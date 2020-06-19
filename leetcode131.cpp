// 分割回文串
// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。返回 s 所有可能的分割方案。
// 我的思路是使用DSP+回溯
# include "leetcode.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        size = s.size();
        vector<int> partdp(size, 0);
        vector<vector<int>> dp(size, partdp);   // 辅助数组，记录哪个下标之间有回文串
        for(int i=0; i<size; i++) dp[i][i] = 1;
        for(int i=1; i<2*size-3; i++){
            int length = 0;
            while(s[i])
        }
    }
private:
    int size;
    vector<vector<string>> res;
    void helper(string& s, int sp, vector<string> partstr, vector<vector<int>> dp){
        if(sp > size){
            res.push_back(partstr);
            return;
        }
        

    }
};