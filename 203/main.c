/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */

// @lc code=start


struct ListNode {
      int val;
     struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    typedef struct ListNode ListNode;
    ListNode* dNode;
    dNode = (ListNode* )malloc(sizeof(ListNode));
    dNode->next = head;
    ListNode* cru = dNode;
    while(cru->next != NULL)
    {
        if(cru->next->val == val)
        {
            ListNode* tmp = cru->next;
            cru->next = cru->next->next;
            free(tmp);
        }
        else
        {
            cru = cru->next;
        }
    }
    head = dNode->next;
    free(dNode);
    return head;
}
// @lc code=end

