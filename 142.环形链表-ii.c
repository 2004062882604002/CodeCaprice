/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    typedef struct ListNode ListNode;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL) // 快指针一直在前面所以不用管slow
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)  // 确定存在环形
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}