#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 5

/* Local struct for standalone testing */
typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

/* --- Part B: Swap Salaries --- */
void swapWrong(double a, double b) {
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

/* --- Part C: Arrays and Pointers --- */
void displaySalaries(const double salaries[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n) {
    double highest = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] > highest) highest = salaries[i];
    }
    return highest;
}

void giveRaise(double salaries[], int n, double percent) {
    for (int i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

/* --- Part D: Structs and Pointers --- */
void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary;
}

Employee *findEmployee(Employee list[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (list[i].id == id) {
            return &list[i]; /* return the address of the match */
        }
    }
    return NULL; /* not found */
}

int main(void) {
    printf("--- Part B: Swaps ---\n");
    double salA = 18500.50, salB = 21000.75;
    printf("Before swap: A = %.2f, B = %.2f\n", salA, salB);
    swapWrong(salA, salB);
    printf("After swapWrong: A = %.2f, B = %.2f (Unchanged!)\n", salA, salB);
    swapSalaries(&salA, &salB);
    printf("After swapSalaries: A = %.2f, B = %.2f (Swapped!)\n", salA, salB);

    printf("\n--- Part C: Array Pointers ---\n");
    double salaries[3] = {15000.00, 18500.50, 21000.75};
    displaySalaries(salaries, 3);
    printf("Highest: %.2f\n", findHighest(salaries, 3));
    giveRaise(salaries, 3, 10.0);
    printf("After 10%% raise:\n");
    displaySalaries(salaries, 3);

    printf("\n--- Part D: Struct Pointers ---\n");
    Employee staff[MAX_EMPLOYEES] = {
        {1001, "Maria", 18500.50},
        {1002, "Simon", 17200.00},
        {1003, "Anna", 21000.75}
    };
    int count = 3;
    
    Employee *found = findEmployee(staff, count, 1002);
    if (found != NULL) {
        printf("Found %s. Updating salary...\n", found->name);
        updateSalary(found, 19000.00);
        printf("%s now earns N$%.2f\n", found->name, found->salary);
    }
    
    found = findEmployee(staff, count, 9999);
    if (found == NULL) {
        printf("Employee 9999 not found (NULL returned).\n");
    }

    return 0;
}