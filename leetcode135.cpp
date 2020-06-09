// ������Ʊ�����ʱ��
// ���ø������� dp[k] ��ʾ�ڵ�k��������������棬����ֻҪά��һ����Сֵ�Ϳ�����

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