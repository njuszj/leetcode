// 填充每个节点的下一个右侧节点指针II
// 填充树节点的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
// 关键是使用已经建立的next指针
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
        if (root == NULL) return root;
        Node* first;      // 最左边的子节点
        Node* work = NULL;       // 工作子节点
        Node* curr = root;
        while (curr != NULL) {
            // 找到最左边的子节点用于递归
            if (curr->left != NULL) { first = curr->left; break; }
            if (curr->right != NULL) { first = curr->right; break; }
            curr = curr->next;
        }
        curr = root;
        while (curr != NULL) {
            if (curr->left != NULL && curr->right != NULL) {
                curr->left->next = curr->right;
                if (work != NULL) {
                    work->next = curr->left;
                }
                work = curr->right;
            }
            else if (curr->left != NULL && curr->right == NULL) {
                if (work != NULL) {
                    work->next = curr->left;
                }
                work = curr->left;
            }
            else if (curr->left == NULL && curr->right != NULL) {
                if (work != NULL) {
                    work->next = curr->right;
                }
                work = curr->right;
            }
            curr = curr->next;
        }
        connect(first);
        return root;
    }
};

