// 将有序数组转换为二叉搜索树
// 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树
// 递归解法比较简单，每次寻找中间的数组元素即可
// "众所周知，二叉搜索树的中序遍历是一个升序序列"
// 因为对中间节点的选取可以是左边也可是右边，所以答案不唯一

# include "leetcode.h"

class Solution {
private:
    TreeNode* ToBSTByIndex(vector<int>& nums, int left, int right) {
        if(right < left) return NULL;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = ToBSTByIndex(nums, left, mid-1);
        node->right = ToBSTByIndex(nums, mid+1, right);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node = ToBSTByIndex(nums, 0, nums.size()-1);
        return node;    
    }
};