#include<stdio.h>
#include<stdlib.h>
#include"memory.h"

void initMemory(Memory *memory, int length){
    memory->type = 1;
    memory->start = 0;
    memory->length = length;
    memory->next = NULL;
    memory->pre = NULL;
}	

void printMemory(Memory *memory){
    printf("==========\n");
    while (memory != NULL){
        if (memory->type) printf("start %d, length %d\n", memory->start, memory->length);
        memory = memory->next;
    }
    return;
}

void combineMemory(Memory *memory){
    while (1){
        if (memory->next == NULL) break;
        if (memory->next->start == memory->start + memory->length && memory->type == memory->next->type){
            Memory* tmp = memory->next;
            memory->length += memory->next->length;
            memory->next = memory->next->next;
            if (memory->next != NULL) memory->next->pre = memory;
            free(tmp);
            continue;
        }
        memory = memory->next;
    }
    return;
}

void allocateMemory(Memory *head, int start, int length){
    Memory *memory = head;
    while (1){
        if (memory->start <= start && memory->start + memory->length >= start + length) break;
        memory = memory->next;
    }
    if (start == memory->start && length == memory->length){
        memory->type = 0;
    }
    else if (start == memory->start){
        Memory* tmp;
        tmp = (Memory*)malloc(sizeof(Memory));
        tmp->type = 1;
        tmp->start = start + length;
        tmp->length = memory->start + memory->length - start - length;
        memory->type = 0;
        memory->length = length;
        tmp->next = memory->next;
        tmp->pre = memory;
        if (memory->next != NULL) memory->next->pre = tmp;
        memory->next = tmp;
    }
    else if (start + length == memory->start + memory->length){
        Memory* tmp;
        tmp = (Memory*)malloc(sizeof(Memory));
        tmp->type = 0;
        tmp->start = start;
        tmp->length = length;
        memory->length = memory->length - length;
        tmp->next = memory->next;
        tmp->pre = memory;
        if (memory->next != NULL) memory->next->pre = tmp;
        memory->next = tmp;
    }
    else{
        Memory* tmp1;
        tmp1 = (Memory*)malloc(sizeof(Memory));
        Memory* tmp2;
        tmp2 = (Memory*)malloc(sizeof(Memory));
        tmp1->type = 0;
        tmp1->start = start;
        tmp1->length = length;
        tmp2->type = 1;
        tmp2->start = start + length;
        tmp2->length = memory->start + memory->length - start - length;
        memory->length = start - memory->start;
        tmp1->next = tmp2;
        tmp2->next = tmp1;
        tmp1->pre = memory;
        tmp2->next = memory->next;
        if (memory->next != NULL) memory->next->pre = tmp2;
        memory->next = tmp1;
    }
    combineMemory(head);
    return;
}
 
void freeMemory(Memory *head, int start, int length){
    Memory *memory = head;
    while (1){
        if (memory->start <= start && memory->start + memory->length >= start + length) break;
        memory = memory->next;
    }
    if (start == memory->start && length == memory->length){
        memory->type = 1;
    }
    else if (start == memory->start){
        Memory* tmp;
        tmp = (Memory*)malloc(sizeof(Memory));
        tmp->type = 0;
        tmp->start = start + length;
        tmp->length = memory->start + memory->length - start - length;
        memory->type = 1;
        memory->length = length;
        tmp->next = memory->next;
        tmp->pre = memory;
        if (memory->next != NULL) memory->next->pre = tmp;
        memory->next = tmp;
    }
    else if (start + length == memory->start + memory->length){
        Memory* tmp;
        tmp = (Memory*)malloc(sizeof(Memory));
        tmp->type = 1;
        tmp->start = start;
        tmp->length = length;
        memory->length = memory->length - length;
        tmp->next = memory->next;
        tmp->pre = memory;
        if (memory->next != NULL) memory->next->pre = tmp;
        memory->next = tmp;
    }
    else{
        Memory* tmp1;
        tmp1 = (Memory*)malloc(sizeof(Memory));
        Memory* tmp2;
        tmp2 = (Memory*)malloc(sizeof(Memory));
        tmp1->type = 1;
        tmp1->start = start;
        tmp1->length = length;
        tmp2->type = 0;
        tmp2->start = start + length;
        tmp2->length = memory->start + memory->length - start - length;
        memory->length = start - memory->start;
        tmp1->next = tmp2;
        tmp2->next = tmp1;
        tmp1->pre = memory;
        tmp2->next = memory->next;
        if (memory->next != NULL) memory->next->pre = tmp2;
        memory->next = tmp1;
    }
    combineMemory(head);
    return;
}
