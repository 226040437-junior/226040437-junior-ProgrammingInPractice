#include <stdio.h>
#include "assets.h"
#include "utilities.h"

void addAsset(Asset assets[], int *count, int capacity) {
    if (*count >= capacity) { printf("Asset list is full.\n"); return; }
    Asset a;
    a.id = readInt("Enter asset ID: ");
    readString("Enter description: ", a.description, 40);
    a.value = readDouble("Enter value: ");
    
    printf("Enter acquired date:\n");
    a.acquired.day = readInt("  Day (1-31): ");
    a.acquired.month = readInt("  Month (1-12): ");
    a.acquired.year = readInt("  Year: ");

    assets[*count] = a;
    (*count)++;
    printf("Asset added.\n");
}

void displayAssets(Asset assets[], int count) {
    if (count == 0) { printf("No assets to display.\n"); return; }
    printf("\n%-6s %-25s %12s %-15s\n", "ID", "Description", "Value", "Acquired");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-6d %-25s %12.2f %02d/%02d/%04d\n",
               assets[i].id, assets[i].description, assets[i].value,
               assets[i].acquired.day, assets[i].acquired.month, assets[i].acquired.year);
    }
}