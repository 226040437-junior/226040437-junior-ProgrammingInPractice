#include <stdio.h>
#include "reports.h"
#include "budget.h"

void employeeReport(int employees[], int empCount) {
    printf("\n=== Employee Report ===\n");
    printf("Total employees: %d\n", empCount);
    if (empCount == 0) {
        printf("No employees to report.\n");
        return;
    }
    printf("Employee IDs: ");
    for (int i = 0; i < empCount; i++) {
        printf("%d ", employees[i]);
    }
    printf("\n");
}

void budgetReport(float budgets[], int budgetCount) {
    printf("\n=== Budget Report ===\n");
    printf("Number of budget items: %d\n", budgetCount);
    printf("Total budget: %.2f\n", calculateBudget(budgets, budgetCount));
}