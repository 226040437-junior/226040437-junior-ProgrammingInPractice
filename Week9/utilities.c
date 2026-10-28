#include <stdio.h>
#include <string.h>
#include "utilities.h"  


void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
     
    }
}


int readInt(const char *prompt) {
    int num = 0;
    printf("%s", prompt);
    while (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a whole number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return num;
}


double readDouble(const char *prompt) {
    double num = 0.0;
    printf("%s", prompt);
    while (scanf("%lf", &num) != 1) {
        printf("Invalid input. Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return num;
}


float readFloat(const char *prompt) {
    float num = 0.0f;
    printf("%s", prompt);
    while (scanf("%f", &num) != 1) {
        printf("Invalid input. Please enter a number: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return num;
}


void readString(const char *prompt, char *buffer, int size) {
    size_t len;
    printf("%s", prompt);
    
    if (fgets(buffer, size, stdin) != NULL) {
        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            clearInputBuffer();
        }
    }
}


void pauseScreen(void) {
    int c;
    printf("\nPress Enter to continue...");
    fflush(stdout);
    while ((c = getchar()) != '\n' && c != EOF) {
        
    }
}