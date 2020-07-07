// 最长上升子序列

# include "leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};