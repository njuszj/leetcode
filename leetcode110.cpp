// 平衡二叉树
// 给定一个二叉树，判断它是否是高度平衡的二叉树
// 本题中，一棵高度平衡二叉树定义为：
//    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1
// 我的理解似乎有点问题！
# include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        dst(1, root);
        set<int>::iterator iter_head = sDepth.begin(), iter_tail = sDepth.end();
        iter_tail--;
        if(*iter_tail - *iter_head > 1) return false;
        return true;
    }
private:
    set<int> sDepth;
    void dst(int depth, TreeNode* node){
        if(node->left == NULL && node->right == NULL) {
            // 叶子节点
            sDepth.insert(depth);
            return;
        }
        if(node->left != NULL)
            dst(depth+1, node->left);
        else sDepth.insert(depth);
        if(node->right != NULL)
            dst(depth+1, node->right);
        else sDepth.insert(depth);
    }
};