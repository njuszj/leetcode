// 买卖股票的最佳时机II
/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

// 这题可以考虑贪婪的方法，从后向前推
// 总是寻找递增的价格序列

// 或者说: 只在上涨日购买，下降日不买!!
// 也就相当于每天都买

# include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int res = 0;
        if(size <= 1) return 0;
        int curr = size - 1, prev = curr;
        while(curr >= 0){
            prev = curr;
            int currval = prices[curr];
            prev--;
            while(prev >= 0){
                if(prices[prev] > prices[prev+1]) break;
                else prev--;
            }
            if(prices[prev+1] >= currval) {
                curr--;
                continue;
            }
            else{
                res += (currval - prices[prev+1]);
                curr = prev;
            }
        }
        return res;
    }
};
