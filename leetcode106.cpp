// 从中序与后序遍历序列构造二叉树
// 这一题与上一题类似, 思路也是一样的
// 从本题我也获得了一个结论: 当一个二叉树的前序遍历与后序遍历的结果恰好相反时，二叉树

# include "leetcode.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return NULL;
        TreeNode* node = new TreeNode(postorder[postorder.size()-1]);   // 取最后一个节点，就是根节点
        if(postorder.size() == 1) return node;
        vector<int>::iterator mid_iter = find(inorder.begin(), inorder.end(), postorder[postorder.size()-1]);  // 找到根节点的位置，区分左右子树
        int left_len = distance(inorder.begin(), mid_iter);  // 左子树节点数
        vector<int>::iterator right_iter = postorder.begin() + left_len;   // 左子树分界点
        vector<int> left_postorder(postorder.begin(), right_iter);   // 构造递归要使用的子树
        vector<int> right_postorder(right_iter, postorder.end()-1);
        vector<int> left_inorder(inorder.begin(), mid_iter);
        vector<int> right_inorder(mid_iter+1, inorder.end());
        node->left = buildTree(left_inorder, left_postorder);  // 递归构造
        node->right = buildTree( right_inorder, right_postorder);
        return node;
    }
};


int main(){
    Solution s;
    vector<int> in = {9,3,15,20,7};
    vector<int> post = {9,15,7,20,3};
    s.buildTree(in, post);
}