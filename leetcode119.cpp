// 杨辉三角II
// 要求以O(m)的空间复杂度返回杨辉三角的第m行
// 思路一: 用m长度的空间循环储存第1,2,3...m行
// 思路二: 联想杨辉三角与二项式展开的关系，直接用通项公式


# include "leetcode.h"

int Combination(int n, int m) {
    // 求 nPm
    int ans = 1;
    for (int i = n; i >= (n - m + 1); --i)
        ans *= i;
    while (m)
        ans /= m--;
    return ans;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> res;
        for (int i = 0; i < rowIndex; i++) {
            res[i] = Combination(rowIndex - 1, i);
        }
    }
    vector<int> getRowByOverride(int rowIndex) {
        // 覆盖法
        rowIndex++;
        vector<int> res(rowIndex, 0);
        res[0] = 1;
        if (rowIndex == 1) return { 1 };
        else {
            for (int i = 0; i < rowIndex; i++) {
                for (int j = i; j >= 0; j--) {
                    if (j == 0 || j == i) res[j] = 1;
                    else res[j] = res[j] + res[j - 1];
                }
            }
        }
        return res;
    }
};