#include "myint.h"
#include "singletest.c"
 
static int madd(int a, int b) {
    return a + b;
}
static int msub(int a, int b) {
    return a - b;
}
int getmyheart(int (*FUNC[])(int, int)) {
    secret();
    test_heart();
    FUNC[0] = madd;
    FUNC[1] = msub;
    return 2;
}
