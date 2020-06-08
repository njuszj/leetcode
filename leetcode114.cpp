// 二叉树转展开为链表
// 将二叉树按先序遍历的顺序原地展开为(仍使用树结构的)链表

/*

    将左子树插入到右子树的地方
    将原来的右子树接到左子树的最右边节点
    考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null

*/

# include "leetcode.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* curr_node = root;
        while(curr_node != NULL){
            TreeNode* right_node = curr_node->right;
            TreeNode* left_node = curr_node->left;
            if (left_node == NULL)
            {
                curr_node = curr_node -> right;
                continue;
            }
            curr_node->right = left_node;
            TreeNode* right_edge = NULL;
            while(left_node != NULL && left_node->right != NULL){
                // 找到左子树的最右节点
                left_node = left_node->right;
            }
            left_node->right = right_node;
            curr_node -> left = NULL;
            curr_node = curr_node -> right;
        }
    }
};