#include"heap.h"

void initialize(struct Heap *heap){
    heap->num = 0;
}

int removeMin(struct Heap *heap){
    int min = 0x7fffffff, index;
    for (int i = 0;i < heap->num;++i){
        if (heap->ary[i] < min){
            min = heap->ary[i];
            index = i;
        }
    }
    heap->ary[index] = heap->ary[heap->num - 1];
    --heap->num;
    return min;
}

void add(struct Heap *heap, int i){
    if (heap->num == MAXHEAP) return;
    heap->ary[heap->num] = i;
    ++heap->num;
    return;
}

int isFull(struct Heap *heap){
    return heap->num == MAXHEAP;
}

int isEmpty(struct Heap *heap){
    return heap->num == 0;
}
