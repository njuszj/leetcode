<<<<<<< HEAD
// Ìî³äÃ¿¸ö½ÚµãµÄÏÂÒ»¸öÓÒ²à½ÚµãÖ¸Õë
/*
¸ø¶¨Ò»¸öÍêÃÀ¶þ²æÊ÷£¬ÆäËùÓÐÒ¶×Ó½Úµã¶¼ÔÚÍ¬Ò»²ã£¬Ã¿¸ö¸¸½Úµã¶¼ÓÐÁ½¸ö×Ó½Úµã¡£¶þ²æÊ÷¶¨ÒåÈçÏÂ£º

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Ìî³äËüµÄÃ¿¸ö next Ö¸Õë£¬ÈÃÕâ¸öÖ¸ÕëÖ¸ÏòÆäÏÂÒ»¸öÓÒ²à½Úµã¡£Èç¹ûÕÒ²»µ½ÏÂÒ»¸öÓÒ²à½Úµã£¬Ôò½« next Ö¸ÕëÉèÖÃÎª NULL¡£

³õÊ¼×´Ì¬ÏÂ£¬ËùÓÐ next Ö¸Õë¶¼±»ÉèÖÃÎª NULL

À´Ô´£ºÁ¦¿Û£¨LeetCode£©
Á´½Ó£ºhttps://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
Öø×÷È¨¹éÁì¿ÛÍøÂçËùÓÐ¡£ÉÌÒµ×ªÔØÇëÁªÏµ¹Ù·½ÊÚÈ¨£¬·ÇÉÌÒµ×ªÔØÇë×¢Ã÷³ö´¦¡£
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
å¡«å……æ¯ä¸ªèŠ‚ç‚¹çš„ä¸‹ä¸€ä¸ªå³ä¾§èŠ‚ç‚¹æŒ‡é’ˆ

ç»™å®šä¸€ä¸ªå®Œç¾ŽäºŒå‰æ ‘ï¼Œå…¶æ‰€æœ‰å¶å­èŠ‚ç‚¹éƒ½åœ¨åŒä¸€å±‚ï¼Œæ¯ä¸ªçˆ¶èŠ‚ç‚¹éƒ½æœ‰ä¸¤ä¸ªå­èŠ‚ç‚¹
å¡«å……å®ƒçš„æ¯ä¸ª next æŒ‡é’ˆï¼Œè®©è¿™ä¸ªæŒ‡é’ˆæŒ‡å‘å…¶ä¸‹ä¸€ä¸ªå³ä¾§èŠ‚ç‚¹ã€‚å¦‚æžœæ‰¾ä¸åˆ°ä¸‹ä¸€ä¸ªå³ä¾§èŠ‚ç‚¹ï¼Œåˆ™å°† next æŒ‡é’ˆè®¾ç½®ä¸º NULL
*/

/*
è§£å†³æ–¹æ¡ˆ1é€’å½’:
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
å…³é”®æ˜¯åˆ©ç”¨å·²ç»å»ºç«‹çš„nextæŒ‡é’ˆå»ºç«‹æ–°çš„nextæŒ‡é’ˆ
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