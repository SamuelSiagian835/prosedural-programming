

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repository.h"
#include "todo.h"

int getActivityCount() {
  return count;
}


void printActivity(const Activity* activityItem) {
    printf("%d|%s|%s|%s\n", activityItem->id, activityItem->waktu, activityItem->nama, activityItem->status);
}


void printAllActivities(const Activity* activities, int count) {
    for (int i = 0; i < count; i++) {
        printActivity(&activities[i]);
    }
}

void addActivity(Activity* activities, int* count, const char* waktu, const char* nama) {
    Activity newActivity;
    newActivity.id = *count + 1;
    strcpy(newActivity.waktu, waktu);
    strcpy(newActivity.nama, nama);
    strcpy(newActivity.status, "none");

    activities[*count] = newActivity;
    (*count)++;
}

void updateStatus(Activity* activities, int count, int id, Status status) {
    for (int i = 0; i < count; i++) {
        if (activities[i].id == id) {
            switch (status) {
                case NONE:
                    strcpy(activities[i].status, "none");
                    break;
                case DONE:
                    strcpy(activities[i].status, "done");
                    break;
                case CANCELED:
                    strcpy(activities[i].status, "canceled");
                    break;
            }
            return;
        }
    }
}

void saveActivities(const Activity* activities, int count, const char* filename) {
    FILE* file = openRepository(filename, "w");

    for (int i = 0; i < count; i++) {
        writeActivity(file, activities[i].id, activities[i].waktu, activities[i].nama, activities[i].status);
    }

    closeRepository(file);
}

void loadInitialData(Activity* activities, int* count, const char* filename) {
    FILE* file = openRepository(filename, "r");

    while (!feof(file)) {
        readActivity(file, &activities[*count].id, activities[*count].waktu, activities[*count].nama, activities[*count].status);
        (*count)++;
    }

    closeRepository(file);
}