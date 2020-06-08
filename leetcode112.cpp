// 路径总和
// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和
// 典型的 DST 应用

# include "leetcode.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        isMatched(root, 0, sum);
        return this->res;
    }
private:
    bool res;
    void isMatched(TreeNode* node, int curr_sum, int sum){
        if(node == NULL) return;
        curr_sum += node->val;
        if(node->left == NULL && node->right == NULL){
            if(curr_sum == sum) res = true;
            return;
        }
        if(node->left != NULL) isMatched(node->left, curr_sum, sum);
        if(node->right != NULL) isMatched(node->right, curr_sum, sum);
    }
};
