#include <stdio.h>

//ADD an employee
void addEmployee(int* id, int* arr[], int length){
    arr[length]=id;
}
//List employee
void listEmployee(int employee[], int length){
    for(int i=0; i<length; i++){
        printf("Employee n: %d", employee[i]);

    }
}
//Search an Employee
int searchEmployee(int searchID, int emp[], int length){
    for(int i=0; i<length; i++){
        if(emp[i]==searchID){
        
               return i;
        }
          
    }
return -1;
}



