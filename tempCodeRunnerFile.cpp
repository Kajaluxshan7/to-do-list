void editTask(std::vector<Task>& tasks) {
    viewTasks(tasks);

    if (!tasks.empty()) {
        std::cout << "Enter the number of the task to edit: ";
        int taskNumber;
        std::cin >> taskNumber;

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
    } else {
        std::cout << "No tasks available to edit." << std::endl;
    }
}

// delete a task 
void deleteTask(std::vector<Task>& tasks) {
    viewTasks(tasks);

    if (!tasks.empty()) {
        std::cout << "Enter the number of the task to delete: ";
        int taskNumber;
        std::cin >> taskNumber;

        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task deleted successfully!" << std::endl;
        } else {
            std::cout << "Invalid task number. Please try again." << std::endl;
        }
    } else {
        std::cout << "No tasks available to delete." << std::endl;
    }
}