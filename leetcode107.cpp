// 二叉树的层次遍历 II
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
// 我仍然使用BFS解法

/*
DFS解法
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = getDep(root);
        vector<vector<int>> ans(n, vector<int>());
        dfs(root, 0, ans, n - 1);
        return ans;
    }
    void dfs(TreeNode *root, int depth, vector<vector<int>>& ans, int n) {
        if (root == NULL) return ;
        ans[n - depth].push_back(root->val); // 倒着装 n - depth
        dfs(root->left, depth + 1, ans, n);
        dfs(root->right, depth + 1, ans, n);
    }
    int getDep(TreeNode *root) { // 求树的高度
        if (root == NULL) return 0;
        return max(getDep(root->left), getDep(root->right)) + 1;
    }
};


作者：lllllliuji-2
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/dfsbu-xu-yao-xuan-zhuan-shu-zu-shi-jian-fu-za-du-o/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处

*/
# include "leetcode.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> sRes;
        vector<vector<int>> res;
        queue<TreeNode*> curr, prev;
        if(root == NULL) return res;
        else
            prev.push(root);
        while(!prev.empty()){
            vector<int> subres;
            while(!prev.empty()){
                curr.push(prev.front());
                prev.pop();
            }
            while(!curr.empty()){
                TreeNode* currnode = curr.front();
                curr.pop();
                if(currnode == NULL) continue;
                else {
                    if(currnode->left != NULL) prev.push(currnode->left);
                    if(currnode->right != NULL) prev.push(currnode->right);
                    subres.push_back(currnode->val);
                }
            }
            sRes.push(subres);
        }
        while(!sRes.empty()){
            res.push_back(sRes.top());
            sRes.pop();
        }
        return res;
    }
};