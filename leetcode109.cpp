// 有序链表转换二叉搜索树
// 这题与上一题很相似，直接借用了

# include "leetcode.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head = head -> next;
        }
        TreeNode* r = sortedArrayToBST(nums);
        return r;
    }
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