#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *detectCycle(struct ListNode *head) {
    typedef struct ListNode ListNode;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next != NULL && fast->next->next != NULL) //快指针一直在前面所以不用管slow
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
        else
        {
            return NULL;
        }
    }
}




int main(void)
{
    typedef struct ListNode ListNode;
    
    return 0;
}

/*
// 定义链表节点结构体
typedef struct LinkedNode{
    int val;
    struct LinkedNode* next;
} LinkedNode;

// 定义链表结构体，设置虚拟头节点以及链表长度
typedef struct
{
    LinkedNode* dummyhead;
    int size;
}MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    list->dummyhead = (LinkedNode* )malloc(sizeof(LinkedNode));
    list->dummyhead->next = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
   if(index < 0 || index >= obj->size)
        return -1;
    
    LinkedNode* cur = obj->dummyhead->next;
    while(index > 0)
    {
        cur = cur->next;
        index--;
    }
    return cur->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    LinkedNode* cur = (LinkedNode* )malloc(sizeof(LinkedNode));
    cur->next = obj->dummyhead->next;
    obj->dummyhead->next = cur;
    cur->val = val;
    (obj->size)++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    LinkedNode* cur = obj->dummyhead;
    LinkedNode* last = (LinkedNode* )malloc(sizeof(LinkedNode));
    last->next = NULL;
    last->val = val;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = last;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index < 0 || index > obj->size)
        return ;
    LinkedNode* cur = obj->dummyhead;
    LinkedNode* tmp = (LinkedNode* )malloc(sizeof(LinkedNode));
    tmp->val = val;
    
    while(index > 0)
    {
        cur = cur->next;
        index--;
    }

    tmp->next = cur->next;
    cur->next = tmp;
    obj->size++;

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return ;
    LinkedNode* cur = obj->dummyhead;
    while(index > 0)
    {
        cur = cur->next;
        index--;
    }
    LinkedNode* toDelete = cur->next;
    cur->next = toDelete->next;
    free(toDelete);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    LinkedNode* cur = obj->dummyhead;
    while (cur != NULL) {
        LinkedNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj);
}

*/