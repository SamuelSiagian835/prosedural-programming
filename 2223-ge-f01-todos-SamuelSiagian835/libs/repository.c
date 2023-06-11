
#include <stdlib.h>
#include "repository.h"

FILE* openRepository(const char* filename, const char* mode) {
    return fopen(filename, mode);
}

void closeRepository(FILE* file) {
    fclose(file);
}

void writeActivity(FILE* file, int id, const char* waktu, const char* nama, const char* status) {
    fprintf(file, "%d|%s|%s|%s\n", id, waktu, nama, status);
}

void readActivity(FILE* file, int* id, char* waktu, char* nama, char* status) {
    fscanf(file, "%d|%[^|]|%[^|]|%[^\n]\n", id, waktu, nama, status);
}