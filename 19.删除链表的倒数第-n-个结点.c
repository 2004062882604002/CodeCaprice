/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode;
    ListNode* dummyhead = (ListNode* )malloc(sizeof(ListNode));  // 定义虚拟头节点
    dummyhead->next = head;
    // 定义快慢指针
    ListNode* quk = dummyhead;
    ListNode* slow = dummyhead;
    int index = 0;
    // 快指针先走的 n-1 步，因为我的循环结束判断条件是快指针“指向NULL”
    while(quk->next != NULL)
    {
        if(index < n)
        {
            quk = quk->next;
            index++;
        }
        else
        {
            quk = quk->next;
            slow = slow->next;
        }  
    }
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return dummyhead->next;
}
// @lc code=end

