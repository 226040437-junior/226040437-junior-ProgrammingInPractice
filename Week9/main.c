#include <stdio.h>
#include "main.h"
#include "employee.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

#define MAX_EMPLOYEES 100
#define MAX_BUDGETS   100


void displayMainMenu(void) {
    printf("\n===== MFMS Main Menu =====\n");
    printf(" 1. Add employee\n");
    printf(" 2. List employees\n");
    printf(" 3. Search employee\n");
    printf(" 4. Add budget item\n");
    printf(" 5. Show budget total\n");
    printf(" 6. Show reports\n");
    printf(" 0. Exit\n");
}

int main(void) {
    int   employees[MAX_EMPLOYEES];
    int   employeeCount = 0;
    float budgets[MAX_BUDGETS];
    int   budgetCount = 0;
    int   choice;

    do {
        displayMainMenu();
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1: {
                if (employeeCount >= MAX_EMPLOYEES) {
                    printf("Employee list is full.\n");
                    break;
                }
                int id = readInt("Enter employee ID: ");
                addEmployee(id, employees, employeeCount);
                employeeCount++;                     /* caller increments */
                printf("Employee %d added.\n", id);
                break;
            }
            case 2:
                listEmployee(employees, employeeCount);
                break;
            case 3: {
                int id  = readInt("Enter employee ID to search: ");
                int idx = searchEmployee(id, employees, employeeCount);
                if (idx >= 0)
                    printf("Employee %d found at position %d.\n", id, idx);
                else
                    printf("Employee %d not found.\n", id);
                break;
            }
            case 4: {
                if (budgetCount >= MAX_BUDGETS) {
                    printf("Budget list is full.\n");
                    break;
                }
                float amt = readFloat("Enter budget amount: ");
                addBudget(amt, budgets, budgetCount);
                budgetCount++;                       /* caller increments */
                printf("Budget item %.2f added.\n", amt);
                break;
            }
            case 5:
                printf("Total budget: %.2f\n",
                       calculateBudget(budgets, budgetCount));
                break;
            case 6:
                employeeReport(employees, employeeCount);
                budgetReport(budgets, budgetCount);
                break;
            case 0:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
        if (choice != 0) {
            pauseScreen();
        }
    } while (choice != 0);

    return 0;
}

