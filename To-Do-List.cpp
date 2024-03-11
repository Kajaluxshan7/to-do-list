#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

// structure to represent each task
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// function
void displayMenu();
void addTask(std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void editTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    char choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // clear the input buffer

        switch (choice) {
            case '1':
                addTask(tasks);
                break;
            case '2':
                markTaskCompleted(tasks);
                break;
            case '3':
                editTask(tasks);
                break;
            case '4':
                deleteTask(tasks);
                break;
            case '5':
                viewTasks(tasks);
                break;
            case '6':
                std::cout << "Exiting the to-do list application. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != '6');

    return 0;
}

// menu options
void displayMenu() {
    std::cout << "\n===== To-Do List Application =====" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Mark Task as Completed" << std::endl;
    std::cout << "3. Edit Task" << std::endl;
    std::cout << "4. Delete Task" << std::endl;
    std::cout << "5. View Tasks" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

// add new task 
void addTask(std::vector<Task>& tasks) {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::getline(std::cin, taskDescription);

    tasks.push_back(Task(taskDescription));
    std::cout << "Task added successfully!" << std::endl;
}

// mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks); // current task list

    if (!tasks.empty()) {
        std::cout << "Enter the number of the task to mark as completed: ";
        int taskNumber;
        std::cin >> taskNumber;

        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task marked as completed!" << std::endl;
        } else {
            std::cout << "Invalid task number. Please try again." << std::endl;
        }
    } else {
        std::cout << "No tasks available to mark as completed." << std::endl;
    }
}

// edit or mark as incomplete
void editTask(std::vector<Task>& tasks) {
    viewTasks(tasks);

    if (!tasks.empty()) {
        do {
            std::cout << "Enter the number of the task to edit (or enter 0 to return to the main menu): ";
            int taskNumber;
            std::cin >> taskNumber;

            if (taskNumber == 0) {
                // return to the main menu
                return;
            }

            if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                std::cout << "Edit Options:" << std::endl;
                std::cout << "1. Edit Description" << std::endl;
                std::cout << "2. Mark as Incomplete" << std::endl;
                std::cout << "Enter your choice: ";

                int editChoice;
                std::cin >> editChoice;
                std::cin.ignore();

                switch (editChoice) {
                    case 1: {
                        std::cout << "Enter the new description: ";
                        std::string newDescription;
                        std::getline(std::cin, newDescription);
                        tasks[taskNumber - 1].description = newDescription;
                        std::cout << "Task description updated!" << std::endl;
                        break;
                    }
                    case 2:
                        tasks[taskNumber - 1].completed = false;
                        std::cout << "Task marked as incomplete!" << std::endl;
                        break;
                    default:
                        std::cout << "Invalid choice. No changes made." << std::endl;
                }
            } else {
                std::cout << "Invalid task number. Please try again." << std::endl;
            }
        } while (true); // continue until a valid option
    } else {
        std::cout << "No tasks available to edit." << std::endl;
    }
}

void deleteTask(std::vector<Task>& tasks) {
    viewTasks(tasks);

    if (!tasks.empty()) {
        do {
            std::cout << "Enter the number of the task to delete (or enter 0 to return to the main menu): ";
            int taskNumber;
            std::cin >> taskNumber;

            if (taskNumber == 0) {
                //return to the main menu
                return;
            }

            if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNumber - 1);
                std::cout << "Task deleted successfully!" << std::endl;
            } else {
                std::cout << "Invalid task number. Please try again." << std::endl;
            }
        } while (true);
    } else {
        std::cout << "No tasks available to delete." << std::endl;
    }
}

// view current tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    } else {
        std::cout << "\n===== Current Tasks =====" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << std::endl;
        }
    }
}
