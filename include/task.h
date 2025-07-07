// Maximum length for task description
#define MAX_LENGTH 256

// Maximum length for task title
#define TITLE_LENGTH 64

// Status enumeration for task progress
typedef enum {
  TODO,
  IN_PROGRESS,
  DONE
} STATUS;

// Task structure representing a single task item
typedef struct {
  int id;
  char title[TITLE_LENGTH];
  char description[MAX_LENGTH];
  STATUS status;
} Task;

// Function prototypes for task management

/**
 * @param tasks Pointer to the array of tasks.
 * @param task_count Pointer to the current number of tasks; will be incremented on success.
 */
void add_task(Task *tasks, int *task_count);

/**
 * @param task_count Pointer to the current number of tasks; will be decremented on success.
 */
void remove_task(Task *tasks, int *task_count);

/**
 * @param task_count Pointer to the current number of tasks.
 */
void list_task(Task *tasks, int *task_count);

/**
 * Displays detailed information of tasks.
 */
void task_show(Task *tasks, int *task_count);

/**
 * Updates the status of a task identified by its id.
 * @param tasks Pointer to the array of tasks.
 * @param id Identifier of the task to update.
 * @param new_status The new status to assign.
 */
void update_status(Task *tasks, int id, STATUS new_status);

/**
 * Clears the input buffer to avoid leftover input issues.
 */
void clear_input_buffer();
