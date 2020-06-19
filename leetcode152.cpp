// 乘积最大子数组
// 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
// 关键是考虑0元素，分隔0后可以分段处理，每一段中最大乘积要么是全乘积，要么是左最长，要么是右最长乘积
/*
 动态规划解法
 由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin
 class Solution {
    public int maxProduct(int[] nums) {
        int max = Integer.MIN_VALUE, imax = 1, imin = 1;
        for(int i=0; i<nums.length; i++){
            if(nums[i] < 0){ 
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = Math.max(imax*nums[i], nums[i]);
            imin = Math.min(imin*nums[i], nums[i]);
            
            max = Math.max(max, imax);
        }
        return max;
    }
}


作者：guanpengchn
链接：https://leetcode-cn.com/problems/maximum-product-subarray/solution/hua-jie-suan-fa-152-cheng-ji-zui-da-zi-xu-lie-by-g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
# include "leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0, r = 0, res = INT32_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                r = i;
            }
            else{
                res = 0;
                res = max(max(res, 0), maxProductWithoutZero(nums, l, r));
                l = i+1;
                r = i+1;
            }
        }
        res = max(res, maxProductWithoutZero(nums, l, r));
        return res;
    }

private:
    int maxProductWithoutZero(vector<int>& nums, int l, int r){
        int res = 1;
        if(r == l) return 0;
        if(r - l == 1) return nums[l];
        for(int i=l; i<r; i++){
            res *= nums[i];
        }
        int left = res, right = res;
        if(res > 0) return res;
        else{
            int i=l, j=r-1;
            while(i<r && left < 0) left /= nums[i++];
            while(j>=l && right < 0) right /= nums[j--];
        }
        return max(left, right);
    }
};