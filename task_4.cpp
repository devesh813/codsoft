#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;  // Maximum number of tasks

struct Task {
    string description;
    bool done;
};

void addTask(Task tasks[], int& taskCount, const string& description) {
    if (taskCount < MAX_TASKS) {
        Task task;
        task.description = description;
        task.done = false;
        tasks[taskCount++] = task;
        cout << "> Task '" << description << "' added to the list." << endl;
    } else {
        cout << "Task list is full. Cannot add more tasks." << endl;
    }
}

void removeTask(Task tasks[], int& taskCount, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskCount) {
        string removedTaskDescription = tasks[taskIndex].description;
        for (int i = taskIndex; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "> Task '" << removedTaskDescription << "' removed from the list." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void markTaskAsDone(Task tasks[], int taskIndex) {
    if (taskIndex >= 0 && taskIndex < MAX_TASKS) {
        tasks[taskIndex].done = true;
        cout << "> Task '" << tasks[taskIndex].description << "' marked as done." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void listTasks(const Task tasks[], int taskCount) {
    cout << "> Tasks in the list:" << endl;
    for (int index = 0; index < taskCount; ++index) {
        cout << index + 1 << ". " << tasks[index].description << " - " << (tasks[index].done ? "Done" : "Not done") << endl;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (true) {
        cout << "\nChoose an option to modify TO-DO list" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. Mark task as done" << endl;
        cout << "4. List tasks" << endl;
        cout << "5. Quit" << endl<<endl;

        int choice;
        cout<<"> Enter your choice: ";
        cin >> choice;
        cout<<endl;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, task);
                addTask(tasks, taskCount, task);
                break;
            }
            case 2: {
                int taskIndex;
                cout << "> Enter the task index to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskCount, taskIndex - 1);
                break;
            }
            case 3: {
                int taskIndex;
                cout << "> Enter the task index to mark as done: ";
                cin >> taskIndex;
                markTaskAsDone(tasks, taskIndex - 1);
                break;
            }
            case 4: {
                listTasks(tasks, taskCount);
                break;
            }
            case 5:
                cout << "Exiting the TO-DO list." << endl<<endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
                break;
        }
    }

    return 0;
}
