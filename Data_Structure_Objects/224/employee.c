#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id(Employee *set, int n, int id){
    for (int i = 0;i < n;++i){
        if ((set + i)->id == id) return (set + i);
    }
    return NULL;
}

Employee* find_employee_by_name(Employee *set, int n, const char *first_name, const char *last_name){
    for (int i = 0;i < n;++i){
        if (!strcmp((set + i)->first_name, first_name) && !strcmp((set + i)->last_name, last_name)) return (set + i);
    }
    return NULL;
}

Employee* find_root_boss(Employee *set, int n, Employee *employee){
    while (1){
        if (employee->boss_id == employee->id) return employee;
        employee = find_employee_by_id(set, n, employee->boss_id);
    }
    return NULL;
}

int check_relationship(Employee *set, int n, Employee *A, Employee *B){
    Employee *employee = A;
    while (1){
        if (employee == B) return 1;
        if (employee->boss_id == employee->id) break;
        employee = find_employee_by_id(set, n, employee->boss_id);
    }
    employee = B;
    while (1){
        if (employee == A) return 2;
        if (employee->boss_id == employee->id) break;
        employee = find_employee_by_id(set, n, employee->boss_id);
    }
    if (find_root_boss(set, n, A) == find_root_boss(set, n, B)) return 3;
    return 4;
}

