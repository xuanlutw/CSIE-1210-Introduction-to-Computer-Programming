#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
    Employee *boss1 = employee1->boss;
    while (1){
        if (boss1 == employee2) return 1;
        if (boss1 == boss1->boss) break;
        boss1 = boss1->boss;
    }
    Employee *boss2 = employee2->boss;
    while (1){
        if (boss2 == employee1) return 2;
        if (boss2 == boss2->boss) break;
        boss2 = boss2->boss;
    }
    if (boss1 == boss2) return 3;
    return 4;
}
