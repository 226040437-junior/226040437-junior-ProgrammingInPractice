#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define SUP_NAME_LEN  50


void addSupplier(int id, const char *name,
                 int ids[], char names[][SUP_NAME_LEN], int length);
void listSuppliers(int ids[], char names[][SUP_NAME_LEN], int length);

int  saveSuppliersText(int ids[], char names[][SUP_NAME_LEN], int length);
int  loadSuppliersText(int ids[], char names[][SUP_NAME_LEN],
                       int *length, int capacity);

#endif