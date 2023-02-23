#include "window.hpp"

void Window::openW(Task<Component*> sched) {
    string choice = "1";
    do {
        printWOptions();
        cin >> choice;
        if (choice == "1") {
            addTask(sched);
        }
        /*else if(choice == "2"){
 *             deleteTask(sched);
 *                     } */
        else if (choice == "3") {
            addSubtask(sched);
        }
        /*else if(choice == "4"){
 *             deleteSubtask(sched);
 *                     } */
        else if (choice == "0") {
            break;
        }
        else {
            cout << "Invalid Choice" << endl;
            cout << "Enter Another Choice" << endl;
        }

    } while (choice != "0");
}

void Window::printWOptions() {
    cout << "Options" << endl;
    cout << "Add Task - 1" << endl;
    cout << "Delete Task - 2" << endl;
    cout << "Add Subtask - 3" << endl;
    cout << "Delete Subtask - 4" << endl;
}

void Window::addTask(Task<Component*> sched) {
    string desc, date, id;

    cout << "Enter an ID" << endl;
    cin >> id;
    cout << "Enter a Description" << endl;
    cin >> desc;
    cout << "Enter a Date" << endl;
    cin >> date;

    if (sched.getID() == id) {
        cout << "ID is already used" << endl;
    }
    Task<Component*> task(id, desc, date, 'A');
    bool success = sched.add(&task);
    if (success) {
        string choice;
        cout << "Task successfully added" << endl;
        cout << "Would you like to add a subtask? Yes or No" << endl;
        cin >> choice;
        while (choice == "Yes") {
            addSubtask(task);
            cout << "Would you like to add another subtask? Yes or No" << endl;
            cin >> choice;
        }
    }
    else {
        cout << "Error: ID already in use" << endl;
    }
}

void Window::addSubtask(Task<Component*> task) {
    string desc, date, id;

    cout << "Enter an ID" << endl;
    cin >> id;
    cout << "Enter a Description" << endl;
    cin >> desc;
    cout << "Enter a Date" << endl;
    cin >> date;
    Task<Component*> subtask(id, desc, date, 'A');
    bool success = task.add(&subtask);
    if (success) {
        cout << "Successfully added subtask" << endl;
    }
    else {
        cout << "Error: ID already in use" << endl;
    }
}
