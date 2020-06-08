// ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��II
// ������ڵ��ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
// �ؼ���ʹ���Ѿ�������nextָ��
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
        Node* first;      // ����ߵ��ӽڵ�
        Node* work = NULL;       // �����ӽڵ�
        Node* curr = root;
        while (curr != NULL) {
            // �ҵ�����ߵ��ӽڵ����ڵݹ�
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

