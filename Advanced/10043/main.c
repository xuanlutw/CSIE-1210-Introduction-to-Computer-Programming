#include <stdio.h>
#include <assert.h>
#include "myint.h"
 
int madd(int a, int b) {
    return a + b;
}
int msub(int a, int b) {
    return a - b; 
}
 
int main() {
    int (*FUNC[8])(int, int);
    int ret = getmyheart(FUNC);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("#function = %d\n", ret);
 
    printf("test function add\n");
    assert(FUNC[0](a, b) == madd(a, b));
    printf("test function sub\n");
    assert(FUNC[1](a, b) == msub(a, b));
 
    return 0;
}
