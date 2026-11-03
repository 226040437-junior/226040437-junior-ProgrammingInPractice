#include <stdio.h>
#include "employee.h"

void addEmployee(int id, int employee[], int length) {
    employee[length] = id;
}

void listEmployee(int employee[], int length) {
    for (int i = 0; i < length; i++) {
        printf("Employee n: %d\n", employee[i]);   /* FIXED: added \n */
    }
}

int searchEmployee(int searchID, int emp[], int length) {
    for (int i = 0; i < length; i++) {
        if (emp[i] == searchID) {
            return i;
        }
    }
    return -1;
}