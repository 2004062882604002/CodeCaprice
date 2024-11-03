/*
 * @lc app=leetcode.cn id=707 lang=c
 *
 * [707] 设计链表
 */

// @lc code=start



typedef struct {
    int val;
    struct NodeList* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    typedef struct MyLinkedList NodeList;
    NodeList* obj = (NodeList* )malloc(sizeof(NodeList));
    obj->next = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    typedef struct MyLinkedList NodeList;
    NodeList* cur;
    cur->obj;
    while(cur->next != NULL)
    {       
        if(index < 0)
        {
            return cur->val;
        }
        else
        {
            cur = cur->next;
            index--
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    typedef struct MyLinkedList NodeList;
    NodeList* head = (NodeList* )malloc(sizeof(NodeList));
    head->val = val;
    head->next = obj;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    typedef struct MyLinkedList NodeList;
    NodeList* cur = obj;
    NodeList* tmp;
    while (cur->next != NULL)
    {
        tmp = cur;
        cur = cur->next;
    }
    NodeList* last = (NodeList* )malloc(sizeof(NodeList));
    last->val =  val;
    last->next = NULL;
    tmp->next = last;
    free(tmp);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    typedef struct MyLinkedList NodeList;
    NodeList* cur = obj;
    NodeList* middle = (NodeList* )malloc(sizeof(NodeList));
    NodeList* tmp;
    while(cur->next != NULL)
    {
        if(index == 0)
        {
            cur = tmp;
            cur->next = middle;
            middle = tmp->next;
            middle->val = val;
            free(tmp);
        }
        else
        {
             cur = cur->next;
            index--;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    typedef struct MyLinkedList NodeList;
    NodeList* shead;
    shead->next = obj;
    NodeList* cur = shead;
    while(cue->next != NULL)
    {
        if(index == 0)
        {
             NodeList* tmp = cur->next;
             cur->next = cur->next->next;
             free(tmp);
        }
        else
        {
            cue = cue->next;
            index--;
        }
        
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
// @lc code=end

