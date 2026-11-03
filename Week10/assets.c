#include <stdio.h>
#include <string.h>
#include "assets.h"

#define ASSET_TEXT_FILE "data/assets.txt"

void addAsset(int id, const char *name, float value,
              int ids[], char names[][ASSET_NAME_LEN],
              float values[], int length) {
    ids[length]    = id;
    values[length] = value;
    strncpy(names[length], name, ASSET_NAME_LEN - 1);
    names[length][ASSET_NAME_LEN - 1] = '\0';
}

void listAssets(int ids[], char names[][ASSET_NAME_LEN],
                float values[], int length) {
    if (length == 0) { printf("No assets to list.\n"); return; }
    printf("\n%-6s %-25s %12s\n", "ID", "Name", "Value");
    printf("----------------------------------------------\n");
    for (int i = 0; i < length; i++) {
        printf("%-6d %-25s %12.2f\n", ids[i], names[i], values[i]);
    }
    printf("Total: %d asset(s).\n", length);
}

int saveAssetsText(int ids[], char names[][ASSET_NAME_LEN],
                   float values[], int length) {
    FILE *fp = fopen(ASSET_TEXT_FILE, "w");
    if (fp == NULL) { perror(ASSET_TEXT_FILE); return 0; }
    for (int i = 0; i < length; i++) {
        fprintf(fp, "%d|%s|%.2f\n", ids[i], names[i], values[i]);
    }
    fclose(fp);
    printf("Saved %d asset(s) to %s\n", length, ASSET_TEXT_FILE);
    return 1;
}

int loadAssetsText(int ids[], char names[][ASSET_NAME_LEN],
                   float values[], int *length, int capacity) {
    FILE *fp = fopen(ASSET_TEXT_FILE, "r");
    if (fp == NULL) { perror(ASSET_TEXT_FILE); return 0; }
    int  loaded = 0;
    char line[256];
    while (loaded < capacity && fgets(line, sizeof line, fp) != NULL) {
        int   id;
        char  name[ASSET_NAME_LEN];
        float value;
        if (sscanf(line, "%d|%49[^|\n]|%f", &id, name, &value) == 3) {
            ids[loaded]    = id;
            values[loaded] = value;
            strncpy(names[loaded], name, ASSET_NAME_LEN - 1);
            names[loaded][ASSET_NAME_LEN - 1] = '\0';
            loaded++;
        } else {
            printf("Skipping malformed line: %s", line);
        }
    }
    fclose(fp);
    *length = loaded;
    printf("Loaded %d asset(s) from %s\n", loaded, ASSET_TEXT_FILE);
    return 1;
}