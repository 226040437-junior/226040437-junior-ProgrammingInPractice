#include <stdio.h>
#include "main.h"
#include "employee.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
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
    printf(" 6. Add supplier\n");
    printf(" 7. List suppliers\n");
    printf(" 8. Add asset\n");
    printf(" 9. List assets\n");
    printf("10. Show reports\n");
    printf("11. Save data (text)\n");
    printf("12. Load data (text)\n");
    printf("13. Save employees (binary)\n");
    printf("14. Load employees (binary)\n");
    printf(" 0. Exit\n");
}

int main(void) {
    int   employees[MAX_EMPLOYEES];         int employeeCount = 0;
    float budgets[MAX_BUDGETS];             int budgetCount   = 0;
    int   supplierIds[MAX_SUPPLIERS];
    char  supplierNames[MAX_SUPPLIERS][SUP_NAME_LEN];
    int   supplierCount = 0;
    int   assetIds[MAX_ASSETS];
    char  assetNames[MAX_ASSETS][ASSET_NAME_LEN];
    float assetValues[MAX_ASSETS];
    int   assetCount = 0;
    int   choice;

    ensureDataDirectory();

    do {
        displayMainMenu();
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1: {
                if (employeeCount >= MAX_EMPLOYEES) {
                    printf("Employee list is full.\n"); break;
                }
                int id = readInt("Enter employee ID: ");
                addEmployee(id, employees, employeeCount);
                employeeCount++;
                printf("Employee %d added.\n", id);
                break;
            }
            case 2:
                listEmployee(employees, employeeCount);
                break;
            case 3: {
                int id  = readInt("Enter employee ID to search: ");
                int idx = searchEmployee(id, employees, employeeCount);
                if (idx >= 0) printf("Employee %d found at position %d.\n", id, idx);
                else          printf("Employee %d not found.\n", id);
                break;
            }
            case 4: {
                if (budgetCount >= MAX_BUDGETS) {
                    printf("Budget list is full.\n"); break;
                }
                float amt = readFloat("Enter budget amount: ");
                addBudget(amt, budgets, budgetCount);
                budgetCount++;
                printf("Budget item %.2f added.\n", amt);
                break;
            }
            case 5:
                printf("Total budget: %.2f\n",
                       calculateBudget(budgets, budgetCount));
                break;
            case 6: {
                if (supplierCount >= MAX_SUPPLIERS) {
                    printf("Supplier list is full.\n"); break;
                }
                int id = readInt("Enter supplier ID: ");
                char name[SUP_NAME_LEN];
                readString("Enter supplier name: ", name, SUP_NAME_LEN);
                addSupplier(id, name, supplierIds, supplierNames, supplierCount);
                supplierCount++;
                printf("Supplier %d added.\n", id);
                break;
            }
            case 7:
                listSuppliers(supplierIds, supplierNames, supplierCount);
                break;
            case 8: {
                if (assetCount >= MAX_ASSETS) {
                    printf("Asset list is full.\n"); break;
                }
                int id = readInt("Enter asset ID: ");
                char name[ASSET_NAME_LEN];
                readString("Enter asset name: ", name, ASSET_NAME_LEN);
                float value = readFloat("Enter asset value: ");
                addAsset(id, name, value,
                         assetIds, assetNames, assetValues, assetCount);
                assetCount++;
                printf("Asset %d added.\n", id);
                break;
            }
            case 9:
                listAssets(assetIds, assetNames, assetValues, assetCount);
                break;
            case 10:
                employeeReport(employees, employeeCount);
                budgetReport(budgets, budgetCount);
                break;
            case 11:
                printf("\n--- Saving all data (text) ---\n");
                saveEmployeesText(employees, employeeCount);
                saveBudgetsText(budgets, budgetCount);
                saveSuppliersText(supplierIds, supplierNames, supplierCount);
                saveAssetsText(assetIds, assetNames, assetValues, assetCount);
                break;
            case 12:
                printf("\n--- Loading all data (text) ---\n");
                loadEmployeesText(employees, &employeeCount, MAX_EMPLOYEES);
                loadBudgetsText(budgets, &budgetCount, MAX_BUDGETS);
                loadSuppliersText(supplierIds, supplierNames,
                                  &supplierCount, MAX_SUPPLIERS);
                loadAssetsText(assetIds, assetNames, assetValues,
                               &assetCount, MAX_ASSETS);
                break;
            case 13:
                saveEmployeesBinary(employees, employeeCount);
                break;
            case 14:
                loadEmployeesBinary(employees, &employeeCount, MAX_EMPLOYEES);
                break;
            case 0:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);

    return 0;
}