#include <stdio.h>
#include <stdlib.h>
#include "node.h"
 
#define LEN 1000
 
struct node * build(int n) {
    struct node * head, * ptr;
    int i;
 
    if (!n)
        return 0;
 
    head = (struct node *) malloc(sizeof(struct node));
    ptr = head;
    for (i = 1; i < n; i++) {
        ptr -> next = (struct node *) malloc(sizeof(struct node));
        ptr = ptr -> next;
    }
    ptr -> next = 0;
    return head;
}
 
int main() {
    int n1, i;
    struct node * list1;
    scanf("%d", &n1);
    list1 = build(n1);
    scanf("%d", &i);
    struct node * gg = getNode(list1, i);
    while (list1 != gg && gg != NULL){
        printf("PASS\n");
        list1 = list1->next;
    }     
    return 0;
}
