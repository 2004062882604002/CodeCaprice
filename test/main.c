#include <stdio.h>
#include <stdlib.h>

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
}LinkedList;


LinkedList* myLinkedListCreate() {
    LinkedList* list = (LinkedList* )malloc(sizeof(LinkedList));
    list->dummyhead = (LinkedNode* )malloc(sizeof(LinkedNode));
    list->dummyhead->next = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(LinkedList* obj, int index) {
   if(index < 0 || index > obj->size - 1)
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
    if(obj->val != INT_MAX)
    {
        MyLinkedList* head = (MyLinkedList* )malloc(sizeof(MyLinkedList));
        head->val = val;
        head->next = obj;
        obj = head;
        
    }
    else
    {
        obj->val = val;
    }
    
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* cur = obj;
    MyLinkedList* tmp = cur;
    while (cur->next != NULL)
    {
        tmp = cur;
        cur = cur->next;
    }
    MyLinkedList* last = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    last->val =  val;
    last->next = NULL;
    tmp->next = last;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* cur = obj;
    MyLinkedList* middle = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    MyLinkedList* tmp;
    while(cur->next != NULL)
    {
        if(index == 0)
        {
            tmp->next = middle;
            middle->next = cur;
            middle->val = val;
        }
        else
        {
            tmp = cur;
            cur = cur->next;
            index--;
        }
    }
    if(index == 0)
    {
        tmp->next = middle;
        middle->next = cur;
        middle->val = val;
    }
    else if(index == 1)
    {
        cur->next = middle;
        middle->next = NULL;
        middle->val = val;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* shead;
    shead = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    shead->next = obj;
    MyLinkedList* cur = shead;
    while(cur->next != NULL)
    {
        if(index == 0)
        {
             MyLinkedList* tmp = cur->next;
             cur->next = cur->next->next;
             free(tmp);
             break;
        }
        else
        {
            cur = cur->next;
            index--;
        }
        
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}



int main(void)
{
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 7);
    myLinkedListAddAtHead(obj, 2);
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtIndex(obj, 3,0);
    myLinkedListDeleteAtIndex(obj, 2);
    myLinkedListAddAtHead(obj, 6);
    myLinkedListAddAtTail(obj, 4);
    int a = myLinkedListGet(obj,4);
    myLinkedListAddAtHead(obj, 4);
    myLinkedListAddAtIndex(obj, 5, 0);
    myLinkedListAddAtHead(obj, 6);

    return 0;
}

