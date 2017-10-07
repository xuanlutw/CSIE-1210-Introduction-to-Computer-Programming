typedef struct memory{
    int type;
    int start;
    int length;
    struct memory* next;
    struct memory* pre;
}Memory;

void initMemory(Memory *memory, int length);
void printMemory(Memory *memory);
void allocateMemory(Memory *memory, int start, int length);
void freeMemory(Memory *memory, int start, int length);
