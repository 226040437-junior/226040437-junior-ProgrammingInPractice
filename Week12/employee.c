#include <stdio.h>
#include "employee.h"
#include "utilities.h"

#define EMP_BINARY_FILE "data/employees.dat"

void addEmployee(Employee employees[], int *count, int capacity) {
    if (*count >= capacity) {
        printf("Employee list is full.\n");
        return;
    }
    Employee e;
    e.id = readInt("Enter employee ID: ");
    readString("Enter name: ", e.name, 30);
    readString("Enter department: ", e.department, 20);
    e.salary = readDouble("Enter salary: ");

    employees[*count] = e;
    (*count)++;
    printf("Employee added successfully.\n");
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) { printf("No employees to display.\n"); return; }
    printf("\n%-6s %-15s %-15s %12s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-15s %-15s %12.2f\n",
               employees[i].id, employees[i].name, 
               employees[i].department, employees[i].salary);
    }
}

int saveEmployeesBinary(Employee employees[], int count) {
    FILE *fp = fopen(EMP_BINARY_FILE, "wb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    fwrite(employees, sizeof(Employee), count, fp);
    fclose(fp);
    printf("Saved %d employee(s) to %s (binary)\n", count, EMP_BINARY_FILE);
    return 1;
}

int loadEmployeesBinary(Employee employees[], int *count, int capacity) {
    FILE *fp = fopen(EMP_BINARY_FILE, "rb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    size_t loaded = fread(employees, sizeof(Employee), capacity, fp);
    fclose(fp);
    *count = (int)loaded;
    printf("Loaded %d employee(s) from %s (binary)\n", *count, EMP_BINARY_FILE);
    return 1;
}

void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (list[i].id == id) {
            return &list[i]; /* Return pointer to the actual struct in the array */
        }
    }
    return NULL;
}