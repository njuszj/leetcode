// 删除排序数组中的重复项 II
// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度

/*
使用双指针法模拟删除的过程，要注意一点边界细节。
*/

# include "leetcode.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=1, index=0, cnt=0;
        if(nums.size() < 1) return nums.size();
        while(curr < nums.size()){
            if(nums[curr] == nums[curr-1]){
                cnt ++;
                if(cnt <= 2) nums[index++] = nums[curr];
                else
                    curr++;
            }
            else{
                cnt = 1;
                nums[index++] = nums[curr];
                curr++;
            }
        }
        return index;
    }
};