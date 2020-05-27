// 二叉树的最小深度

# include "leetcode.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        dst(1, root);
        return *(sDepth.begin());
    }
private:
    set<int> sDepth;
    void dst(int depth, TreeNode* node){
        // 这个函数用来获得所有叶子节点的深度
        if(node->left == NULL && node->right == NULL) {
            // 叶子节点
            sDepth.insert(depth);
            return;
        }
        if(node->left != NULL)
            dst(depth+1, node->left);
        if(node->right != NULL)
            dst(depth+1, node->right);
    }
};