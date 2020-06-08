// 分隔链表
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
// 你应当保留两个分区中每个节点的初始相对位置

// 使用一个虚拟x节点做分隔，将小于x的节点全部链接到x节点之前，然后删除x节点
// 因为链表的操作只要改变连接关系不用新建空间，所以有更简洁的解法: 使用before, after两个指针，分别链接大小节点

# include "leetcode.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* origin_head = head;
        ListNode *curr = head, *left = NULL;
        ListNode* nodex = new ListNode(x);  // 虚拟x节点, 链接到头部
        nodex->next = head;
        ListNode *prev=nodex;
        int head_flag = 1;
        while(curr != NULL){
            if(curr->val < x){
                // 应该在x节点左边，采用尾插法
                ListNode* tmp = curr;
                curr = curr->next;
                if(left)
                    left->next = tmp;  // 插入x节点左边
                tmp->next = nodex; // 位置是左边的尾部
                if(head_flag){
                    // 设置头结点
                    head_flag = 0;
                    head = tmp;
                }
                left = tmp;
                prev->next = curr;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        if(left == nodex){
            delete nodex;
            return origin_head;
        }
        else{
            left->next = nodex->next;
            delete nodex;
            return head;
        }
    }
};