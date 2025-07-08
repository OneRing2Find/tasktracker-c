#include "../include/task.h"  // Task-related types and prototypes
#include <stdio.h>

#define MAX_TASKS 100

int main() {
    Task tasks[MAX_TASKS];   // Fixed-size array to store tasks
    int task_count = 0;
    int option = 0;         // User menu choice

    while (option != 9) {
        // Simple menu prompt
        puts("");
        puts("[1] Add Task");
        puts("[2] Delete Task");
        puts("[3] Show Tasks");
        puts("[9] Exit");
        printf("Choose an option: ");
        scanf("%1d", &option);
        clear_input_buffer();

        switch (option) {
            case 1:
                add_task(tasks, &task_count);
                task_show(tasks, &task_count);
                break;
            case 2:
                break;
            case 3:
                if (task_count > 0) {
                    puts("Tasks: ");
                    for (int i = 0; i < task_count; i++) {
                        printf("[%d] %s\n", i, tasks[i].title);
                    }
                } else {
                    puts ("There is no task");
                    break;
                }

                puts("Choose a task to see details: ");
                scanf("%d", &option);
                clear_input_buffer();

                if (option >= 0 && option < task_count) {
                    puts("Task details:");
                    printf("ID: %d\n", tasks[option].id);
                    printf("Title: %s\n", tasks[option].title);
                    printf("Description: %s\n", tasks[option].description);
                    printf("Status: %d\n", tasks[option].status);
                    puts("");
                } else {
                    puts("Invalid ID. Try again.");
                }
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                puts("Invalid input, please try again");
                break;
        }
    }
    return 0;
}
