

#ifndef TODO_H
#define TODO_H

typedef enum {
    NONE,
    DONE,
    CANCELED
} Status;

typedef struct {
    int id;
    char waktu[6];
    char nama[100];
    char status[10];
} Activity;

int getActivityCount();
void printActivity(const Activity* activity);
void printAllActivities(const Activity* activities, int count);
void addActivity(Activity* activities, int* count, const char* waktu, const char* nama);
void updateStatus(Activity* activities, int count, int id, Status status);
void saveActivities(const Activity* activities, int count, const char* filename);
void loadInitialData(Activity* activities, int* count, const char* filename);

#endif