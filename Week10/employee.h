#ifndef EMPLOYEES_H
#define EMPLOYEES_H

void addEmployee(int id, int employee[], int length);
void listEmployee(int employee[], int length);
int  searchEmployee(int searchID, int emp[], int length);

//

int saveEmployeesText(int employee[], int length);
int loadEmployeesText(int employee[], int *length, int capacity);


int saveEmployeesBinary(int employee[], int length);
int loadEmployeesBinary(int employee[], int *length, int capacity);

#endif