#include <stdio.h>
#include "budget.h"

void addBudget(float amount, float budgets[], int length) {
    budgets[length] = amount;
}

float calculateBudget(float budgets[], int length) {
    float sum = 0.0f;
    /* FIXED: was i <= length (read one past the end) */
    for (int i = 0; i < length; i++) {
        sum += budgets[i];
    }
    return sum;
}

//

#define BUDGET_TEXT_FILE "data/budgets.txt"

int saveBudgetsText(float budgets[], int length) {
    FILE *fp = fopen(BUDGET_TEXT_FILE, "w");
    if (fp == NULL) { perror(BUDGET_TEXT_FILE); return 0; }
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%.2f\n", budgets[i]);
    }
    fclose(fp);
    printf("Saved %d budget item(s) to %s\n", length, BUDGET_TEXT_FILE);
    return 1;
}

int loadBudgetsText(float budgets[], int *length, int capacity) {
    FILE *fp = fopen(BUDGET_TEXT_FILE, "r");
    if (fp == NULL) { perror(BUDGET_TEXT_FILE); return 0; }
    int   loaded = 0;
    float v;
    while (loaded < capacity && fscanf(fp, "%f", &v) == 1) {
        budgets[loaded++] = v;
    }
    fclose(fp);
    *length = loaded;
    printf("Loaded %d budget item(s) from %s\n", loaded, BUDGET_TEXT_FILE);
    return 1;
}