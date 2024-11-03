#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList* )malloc(sizeof(MyLinkedList));
    obj->next = NULL;
    obj->val = INT_MAX;
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

