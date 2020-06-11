// 二叉树的最大路径和
// 给定一个非空二叉树，返回其最大路径和。
// 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
// 使用递归处理问题， 通过
// 递归处理经过每个根节点的最大值，并更新结果

# include "leetcode.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        rootMax(root);
        return ans;
    }
private:
    int ans = INT32_MIN;
    int rootMax(TreeNode* root) {
        // 途径每个"根"节点的最大路径和
        int currmax = INT32_MIN;
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) {
            ans = max(ans, root->val);
            return root->val;
        }
        else {
            int left = rootMax(root->left);
            int right = rootMax(root->right);
            currmax = max(max(root->val, left+root->val), right+root->val);
            ans = max(ans, max(currmax,left+right+root->val));
            return currmax;
        }
        return 0;
    }
};