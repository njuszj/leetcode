// 三角形最小路径和
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
*/

// 解决方案： 自底向上求解，依次求到每个节点的最优选择

# include "leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(); // 层数
        if (size == 0) return 0;
        if (size == 1) return triangle[0][0];
        for (int i = size - 2; i >= 0; i--) {
            int layer_size = triangle[i].size();
            for (int j = 0; j < layer_size; j++) {
                // 每一层每个节点到底部的最短距离
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};