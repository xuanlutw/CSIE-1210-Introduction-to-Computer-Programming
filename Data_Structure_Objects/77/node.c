#include<stdio.h>
#include"node.h"

struct node *getNode(struct node *head, unsigned int i){
    unsigned int length = 0;
    struct node *nxt = head;
    while (1){
        ++length;
        if (nxt->next == NULL) break;
        nxt = nxt->next;
    }
    if (i >= length) return NULL;
    nxt = head;
    for (int j = 0;j < (length - i - 1);++j) nxt = nxt->next;
    return nxt;
}
         
