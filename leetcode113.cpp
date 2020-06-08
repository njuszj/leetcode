// 路径之和II
// 这次要输出路径
// 感觉使用迭代效率会更高

# include "leetcode.h"

class Solution {
public:
    vector<vector<int>> pathSumByDST(TreeNode* root, int sum) {
        isMatched(root, {}, 0, sum);
        return this->res;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        // 错误，这不是路径栈
        vector<vector<int>> res;
        if(root == NULL) return res;
        stack<TreeNode*> path;
        stack<int> path_sum;
        path.push(root);
        path_sum.push(root->val);
        int curr_sum = 0;
        while(!path.empty()){
            TreeNode* curr = path.top();
            path.pop();
            curr_sum = path_sum.top();
            path_sum.pop();
            if(curr->right != NULL){
                path.push(curr->right);
                path_sum.push(curr_sum + curr->right->val);
            }
            if(curr->left != NULL){
                path.push(curr->left);
                path_sum.push(curr_sum + curr->left->val);
            }            
            if(curr->left == NULL && curr->right == NULL && curr_sum == sum){
                // 找到满足条件的叶子节点
                vector<int> vTmp;
                stack<TreeNode*> sTmp = path;
                while(!sTmp.empty()){
                    vTmp.push_back(sTmp.top()->val);
                    sTmp.pop();
                }
                res.push_back(vTmp);
            }
        }
        return res;
    }
private:
    vector<vector<int>> res;
    void isMatched(TreeNode* node, vector<int> path, int curr_sum, int sum){
        if(node == NULL) return;
        curr_sum += node->val;
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL) {
            if(curr_sum == sum)
                res.push_back(path);
            return;
        }
        if(node->left != NULL) isMatched(node->left, path, curr_sum, sum);
        if(node->right != NULL) isMatched(node->right, path, curr_sum, sum);
    }
};