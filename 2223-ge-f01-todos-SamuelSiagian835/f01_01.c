
#include <stdio.h>
#include "./libs/repository.h"
#include "./libs/todo.h"

int main() {
    Activity activities[100];
    int count = 0;

    loadInitialData(activities, &count, "./storage/todo-repository.txt");
    printAllActivities(activities, count);

    return 0;
}