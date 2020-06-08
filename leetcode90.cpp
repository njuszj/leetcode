// 子集II
// 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
// 解集不能包含重复的子集

# include "leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        size = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return res;
    }
private:
    int size = 0;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int> path, int loc){
        res.push_back(path);
        if(loc == size) return;
        for(int i=loc; i<size; i++){
            if(i > loc && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> a = {1,2,3,3};
    vector<vector<int>> r = s.subsetsWithDup(a);
    printDoubleVector(r);
}
