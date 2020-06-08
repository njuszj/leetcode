<<<<<<< HEAD
// 盛水最多的容器
// 双指针解法
# include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int head = 0, tail = height.size() - 1;
        int max_cap = min(height[head], height[tail]) * (tail - head);     
        while(head < tail){
            int curr_cap = min(height[head], height[tail]) * (tail - head);
            if(curr_cap >= max_cap) max_cap = curr_cap;
            if(height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return max_cap;
    }
=======
// 盛水最多的容器
// 双指针解法
# include "leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int head = 0, tail = height.size() - 1;
        int max_cap = min(height[head], height[tail]) * (tail - head);     
        while(head < tail){
            int curr_cap = min(height[head], height[tail]) * (tail - head);
            if(curr_cap >= max_cap) max_cap = curr_cap;
            if(height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return max_cap;
    }
>>>>>>> b5bceb60679d9e4014bc49c7686be5965b5eb0ea
};