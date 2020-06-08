// 买卖股票的最佳时机
// 设置辅助数组 dp[k] 表示在第k天卖出的最大收益，这样只要维护一个最小值就可以了

# include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int res = 0, min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int val = prices[i] - min_price;
            if (val > res) res = val;
            if (prices[i] < min_price) min_price = prices[i];
        }
        return res;
    }
};