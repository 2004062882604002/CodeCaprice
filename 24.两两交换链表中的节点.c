/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode* dummyhead = (ListNode* )malloc(sizeof(ListNode));
    dummyhead->next = head;
    ListNode* cur = dummyhead;
    while(cur->next != NULL  && cur->next->next != NULL)
    {
        ListNode* temp = cur->next;
        ListNode* temp1 =  cur->next->next->next;
        cur->next = cur->next->next;
        cur->next->next = temp;
        temp->next = temp1;

        cur = cur->next->next;
    }
    return dummyhead->next;
}
// @lc code=end

