#include <stdio.h>
#include <string.h>
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
    printf(" 3. Update Employee Salary (Pointer)\n");
    printf("--- Suppliers ---\n");
    printf(" 4. Add Supplier\n");
    printf(" 5. Display Suppliers\n");
    printf("--- Assets ---\n");
    printf(" 6. Add Asset\n");
    printf(" 7. Display Assets\n");
    printf("--- Budgets ---\n");
    printf(" 8. Add Budget\n");
    printf(" 9. Display Budgets\n");
    printf("10. Increase Budget (Pointer)\n");
    printf("--- Projects ---\n");
    printf("11. Add Project\n");
    printf("12. Display Projects\n");
    printf("--- Persistence ---\n");
    printf("13. Save Employees (Binary)\n");
    printf("14. Load Employees (Binary)\n");
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
            case 3: {
                int id = readInt("Enter employee ID to update: ");
                Employee *emp = findEmployee(employees, employeeCount, id);
                if (emp != NULL) {
                    double newSal = readDouble("Enter new salary: ");
                    updateSalary(emp, newSal);
                    printf("Success! %s now earns %.2f\n", emp->name, emp->salary);
                } else {
                    printf("Error: Employee with ID %d not found.\n", id);
                }
                break;
            }
            case 4:  addSupplier(suppliers, &supplierCount, MAX_RECORDS); break;
            case 5:  displaySuppliers(suppliers, supplierCount); break;
            case 6:  addAsset(assets, &assetCount, MAX_RECORDS); break;
            case 7:  displayAssets(assets, assetCount); break;
            case 8:  addBudget(budgets, &budgetCount, MAX_RECORDS); break;
            case 9:  displayBudgets(budgets, budgetCount); break;
            case 10: {
              
                char dept[20];
                readString("Enter department to increase budget: ", dept, 20);
                int foundIdx = -1;
                for (int i = 0; i < budgetCount; i++) {
                    if (strcmp(budgets[i].department, dept) == 0) {
                        foundIdx = i;
                        break;
                    }
                }
                if (foundIdx != -1) {
                    double amount = readDouble("Enter amount to add: ");
                    increaseBudget(&budgets[foundIdx], amount);
                } else {
                    printf("Department not found.\n");
                }
                break;
            }
            case 11: addProject(projects, &projectCount, MAX_RECORDS); break;
            case 12: displayProjects(projects, projectCount); break;
            case 13: saveEmployeesBinary(employees, employeeCount); break;
            case 14: loadEmployeesBinary(employees, &employeeCount, MAX_RECORDS); break;
            case 0:  printf("Goodbye.\n"); break;
            default: printf("Invalid option.\n");
        }
        if (choice != 0) pauseScreen();
    } while (choice != 0);

    return 0;
}