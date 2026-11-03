#include <stdio.h>
#include <string.h>
#include "suppliers.h"

#define SUP_TEXT_FILE "data/suppliers.txt"

void addSupplier(int id, const char *name,
                 int ids[], char names[][SUP_NAME_LEN], int length) {
    ids[length] = id;
    strncpy(names[length], name, SUP_NAME_LEN - 1);
    names[length][SUP_NAME_LEN - 1] = '\0';
}

void listSuppliers(int ids[], char names[][SUP_NAME_LEN], int length) {
    if (length == 0) { printf("No suppliers to list.\n"); return; }
    printf("\n%-6s %-25s\n", "ID", "Name");
    printf("-----------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%-6d %-25s\n", ids[i], names[i]);
    }
    printf("Total: %d supplier(s).\n", length);
}

int saveSuppliersText(int ids[], char names[][SUP_NAME_LEN], int length) {
    FILE *fp = fopen(SUP_TEXT_FILE, "w");
    if (fp == NULL) { perror(SUP_TEXT_FILE); return 0; }
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%d|%s\n", ids[i], names[i]);
    }
    fclose(fp);
    printf("Saved %d supplier(s) to %s\n", length, SUP_TEXT_FILE);
    return 1;
}


int loadSuppliersText(int ids[], char names[][SUP_NAME_LEN],
                      int *length, int capacity) {
    FILE *fp = fopen(SUP_TEXT_FILE, "r");
    if (fp == NULL) { perror(SUP_TEXT_FILE); return 0; }
    int  loaded = 0;
    char line[256];
    while (loaded < capacity && fgets(line, sizeof line, fp) != NULL) {
        int  id;
        char name[SUP_NAME_LEN];
        if (sscanf(line, "%d|%49[^|\n]", &id, name) == 2) {
            ids[loaded] = id;
            strncpy(names[loaded], name, SUP_NAME_LEN - 1);
            names[loaded][SUP_NAME_LEN - 1] = '\0';
            loaded++;
        } else {
            printf("Skipping malformed line: %s", line);
        }
    }
    fclose(fp);
    *length = loaded;
    printf("Loaded %d supplier(s) from %s\n", loaded, SUP_TEXT_FILE);
    return 1;
}