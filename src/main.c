#include "../include/task.h"  // Task-related types and prototypes
#include <stdio.h>

#define MAX_TASKS 100

int main() {
    Task tasks[MAX_TASKS];   // Fixed-size array to store tasks
    int task_count = 0;
    int option = 0;          // User menu choice

    while (option != 9) {
        // Simple menu prompt
        puts("[1] Add Task");
        puts("[2] Delete Task");
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
