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