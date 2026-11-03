#include <stdio.h>
#include "suppliers.h"
#include "utilities.h"

void addSupplier(Supplier suppliers[], int *count, int capacity) {
    if (*count >= capacity) { printf("Supplier list is full.\n"); return; }
    Supplier s;
    s.id = readInt("Enter supplier ID: ");
    readString("Enter name: ", s.name, 40);
    readString("Enter email: ", s.email, 40);
    readString("Enter phone: ", s.phone, 15);
    readString("Enter town: ", s.town, 20);

    suppliers[*count] = s;
    (*count)++;
    printf("Supplier added.\n");
}

void displaySuppliers(Supplier suppliers[], int count) {
    if (count == 0) { printf("No suppliers to display.\n"); return; }
    printf("\n%-6s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email, 
               suppliers[i].phone, suppliers[i].town);
    }
}