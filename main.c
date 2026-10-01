#include <stdio.h>
#include <string.h>

#define N_SALARIES 50
#define N_BUDGETS  10
#define N_REGS     20
#define REG_LEN    20

//EMPLOYEE SALARIES


void captureSalaries(float salaries[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
}

//
void displaySalaries(const float salaries[], int n)
{
    printf("\n--- Employee Salaries ---\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %2d: %.2f\n", i + 1, salaries[i]);
    }
}

//Total salary expenditure 
float totalSalaries(const float salaries[], int n)
{
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total;
}

//Average salary 
float averageSalaries(const float salaries[], int n)
{
    return totalSalaries(salaries, n) / n;
}

//Highest salary (start from element 0 - never assume 0) 
float highestSalary(const float salaries[], int n)
{
    float highest = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
    }
    return highest;
}

//Lowest salary 
float lowestSalary(const float salaries[], int n)
{
    float lowest = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    return lowest;
}

//Linear search: returns index of first match, or -1 if not found 
int searchSalary(const float salaries[], int n, float target)
{
    for (int i = 0; i < n; i++) {
        if (salaries[i] == target) {
            return i;             
        }
    }
    return -1;                    
}

/* =============================================================
                     DEPARTMENT BUDGETS
   ============================================================= */

void captureBudgets(float budgets[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
}

void displayBudgets(const float budgets[], int n)
{
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < n; i++) {
        printf("Department %2d: %.2f\n", i + 1, budgets[i]);
    }
}

float totalBudgets(const float budgets[], int n)
{
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += budgets[i];
    }
    return total;
}

float averageBudgets(const float budgets[], int n)
{
    return totalBudgets(budgets, n) / n;
}

//Bubble sort: lowest to highest (ascending) 
void sortBudgetsAscending(float budgets[], int n)
{
    float temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {

                /* the three fundamental swap statements */
                temp             = budgets[j];
                budgets[j]       = budgets[j + 1];
                budgets[j + 1]   = temp;
            }
        }
    }
}

/* =============================================================
                VEHICLE REGISTRATION NUMBERS
   ============================================================= */

void captureRegistrations(char regs[][REG_LEN], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", regs[i]);        /* %19s prevents overflow */
    }
}

void displayRegistrations(char regs[][REG_LEN], int n)
{
    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < n; i++) {
        printf("%2d. %s\n", i + 1, regs[i]);
    }
}

//Search using strcmp() because registrations are strings 
int searchRegistration(char regs[][REG_LEN], int n, const char *target)
{
    for (int i = 0; i < n; i++) {
        if (strcmp(regs[i], target) == 0) {
            return i;                  /* found */
        }
    }
    return -1;                         /* not found */
}

/* =============================================================
                     MAIN : MENU
   ============================================================= */

int main(void)
{
    float salaries[N_SALARIES];
    float budgets[N_BUDGETS];
    char  registrations[N_REGS][REG_LEN];

    int salariesCaptured = 0;
    int budgetsCaptured  = 0;
    int regsCaptured     = 0;

    int   choice;
    float target;
    char  targetReg[REG_LEN];
    int   position;

    do {
        printf("\n========== MUNICIPAL INFORMATION MANAGEMENT SYSTEM ==========\n");
        printf(" A. EMPLOYEE SALARIES\n");
        printf("   1. Capture %d employee salaries\n", N_SALARIES);
        printf("   2. Display all salaries\n");
        printf("   3. Salary statistics (total, average, highest, lowest)\n");
        printf("   4. Search for a salary\n");
        printf(" B. DEPARTMENT BUDGETS\n");
        printf("   5. Capture %d department budgets\n", N_BUDGETS);
        printf("   6. Display budgets\n");
        printf("   7. Budget statistics (total, average)\n");
        printf("   8. Sort budgets (lowest to highest)\n");
        printf(" C. VEHICLE REGISTRATIONS\n");
        printf("   9. Capture %d registration numbers\n", N_REGS);
        printf("  10. Display all registrations\n");
        printf("  11. Search for a registration\n");
        printf("   0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

       
        case 1:
            captureSalaries(salaries, N_SALARIES);
            salariesCaptured = 1;
            printf("All %d salaries captured successfully.\n", N_SALARIES);
            break;

        case 2:
            if (salariesCaptured)
                displaySalaries(salaries, N_SALARIES);
            else
                printf("No salaries captured yet. Choose option 1 first.\n");
            break;

        case 3:
            if (salariesCaptured) {
                printf("\n--- Salary Report ---\n");
                printf("Total salary expenditure: %.2f\n",
                       totalSalaries(salaries, N_SALARIES));
                printf("Average salary        : %.2f\n",
                       averageSalaries(salaries, N_SALARIES));
                printf("Highest salary        : %.2f\n",
                       highestSalary(salaries, N_SALARIES));
                printf("Lowest salary         : %.2f\n",
                       lowestSalary(salaries, N_SALARIES));
            } else {
                printf("No salaries captured yet. Choose option 1 first.\n");
            }
            break;

        case 4:
            if (salariesCaptured) {
                printf("Enter the salary to search for: ");
                scanf("%f", &target);

                position = searchSalary(salaries, N_SALARIES, target);

                if (position != -1)
                    printf("Salary %.2f found at employee %d (index %d).\n",
                           target, position + 1, position);
                else
                    printf("Salary %.2f was not found.\n", target);
            } else {
                printf("No salaries captured yet. Choose option 1 first.\n");
            }
            break;

      
        case 5:
            captureBudgets(budgets, N_BUDGETS);
            budgetsCaptured = 1;
            printf("All %d budgets captured successfully.\n", N_BUDGETS);
            break;

        case 6:
            if (budgetsCaptured)
                displayBudgets(budgets, N_BUDGETS);
            else
                printf("No budgets captured yet. Choose option 5 first.\n");
            break;

        case 7:
            if (budgetsCaptured) {
                printf("\n--- Budget Report ---\n");
                printf("Total municipal budget  : %.2f\n",
                       totalBudgets(budgets, N_BUDGETS));
                printf("Average department budget: %.2f\n",
                       averageBudgets(budgets, N_BUDGETS));
            } else {
                printf("No budgets captured yet. Choose option 5 first.\n");
            }
            break;

        case 8:
            if (budgetsCaptured) {
                sortBudgetsAscending(budgets, N_BUDGETS);
                printf("Budgets sorted from lowest to highest.\n");
                displayBudgets(budgets, N_BUDGETS);
            } else {
                printf("No budgets captured yet. Choose option 5 first.\n");
            }
            break;

      
        case 9:
            captureRegistrations(registrations, N_REGS);
            regsCaptured = 1;
            printf("All %d registrations captured successfully.\n", N_REGS);
            break;

        case 10:
            if (regsCaptured)
                displayRegistrations(registrations, N_REGS);
            else
                printf("No registrations captured yet. Choose option 9 first.\n");
            break;

        case 11:
            if (regsCaptured) {
                printf("Enter the registration to search for: ");
                scanf("%19s", targetReg);

                position = searchRegistration(registrations, N_REGS, targetReg);

                if (position != -1)
                    printf("Registration %s found at position %d.\n",
                           targetReg, position + 1);
                else
                    printf("Registration %s was not found.\n", targetReg);
            } else {
                printf("No registrations captured yet. Choose option 9 first.\n");
            }
            break;

        case 0:
            printf("Exiting the Municipal Information Management System. Goodbye.\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 0 and 11.\n");
        }

    } while (choice != 0);

    return 0;
}