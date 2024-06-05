#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> todoList;
    char choice;

    do {
        cout << "\n======= To-Do List =======\n";
        cout << "1. Add a task\n";
        cout << "2. View tasks\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string task;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, task);
                todoList.push_back(task);
                cout << "Task added successfully!\n";
                break;
            }
            case '2': {
                if(todoList.empty()) {
                    cout << "No tasks in the list.\n";
                } else {
                    cout << "\n======= Tasks =======\n";
                    for(int i = 0; i < todoList.size(); ++i) {
                        cout << i+1 << ". " << todoList[i] << endl;
                    }
                }
                break;
            }
            case '3':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != '3');

    return 0;
}
