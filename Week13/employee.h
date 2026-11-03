#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"


void addEmployee(Employee **employees, int *count, int *capacity);
void displayEmployees(Employee employees[], int count);

/* From Week 12 */
Employee *findEmployee(Employee list[], int count, int id);
void updateSalary(Employee *e, double newSalary);

int saveEmployeesBinary(Employee employees[], int count);
int loadEmployeesBinary(Employee **employees, int *count, int *capacity);

#endif