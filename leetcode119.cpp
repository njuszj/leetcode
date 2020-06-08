// �������II
// Ҫ����O(m)�Ŀռ临�Ӷȷ���������ǵĵ�m��
// ˼·һ: ��m���ȵĿռ�ѭ�������1,2,3...m��
// ˼·��: ����������������ʽչ���Ĺ�ϵ��ֱ����ͨ�ʽ


# include "leetcode.h"

int Combination(int n, int m) {
    // �� nPm
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
        // ���Ƿ�
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