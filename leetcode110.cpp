// 平衡二叉树， 从本题尝试掌握自底向上递归方法
// 给定一个二叉树，判断它是否是高度平衡的二叉树
// 本题中，一棵高度平衡二叉树定义为：
//    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1
// 我的理解似乎有点问题！
// 自顶向上简单一点，但是存在冗余

/*
自底向上方法
class Solution {
private:
  // Return whether or not the tree at root is balanced while also storing
  // the tree's height in a reference variable. 
  bool isBalancedTreeHelper(TreeNode* root, int& height) {
    // An empty tree is balanced and has height = -1
    if (root == NULL) {
      height = -1;
      return true;
    }

    // Check subtrees to see if they are balanced. If they are, check if the 
    // current node is also balanced using the heights obtained from the 
    // recursive calls.
    int left, right;
    if (isBalancedTreeHelper(root->left, left)  &&
        isBalancedTreeHelper(root->right, right) &&
        abs(left - right) < 2) {
      // Store the current tree's height
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
public:
  bool isBalanced(TreeNode* root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};


作者：LeetCode
链接：https://leetcode-cn.com/problems/balanced-binary-tree/solution/ping-heng-er-cha-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



要点是先判断子树是否平衡再判断父节点

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        self.res = True
        def helper(root):
            if not root:
                return 0
            left = helper(root.left) + 1
            right = helper(root.right) + 1
            #print(right, left)
            if abs(right - left) > 1: 
                self.res = False
            return max(left, right)
        helper(root)
        return self.res

作者：powcai
链接：https://leetcode-cn.com/problems/balanced-binary-tree/solution/zi-ding-xiang-xia-he-zi-di-xiang-shang-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



*/
# include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left_depth = 1;
        int right_depth = 1;
        getDepth(root->left, left_depth, 1);
        getDepth(root->right, right_depth, 1);
        if(abs(left_depth - right_depth) > 1) return false;
        else return isBalanced(root->right) && isBalanced(root->left);
    }
private:
    void getDepth(TreeNode* node, int& max_depth, int curr_depth){
        if(node == NULL) {
            max_depth--;
            return;
        }
        if(node->left == NULL && node->right == NULL){
            if(curr_depth >= max_depth) max_depth = curr_depth;
            return;
        }
        if(node->right != NULL)
            getDepth(node->right, max_depth, curr_depth+1);
        if(node->left != NULL)
            getDepth(node->left, max_depth, curr_depth+1);
    }
};