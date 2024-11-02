#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
     struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val);
int main(void)
{

    return 0;
}
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

