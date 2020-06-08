<<<<<<< HEAD
// 相同的树
// 使用深度优先遍历，不过似乎并不成功...
// 老实递归吧..效率并不差

# include "leetcode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
=======
// 相同的树
// 使用深度优先遍历，不过似乎并不成功...
// 老实递归吧..效率并不差

# include "leetcode.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
>>>>>>> b5bceb60679d9e4014bc49c7686be5965b5eb0ea
};