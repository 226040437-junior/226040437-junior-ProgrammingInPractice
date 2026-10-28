#include <stdio.h>

//ADD  Budget
void addBudget(float amount, float budgets[], int length){
    budgets[length]=amount;

}
//Calculate budget

float calculateBudget(float budgets[], int length){
    float sum=0; 
    for (int i=0; i<=length; i++){
        sum+= budgets[i];
    }
    return sum;

}





//addEmployee(), 
//listEmployees(), 
//searchEmployee()