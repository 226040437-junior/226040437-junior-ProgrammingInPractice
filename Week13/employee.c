#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utilities.h"

#define EMP_BINARY_FILE "data/employees.dat"

void addEmployee(Employee **employees, int *count, int *capacity) {
   
    if (*count == *capacity) {
        int newCapacity = (*capacity == 0) ? 2 : (*capacity * 2);
        Employee *temp = realloc(*employees, newCapacity * sizeof(Employee));
        
        if (temp == NULL) {
            printf("Out of memory! Cannot add employee.\n");
            return;
        }
        
        *employees = temp; 
        *capacity = newCapacity;
        printf("(Array grown to %d slots)\n", *capacity);
    }

   
    Employee e;
    e.id = readInt("Enter employee ID: ");
    readString("Enter name: ", e.name, 30);
    readString("Enter department: ", e.department, 20);
    e.salary = readDouble("Enter salary: ");

    (*employees)[*count] = e;
    (*count)++;
    printf("Employee added successfully.\n");
}



int saveEmployeesBinary(Employee employees[], int count) {
    FILE *fp = fopen(EMP_BINARY_FILE, "wb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    fwrite(employees, sizeof(Employee), count, fp);
    fclose(fp);
    printf("Saved %d employee(s) to %s (binary)\n", count, EMP_BINARY_FILE);
    return 1;
}

int loadEmployeesBinary(Employee **employees, int *count, int *capacity) {
    FILE *fp = fopen(EMP_BINARY_FILE, "rb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    
    
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    int numRecords = fileSize / sizeof(Employee);
    
    if (numRecords > *capacity) {
       
        Employee *temp = realloc(*employees, numRecords * sizeof(Employee));
        if (temp == NULL) {
            printf("Out of memory during load!\n");
            fclose(fp);
            return 0;
        }
        *employees = temp;
        *capacity = numRecords;
        printf("(Array grown to %d slots to fit file)\n", *capacity);
    }
    
    size_t loaded = fread(*employees, sizeof(Employee), *capacity, fp);
    fclose(fp);
    *count = (int)loaded;
    printf("Loaded %d employee(s) from %s (binary)\n", *count, EMP_BINARY_FILE);
    return 1;
}