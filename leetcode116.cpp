/*
填充每个节点的下一个右侧节点指针

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL
*/

/*
解决方案1递归:
    class Solution {
        public:
            void connect(TreeLinkNode *root) {
                if (root == NULL || root->left == NULL)
                    return;
                root->left->next = root->right;
                if (root->next)
                    root->right->next = root->next->left;
                connect(root->left);
                connect(root->right);
            }
    };
关键是利用已经建立的next指针建立新的next指针
*/

# include "leetcode.h"

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

class Solution {
public:
    Node* connect(Node* root) {
        
    }
private:
    void helper(Node* node, int layer){
         
    }
};