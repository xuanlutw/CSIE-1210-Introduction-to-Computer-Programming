#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
 
Node* mk_list(int n) {
    Node *head;
    Node *front;
    for (int i = 0; i < n; i++) {
        Node *u;
        u = (Node*)malloc(sizeof(Node));
        u->v = sp_rand(), u->next = NULL;
        if (!i){
            head = u;
            front = u;
        }
        else{
            front->next = u;
            front = u;
        }
    }
    return head;
}

void rm_list(Node *head) {
    Node *tmp;
    while(1){
        tmp = head->next;
        if (!tmp->next || !tmp) break;
        free(head);
        head = tmp;
        tmp = tmp->next;
    }
    free(head);
    free(tmp);
    return;
}
