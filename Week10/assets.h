#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS     100
#define ASSET_NAME_LEN 50

void addAsset(int id, const char *name, float value,
              int ids[], char names[][ASSET_NAME_LEN],
              float values[], int length);
void listAssets(int ids[], char names[][ASSET_NAME_LEN],
                float values[], int length);

int  saveAssetsText(int ids[], char names[][ASSET_NAME_LEN],
                    float values[], int length);
int  loadAssetsText(int ids[], char names[][ASSET_NAME_LEN],
                    float values[], int *length, int capacity);

#endif