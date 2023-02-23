#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "window.hpp"
#include "Iterator.hpp"
#include "component.hpp"
#include "task.hpp"
//#include "task.cpp"
//#include "window.cpp"

class Menu {
public:
    void menu();
    /* Menu(string id, string desc, string date);*/

private:
    //vector<Task<Component*>> Schedules;
    void printOptions();
    void addSchedule(Task<Component*> &);
    void deleteSchedule();
    //void chooseSchedule();
    void printSchedules(Task<Component*> &Schedules);
};

#endif
