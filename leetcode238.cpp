// ��������������ĳ˻�
// ����һ������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻�
// Ҫ��ʹ�ó�������ʱ�临�Ӷ�ΪO(n)

// ����Ż�ʹ�ռ临�ӶȽ���ΪO(1) ?? 
// ʹ����������ݴ� ǰ׺�˻��� Ȼ�����һ�飬ͬʱ�����׺����������

# include "leetcode.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        if (size == 0 || size == 1) return res;
        vector<int> prefix_sum(size, 1);  // ǰ׺��
        vector<int> tail_sum(size, 1);    // ��׺��
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