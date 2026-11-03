#include <stdio.h>
#include "budget.h"
#include "utilities.h"

void addBudget(Budget budgets[], int *count, int capacity) {
    if (*count >= capacity) { printf("Budget list is full.\n"); return; }
    Budget b;
    readString("Enter department: ", b.department, 20);
    b.allocated = readDouble("Enter allocated amount: ");
    b.spent = readDouble("Enter spent amount: ");

    budgets[*count] = b;
    (*count)++;
    printf("Budget added.\n");
}

void displayBudgets(Budget budgets[], int count) {
    if (count == 0) { printf("No budgets to display.\n"); return; }
    printf("\n%-20s %12s %12s %12s\n", "Department", "Allocated", "Spent", "Balance");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        double balance = budgets[i].allocated - budgets[i].spent;
        printf("%-20s %12.2f %12.2f %12.2f\n",
               budgets[i].department, budgets[i].allocated, 
               budgets[i].spent, balance);
    }
}

void increaseBudget(Budget *b, double amount) {
    b->allocated += amount;
    printf("Budget for %s increased by %.2f. New allocated: %.2f\n", 
           b->department, amount, b->allocated);
}