// 除自身以外数组的乘积
// 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积
// 要求不使用除法，且时间复杂度为O(n)

// 如何优化使空间复杂度降低为O(1) ?? 
// 使用输出数组暂存 前缀乘积， 然后遍历一遍，同时计算后缀积和输出结果

# include "leetcode.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        if (size == 0 || size == 1) return res;
        vector<int> prefix_sum(size, 1);  // 前缀和
        vector<int> tail_sum(size, 1);    // 后缀和
        for (int i = 0; i < size; i++) {
            if (i > 0) prefix_sum[i] = prefix_sum[i - 1] * nums[i];
            else prefix_sum[i] = nums[i];
        }
        for (int i = size - 1; i >= 0; i--) {
            if (i < size - 1) tail_sum[i] = tail_sum[i + 1] * nums[i];
            else tail_sum[i] = nums[i];
        }
        for (int i = 0; i < size; i++) {
            if (i == 0) res[i] = tail_sum[i + 1];
            else if (i == size - 1) res[i] = prefix_sum[i - 1];
            else res[i] = prefix_sum[i - 1] * tail _sum[i + 1];
        }
        return res;
    }
};