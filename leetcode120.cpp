// ��������С·����
/*
����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�

���ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣
*/

// ��������� �Ե�������⣬������ÿ���ڵ������ѡ��

# include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(); // ����
        if (size == 0) return 0;
        if (size == 1) return triangle[0][0];
        for (int i = size - 2; i >= 0; i--) {
            int layer_size = triangle[i].size();
            for (int j = 0; j < layer_size; j++) {
                // ÿһ��ÿ���ڵ㵽�ײ�����̾���
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};