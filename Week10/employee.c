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

//

#include <stdlib.h>  

#define EMP_TEXT_FILE   "data/employees.txt"
#define EMP_BINARY_FILE "data/employees.dat"

int saveEmployeesText(int employee[], int length) {
    FILE *fp = fopen(EMP_TEXT_FILE, "w");
    if (fp == NULL) { perror(EMP_TEXT_FILE); return 0; }
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%d\n", employee[i]);
    }
    fclose(fp);
    printf("Saved %d employee ID(s) to %s\n", length, EMP_TEXT_FILE);
    return 1;
}

int loadEmployeesText(int employee[], int *length, int capacity) {
    FILE *fp = fopen(EMP_TEXT_FILE, "r");
    if (fp == NULL) { perror(EMP_TEXT_FILE); return 0; }
    int loaded = 0, id;
    while (loaded < capacity && fscanf(fp, "%d", &id) == 1) {
        employee[loaded++] = id;
    }
    fclose(fp);
    *length = loaded;
    printf("Loaded %d employee ID(s) from %s\n", loaded, EMP_TEXT_FILE);
    return 1;
}

int saveEmployeesBinary(int employee[], int length) {
    FILE *fp = fopen(EMP_BINARY_FILE, "wb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    size_t written = fwrite(employee, sizeof(int), (size_t)length, fp);
    fclose(fp);
    if (written != (size_t)length) {
        printf("Warning: only %zu of %d IDs written.\n", written, length);
        return 0;
    }
    printf("Saved %d employee ID(s) to %s (binary)\n", length, EMP_BINARY_FILE);
    return 1;
}

int loadEmployeesBinary(int employee[], int *length, int capacity) {
    FILE *fp = fopen(EMP_BINARY_FILE, "rb");
    if (fp == NULL) { perror(EMP_BINARY_FILE); return 0; }
    size_t loaded = fread(employee, sizeof(int), (size_t)capacity, fp);
    fclose(fp);
    *length = (int)loaded;
    printf("Loaded %d employee ID(s) from %s (binary)\n", *length, EMP_BINARY_FILE);
    return 1;
}