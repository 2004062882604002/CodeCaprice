/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    typedef struct ListNode ListNode;
    ListNode* curA = headA;
    ListNode* curB = headB;
    // 定义链表长度
    int lengthA = 0;
    int lengthB = 0;
    // 求链表A长度
    while(curA)
    {
        curA = curA->next;
        lengthA++;
    }
    // 求链表B长度
    while(curB)
    {
        curB = curB->next;
        lengthB++;
    }
    // 计算两个链表差值
    int dif = abs(lengthA - lengthB);
    curA = headA;
    curB = headB;
    int index;
    // 两个链表尾部对齐
    if(lengthA > lengthB)
    {  
        for(int i = 0; i < dif; i++)
        {
            curA = curA->next;
        }
        index = lengthB;
    }
    else
    {
        for(int i = 0; i < dif; i++)
        {
            curB = curB->next;
        }
        index = lengthA;
    }
    // 比较是否有交点
    while(curA != curB && index >= 0)
    {
        curA = curA->next;
        curB = curB->next;
        index--;
    }
    // 判断
    if(index == -1)
    {
        return NULL;
    }
    else
    {
        return curA;
    }
}