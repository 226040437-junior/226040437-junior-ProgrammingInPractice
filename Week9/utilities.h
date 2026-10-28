#ifndef UTILITIES_H
#define UTILITIES_H

void clearInputBuffer(void);
int readInt(const char *prompt);
double readDouble(const char *prompt);
float readFloat(const char *prompt);
void readString(const char *prompt, char *buffer, int size);
void pauseScreen(void);

#endif