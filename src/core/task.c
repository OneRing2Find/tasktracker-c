#include "../../include/task.h"
#include <stdio.h>
#include <string.h>

#define TITLE_LENGTH 64
#define MAX_LENGTH 256

// Clears the input buffer to avoid leftover characters interfering with subsequent input
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Adds a new task to the tasks array, updating the task count accordingly
void add_task(Task *tasks, int *task_count) {
    char title[TITLE_LENGTH] = "";
    char description[MAX_LENGTH] = "";
    int choice;

    while (1) {
        puts("===========================");
        puts("         ADD TASK          ");
        puts("===========================");

        // Prompt user for the task title and read input safely
        printf("%s", "Insert the title: ");
        fgets(title, TITLE_LENGTH, stdin);
        title[strcspn(title, "\n")] = 0;

        puts("");

        // Prompt user for the task description and read input safely
        printf("%s", "Insert the description: ");
        fgets(description, MAX_LENGTH, stdin);
        description[strcspn(description, "\n")] = 0; // Remove trailing newline character

        puts("[1] save [2] return");
        printf("Choose an option: ");

        // Read user choice; validate input
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            puts("Invalid input, try again.");
            continue;
        }

        clear_input_buffer();

        if (choice == 1) {
            // Populate the next available task slot
            tasks[*task_count].id = *task_count + 1;
            strncpy(tasks[*task_count].title, title, TITLE_LENGTH);
            tasks[*task_count].title[TITLE_LENGTH - 1] = '\0';
            strncpy(tasks[*task_count].description, description, MAX_LENGTH);
            tasks[*task_count].description[MAX_LENGTH - 1] = '\0';
            tasks[*task_count].status = TODO;

            // Increment the task count after successful
            (*task_count)++;
            puts("Saved");
            break;
        } else {
            puts("Returning...");
            break;
        }
    }
}

// Displays the most recently added task's details
void task_show(Task *tasks, int *task_count) {
    if (*task_count > 0) {
        puts("Task added:");
        printf("ID: %d\n", tasks[*task_count - 1].id);
        printf("Title: %s\n", tasks[*task_count - 1].title);
        printf("Description: %s\n", tasks[*task_count - 1].description);
        printf("Status: %d\n", tasks[*task_count - 1].status);
        puts("");
    } else {
        puts("No task was added.");
    }
}
