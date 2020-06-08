<<<<<<< HEAD
// 二叉树的的最大深度
// 递归会很简单, 而且效率也不错

# include "leetcode.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
=======
// 二叉树的的最大深度
// 递归会很简单, 而且效率也不错

# include "leetcode.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
>>>>>>> b5bceb60679d9e4014bc49c7686be5965b5eb0ea
};