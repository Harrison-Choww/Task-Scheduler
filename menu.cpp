#include "menu.hpp"
//#include "window.hpp"

using namespace std;
/*Menu::Menu(string id, string desc, string date){
    Task<Component*> master(id,desc,date,'A');
    Schedules.push_back(main);
}*/
Task<Component*> Schedules("", "", "", 'A');

void Menu::menu() {
    string desc, date, id;

    cout << "Enter an ID" << endl;
    cin.clear();
    getline(cin, id);
    cout << "Enter a Description" << endl;
    cin.clear();
    getline(cin, desc);
    cout << "Enter a Date" << endl;
    cin.clear();
    cin >> date;
    //Task<Component*> main(id, desc, date, 'A');
    Task<Component*> Schedules(id, desc, date, 'A');
    //Schedules.push_back(main);
    int choice = 1;
    do {
        printOptions();
        cin.clear();
        cin >> choice;
        if (choice == 1) {
            addSchedule(Schedules);
        }
        else if (choice == 2) {
            deleteSchedule();
        }
        else if (choice == 4) {
            printSchedules(Schedules);
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Invalid Choice" << endl;
            cout << "Enter Another Choice" << endl;
        }

    } while (choice != 0);
}

void Menu::printOptions() {
    cout << "Menu" << endl;
    cout << "Add Schedule - 1" << endl;
    cout << "Delete Schedule - 2" << endl;
    cout << "Choose a Schedule to Edit - 3" << endl;
    cout << "Print Schedule - 4" << endl;
}

void Menu::addSchedule(Task<Component*> &Schedules) {
    string desc, date, id;

    cout << "Enter an ID" << endl;
    cin.clear();
    getline(cin, id);
    cout << "Enter a Description" << endl;
    cin.clear();
    getline(cin, desc);
    cout << "Enter a Date" << endl;
    cin.clear();
    cin >> date;

    bool valid;
    Task<Component*> sched(id, desc, date, 'A');
    /*
    if (!Schedules.empty()) {
        valid = Schedules.at(0).add(&sched);
    }
    else {
        cout << "No main exists" << endl;
        return;
    }
    */

    valid = Schedules.add(&sched);

    if (valid) {
        string choice;
        cout << "Would you like to add to the schedule? Yes or No." << endl;
        cin.clear();
        cin >> choice;
        if (choice == "Yes") {
            Window w;
            w.openW(sched);
        }
    }
    else {
        cout << "Error: ID already in use." << endl;
    }
}

void Menu::deleteSchedule() {
    /*
    string id;
    cout << "Enter ID of Schedule to delete" << endl;
    cin.clear();
    getline(cin,id);
    bool success = false;
    if (!Schedules.empty()) {
        Task<Component*> temp(id, "", "", 'D');
        success = Schedules.at(0).del(&temp);
    }
    if (success) {
        cout << "Schedule successfully removed" << endl;
    }
    else {
        cout << "Schedule not found" << endl;
    }

    */
}

void Menu::printSchedules(Task<Component*> &Schedules) {
    cout << "Your Schedule:" << endl << endl;
    Schedules.printID(0);
    
    
    Iterator<Component*, Task<Component*> > *it = Schedules.CreateIterator();
     for (it->First(); !it->IsDone(); it->Next()) {
     Component* node = *it->Current();
         cout << "ID : " << node->getID() << ", Desc : " << node->getDesc() << ", Date : " << node->getDate() << endl;
     }
     cout << '\n'; 
}
