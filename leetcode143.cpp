// 重排列表
// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

# include "leetcode.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        head = reverse(head);
    }
private:
    ListNode* reverse(ListNode* head){
        // 反转链表
        if(head == NULL) return NULL;
        ListNode* tmphead = new ListNode(0);
        tmphead->next = head;
        ListNode *first = tmphead, *second = head, *third = head;
        third = third->next;
        while(second != NULL){
            if(second == head) second->next = NULL;
            else second -> next = first;
            first = second;
            second = third;
            if(third != NULL)
                third = third->next;
            else
                break;
        }
        tmphead->next = first;
        return first;
    }
};

int main(){
    ListNode* l = initList({1,2,3,4,5,6});
    Solution s;
    s.reorderList(l);
    printList(l);
}
