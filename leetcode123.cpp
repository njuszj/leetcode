// 买卖股票的最佳时机III
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
*/

// 使用辅助数组 dp[i] 表示前 i 天(在第i天卖出) 一次交易能获取的最大利润--失败
// 使用动态规划，考虑状态转移方程==有限状态机，需要三个变量分别表示 天数、 操作次数、 是否持有

/*
class Solution:
    def maxProfit(self, prices):
        if prices==[]:
            return 0
        length=len(prices)
        #结束时的最高利润=[天数][是否持有股票][卖出次数]
        dp=[ [[0,0,0],[0,0,0] ] for i in range(0,length) ]
        #第一天休息
        dp[0][0][0]=0
        #第一天买入
        dp[0][1][0]=-prices[0]
        # 第一天不可能已经有卖出
        dp[0][0][1] = float('-inf')
        dp[0][0][2] = float('-inf')
        #第一天不可能已经卖出
        dp[0][1][1]=float('-inf')
        dp[0][1][2]=float('-inf')
        for i in range(1,length):
            #未持股，未卖出过，说明从未进行过买卖
            dp[i][0][0]=0
            #未持股，卖出过1次，可能是今天卖的，可能是之前卖的
            dp[i][0][1]=max(dp[i-1][1][0]+prices[i],dp[i-1][0][1])
            #未持股，卖出过2次，可能是今天卖的，可能是之前卖的
            dp[i][0][2]=max(dp[i-1][1][1]+prices[i],dp[i-1][0][2])
            #持股，未卖出过，可能是今天买的，可能是之前买的
            dp[i][1][0]=max(dp[i-1][0][0]-prices[i],dp[i-1][1][0])
            #持股，卖出过1次，可能是今天买的，可能是之前买的
            dp[i][1][1]=max(dp[i-1][0][1]-prices[i],dp[i-1][1][1])
            #持股，卖出过2次，不可能
            dp[i][1][2]=float('-inf')
        return max(dp[length-1][0][1],dp[length-1][0][2],0)


作者：marcusxu
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/tong-su-yi-dong-de-dong-tai-gui-hua-jie-fa-by-marc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

# include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;
        vector<int> status(2, 0);  // 两种状态
        vector<vector<int>> oper(3, status);  // 最多两次操作
        vector<vector<vector<int>>> dp(size, oper);   // 天数，数组表示每一天，各个状态下的最大利润
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = 0;
        dp[0][2][0] = 0;
        dp[0][1][1] = INT32_MIN;
        dp[0][2][1] = INT32_MIN;
        for(int i=1; i<size; i++){
            dp[i][0][0] = 0;  // 无卖出，不持有
            dp[i][0][1] = max(dp[i-1][0][1], -prices[i]); // 无卖出，持有
            dp[i][1][0] = max(prices[i]+dp[i-1][0][1], dp[i-1][1][0]);// 卖出一次， 不持有
            dp[i][1][1] = max(dp[i-1][1][0]-prices[i], dp[i-1][1][1]); // 卖出一次， 持有
            dp[i][2][0] = max(dp[i-1][1][1]+prices[i], dp[i-1][2][0]);// 卖出两次， 不持有
            dp[i][2][1] = INT32_MIN;  // 卖出两次仍然持有， 不可能
        }
        return max(dp[size-1][2][0], dp[size-1][1][0]);
    }
};