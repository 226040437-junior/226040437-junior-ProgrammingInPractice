#ifndef BUDGET_H
#define BUDGET_H


void  addBudget(float amount, float budgets[], int length);
float calculateBudget(float budgets[], int length);

int saveBudgetsText(float budgets[], int length);
int loadBudgetsText(float budgets[], int *length, int capacity);

#endif