#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    obj->next = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* cur = obj;
    while(cur != NULL)
    {       
        if(index == 0)
        {
            return cur->val;
        }
        else
        {
            cur = cur->next;
            index--;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj->next != NULL)
    {
        MyLinkedList* head = (MyLinkedList* )malloc(sizeof(MyLinkedList));
        head->val = val;
        head->next = obj;
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
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);    // 链表变为 1->2->3
    int a = myLinkedListGet(obj,1);              // 返回 2
    myLinkedListDeleteAtIndex(obj, 1);   // 现在，链表变为 1->3
    int b = myLinkedListGet(obj,1);              // 返回 3
    return 0;
}

