#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define NAME_LEN 100
#define EMAIL_LEN 100
#define PHONE_LEN 30
#define TOWN_LEN 50

// ---------- Function Prototypes ----------
void displayWelcome();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void displayMenu();

// Supplier Management functions (from Week 7)
void addSupplier();
void displaySuppliers();
void searchSupplier();

// ---------- Global Supplier Data ----------
char supplierNames[MAX_SUPPLIERS][NAME_LEN];
char supplierEmails[MAX_SUPPLIERS][EMAIL_LEN];
char supplierPhones[MAX_SUPPLIERS][PHONE_LEN];
char supplierTowns[MAX_SUPPLIERS][TOWN_LEN];
int supplierCount = 0;

// Helper to remove trailing newline from fgets
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// ---------- Main Function ----------
int main() {
    displayWelcome();

    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int empSize = sizeof(employeeIDs) / sizeof(employeeIDs[0]);

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // consume newline left by scanf

        switch (choice) {
            case 1: {  // Calculate VAT
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                getchar();
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            }
            case 2: {  // Calculate Salary
                float basic, housing, transport;
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                getchar();
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 3: {  // Calculate Budget
                float revenue, expenses;
                printf("Revenue: ");
                scanf("%f", &revenue);
                printf("Expenses: ");
                scanf("%f", &expenses);
                getchar();
                float balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0)
                    printf("SURPLUS\n");
                else if (balance < 0)
                    printf("DEFICIT\n");
                else
                    printf("BALANCED\n");
                break;
            }
            case 4: {  // Search Employee
                int id;
                printf("Enter employee ID: ");
                scanf("%d", &id);
                getchar();
                int pos = searchEmployee(id, employeeIDs, empSize);
                if (pos != -1)
                    printf("Employee found at position %d.\n", pos);
                else
                    printf("Employee not found.\n");
                break;
            }
            case 5: {  // Supplier Management submenu
                int subChoice;
                do {
                    printf("\n--- Supplier Management ---\n");
                    printf("1. Add Supplier\n");
                    printf("2. Display Suppliers\n");
                    printf("3. Search Supplier\n");
                    printf("4. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);
                    getchar();
                    switch (subChoice) {
                        case 1: addSupplier(); break;
                        case 2: displaySuppliers(); break;
                        case 3: searchSupplier(); break;
                        case 4: printf("Returning to main menu.\n"); break;
                        default: printf("Invalid choice.\n");
                    }
                } while (subChoice != 4);
                break;
            }
            case 6:  // Exit
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ---------- Function Definitions ----------

// LAB TASK 1: Basic Function
void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}

// LAB TASK 2: calculateVAT()
float calculateVAT(float amount) {
    return amount * 0.15;   // VAT at 15%
}

// LAB TASK 3: calculateSalary()
float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

// LAB TASK 4: calculateBudget()
float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

// LAB TASK 6: searchEmployee()
int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;   // return position (0-based index)
        }
    }
    return -1;          // not found
}

// LAB TASK 5: displayMenu()
void displayMenu() {
    printf("\n===== MUNICIPAL FINANCIAL MANAGEMENT =====\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

// ---------- Supplier Management Functions (from Week 7) ----------
void addSupplier() {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Maximum number of suppliers reached.\n");
        return;
    }

    char tempName[NAME_LEN];
    char tempEmail[EMAIL_LEN];
    char tempPhone[PHONE_LEN];
    char tempTown[TOWN_LEN];

    printf("\n--- Add New Supplier ---\n");
    printf("Enter supplier name: ");
    fgets(tempName, sizeof(tempName), stdin);
    removeNewline(tempName);

    printf("Enter email: ");
    fgets(tempEmail, sizeof(tempEmail), stdin);
    removeNewline(tempEmail);

    printf("Enter phone: ");
    fgets(tempPhone, sizeof(tempPhone), stdin);
    removeNewline(tempPhone);

    printf("Enter town: ");
    fgets(tempTown, sizeof(tempTown), stdin);
    removeNewline(tempTown);

    strcpy(supplierNames[supplierCount], tempName);
    strcpy(supplierEmails[supplierCount], tempEmail);
    strcpy(supplierPhones[supplierCount], tempPhone);
    strcpy(supplierTowns[supplierCount], tempTown);

    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers() {
    if (supplierCount == 0) {
        printf("\nNo suppliers to display.\n");
        return;
    }

    printf("\n--- Supplier Details ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d:\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}

void searchSupplier() {
    if (supplierCount == 0) {
        printf("\nNo suppliers to search.\n");
        return;
    }

    char searchName[NAME_LEN];
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    removeNewline(searchName);

    int found = 0;
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], searchName) == 0) {
            printf("Supplier found!\n");
            printf("Name : %s\n", supplierNames[i]);
            printf("Email: %s\n", supplierEmails[i]);
            printf("Phone: %s\n", supplierPhones[i]);
            printf("Town : %s\n", supplierTowns[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Supplier not found.\n");
    }
}