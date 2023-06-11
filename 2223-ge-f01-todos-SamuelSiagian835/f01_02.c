// 12S21035 - Silviana Siagian
// 12S21042 - Samuel Siagian

#include <stdio.h>
#include <string.h>
#include "./libs/todo.h"
#include "./libs/repository.h"

int main() {
    loadInitialData();

    char command[100];
    while (1) {
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "todo-print-all") == 0) {
            printAllActivities();
        } else if (strstr(command, "todo-add") != NULL) {
            char time[6];
            char name[100];
            sscanf(command, "todo-add#%[^#]#%[^\n]", time, name);
            Activity activity;
            activity.id = getActivityCount() + 1; // Menggunakan fungsi getActivityCount()
            strcpy(activity.time, time);
            strcpy(activity.name, name);
            strcpy(activity.status, "none");
            addActivity(activity);
            saveActivity(activity);
        } else if (strcmp(command, "---") == 0) {
            break;
        }
    }

    return 0;
}
