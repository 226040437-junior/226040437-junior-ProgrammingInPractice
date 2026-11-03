#include <stdio.h>
#include "main.h"
#include "records.h"
#include "employee.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"
#include "utilities.h"

void displayMainMenu(void) {
    printf("\n===== MFMS Main Menu =====\n");
    printf("--- Employees ---\n");
    printf(" 1. Add Employee\n");
    printf(" 2. Display Employees\n");
    printf("--- Suppliers ---\n");
    printf(" 3. Add Supplier\n");
    printf(" 4. Display Suppliers\n");
    printf("--- Assets ---\n");
    printf(" 5. Add Asset\n");
    printf(" 6. Display Assets\n");
    printf("--- Budgets ---\n");
    printf(" 7. Add Budget\n");
    printf(" 8. Display Budgets\n");
    printf("--- Projects ---\n");
    printf(" 9. Add Project\n");
    printf("10. Display Projects\n");
    printf("--- Persistence ---\n");
    printf("11. Save Employees (Binary)\n");
    printf("12. Load Employees (Binary)\n");
    printf(" 0. Exit\n");
}

int main(void) {
    Employee employees[MAX_RECORDS]; int employeeCount = 0;
    Supplier suppliers[MAX_RECORDS]; int supplierCount = 0;
    Asset    assets[MAX_RECORDS];    int assetCount    = 0;
    Budget   budgets[MAX_RECORDS];   int budgetCount   = 0;
    Project  projects[MAX_RECORDS];  int projectCount  = 0;
    int choice;

    ensureDataDirectory();

    do {
        displayMainMenu();
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:  addEmployee(employees, &employeeCount, MAX_RECORDS); break;
            case 2:  displayEmployees(employees, employeeCount); break;
            case 3:  addSupplier(suppliers, &supplierCount, MAX_RECORDS); break;
            case 4:  displaySuppliers(suppliers, supplierCount); break;
            case 5:  addAsset(assets, &assetCount, MAX_RECORDS); break;
            case 6:  displayAssets(assets, assetCount); break;
            case 7:  addBudget(budgets, &budgetCount, MAX_RECORDS); break;
            case 8:  displayBudgets(budgets, budgetCount); break;
            case 9:  addProject(projects, &projectCount, MAX_RECORDS); break;
            case 10: displayProjects(projects, projectCount); break;
            case 11: saveEmployeesBinary(employees, employeeCount); break;
            case 12: loadEmployeesBinary(employees, &employeeCount, MAX_RECORDS); break;
            case 0:  printf("Goodbye.\n"); break;
            default: printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);

    return 0;
}