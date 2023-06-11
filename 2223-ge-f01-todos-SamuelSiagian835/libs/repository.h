#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <stdio.h>

FILE* openRepository(const char* filename, const char* mode);
void closeRepository(FILE* file);
void writeActivity(FILE* file, int id, const char* waktu, const char* nama, const char* status);
void readActivity(FILE* file, int* id, char* waktu, char* nama, char* status);

#endif