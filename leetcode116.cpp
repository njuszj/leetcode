<<<<<<< HEAD
// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
/*
����һ��������������������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��

��ʼ״̬�£����� next ָ�붼������Ϊ NULL

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

# include "leetcode.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        Node *curr = root, *prev = NULL;
        while (curr != NULL) {
            if (curr->left != NULL && curr->right != NULL) {
                curr->left->next = curr->right;
                if (prev != NULL) prev->right->next = curr->left;
            }
            prev = curr;
            curr = curr->next;
        }
        connect(root->left);
        return root;
    }
=======
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
>>>>>>> b5bceb60679d9e4014bc49c7686be5965b5eb0ea
};