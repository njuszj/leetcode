<<<<<<< HEAD
// 填充每个节点的下一个右侧节点指针
/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
濉厖姣忎釜鑺傜偣鐨勪笅涓�涓彸渚ц妭鐐规寚閽�

缁欏畾涓�涓畬缇庝簩鍙夋爲锛屽叾鎵�鏈夊彾瀛愯妭鐐归兘鍦ㄥ悓涓�灞傦紝姣忎釜鐖惰妭鐐归兘鏈変袱涓瓙鑺傜偣
濉厖瀹冪殑姣忎釜 next 鎸囬拡锛岃杩欎釜鎸囬拡鎸囧悜鍏朵笅涓�涓彸渚ц妭鐐广�傚鏋滄壘涓嶅埌涓嬩竴涓彸渚ц妭鐐癸紝鍒欏皢 next 鎸囬拡璁剧疆涓� NULL
*/

/*
瑙ｅ喅鏂规1閫掑綊:
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
鍏抽敭鏄埄鐢ㄥ凡缁忓缓绔嬬殑next鎸囬拡寤虹珛鏂扮殑next鎸囬拡
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