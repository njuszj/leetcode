// 删除排序链表中的重复元素
// 删除后节点的方法实在要考虑太多了。。。还是添加哨兵用三指针吧!

# include "leetcode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head, *curr = head;
        if(curr == NULL) return curr;
        curr = curr->next;
        while(curr != NULL){
            int flag = 0;
            int val = prev->val;
            cout << "prev" << prev->val << " " << "curr" << curr->val << endl;
            cout << "prev->next " << prev->next->val << endl;
            while(curr != NULL){
                if(curr->val == val){
                    // 删除重复元素
                    flag = 1;
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                else break;
            }
            if(flag){
                // 删除prev
                if(prev->next == NULL){
                    if(prev == head)
                        head = NULL;
                    delete prev;
                    prev = NULL;
                    curr = NULL;
                }
                else{
                    if(curr!=NULL)
                        curr = curr->next;
                    ListNode* ptmp = prev->next->next;
                    prev->val = prev->next->val;
                    delete prev->next;
                    prev->next = ptmp;
                }
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* l = initList({1,2,2});
    printList(l);
    Solution s;
    ListNode* r = s.deleteDuplicates(l);
    printList(r);
}