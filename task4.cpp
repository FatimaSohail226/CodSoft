#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a task
void addTask(vector<Task>& tasks, const string& taskDescription) {
    tasks.emplace_back(taskDescription);
}

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << (tasks[i].completed ? " (Completed)" : " (Pending)") << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int taskNumber) {
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNumber - 1].completed = true;
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int taskNumber) {
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + taskNumber - 1);
}

int main() {
    vector<Task> tasks;
    int choice, taskNumber;
    string taskDescription;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                markTaskCompleted(tasks, taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(tasks, taskNumber);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
