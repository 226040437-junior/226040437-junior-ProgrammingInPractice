#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5
#define NAME_LEN 100
#define EMAIL_LEN 100
#define PHONE_LEN 30
#define TOWN_LEN 50

// Global arrays to store supplier data
char supplierNames[MAX_SUPPLIERS][NAME_LEN];
char supplierEmails[MAX_SUPPLIERS][EMAIL_LEN];
char supplierPhones[MAX_SUPPLIERS][PHONE_LEN];
char supplierTowns[MAX_SUPPLIERS][TOWN_LEN];
int supplierCount = 0;

// Helper function to remove trailing newline from fgets input
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Add a supplier 
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

    // Copy into global arrays 
    strcpy(supplierNames[supplierCount], tempName);
    strcpy(supplierEmails[supplierCount], tempEmail);
    strcpy(supplierPhones[supplierCount], tempPhone);
    strcpy(supplierTowns[supplierCount], tempTown);

    // Construct a description using strcat
    char description[300] = "";
    strcat(description, tempName);
    strcat(description, " operates in ");
    strcat(description, tempTown);
    strcat(description, ".");
    printf("\nDescription: %s\n", description);

    supplierCount++;
    printf("Supplier added successfully.\n");
}

// Display all suppliers and show string lengths
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
        // LAB TASK 2: Display length of name, email, town
        printf("Name length : %zu\n", strlen(supplierNames[i]));
        printf("Email length: %zu\n", strlen(supplierEmails[i]));
        printf("Town length : %zu\n", strlen(supplierTowns[i]));
    }
}

// Search for a supplier by name using strcmp
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

// Show name length of all suppliers (or a specific one)
void showNameLength() {
    if (supplierCount == 0) {
        printf("\nNo suppliers available.\n");
        return;
    }
    printf("\n--- Supplier Name Lengths ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%s : %zu characters\n", supplierNames[i], strlen(supplierNames[i]));
    }
}

// Demonstrate copying supplier information
void copySupplierDemo() {
    if (supplierCount == 0) {
        printf("\nNo supplier to copy. Add a supplier first.\n");
        return;
    }
    char backup[NAME_LEN];
    // Copy the first supplier's name into backup
    strcpy(backup, supplierNames[0]);
    printf("\nOriginal name: %s\n", supplierNames[0]);
    printf("Backup name  : %s\n", backup);
}

// Menu function
void displayMenu() {
    printf("\n===== MUNICIPAL FINANCIAL MANAGEMENT =====\n");
    printf("1. Add Supplier\n");
    printf("2. Display Suppliers\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Length\n");
    printf("5. Copy Supplier Demo\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                showNameLength();
                break;
            case 5:
                copySupplierDemo();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}