/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur != NULL)
    {
        ListNode* temp;
        temp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = temp;
    }
    return pre;
}
// @lc code=end

