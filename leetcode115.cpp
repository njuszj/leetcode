// 不同的子序列
// 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数
/*
第一感觉是动态规划
    用 dp[t][s] 表示 T 的前 t 个元素 在 S 的前 s 个元素中出现的次数
那么
    if t[t] == s[s] 
       if dp[t][s-1] > 0: dp[t][s] = dp[t][s-1] + 1
       if dp[t][s-1] == 0: dp[t][s] = dp[t-1][s-1]
    if (t[t] != s[s]): dp[t][s] = dp[t][s-1];
完全搞错了!
*/

/*
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
*/

# include "leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        const int s_size = s.size();
        const int t_size = t.size();
        if(s_size*t_size == 0) return 0;
        vector<int> vCol(s_size, 0);
        vector<vector<int>> dp(t_size, vCol);
        if(s[0] == t[0]) dp[0][0] = 1;
        for(int i=0; i<t_size; i++){
            for(int j=0; j<s_size; j++){
                if(i > j) continue;
                if(j>0 && i==0 && t[i] == s[j]) dp[i][j] = dp[i][j-1] + 1;
                else if(j>0 && i==0 && t[i] != s[j]) dp[i][j] = dp[i][j-1];
                else if(j == 0) continue;
                else if(t[i] == s[j]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];  //以j为结尾的 + 不以j为结尾的
                }
                else if(j>0 && t[i] != s[j]) dp[i][j] = dp[i][j-1];
                cout << j << " ";
            }
        }
        // printDoubleVector(dp);
        return dp[t_size-1][s_size-1];
    }
};

int main(){
    Solution s;
    int r = s.numDistinct("rabbbit", "rabbit");
}
