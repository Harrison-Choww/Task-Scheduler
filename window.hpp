#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include "component.hpp"
#include "Iterator.hpp"
#include "task.hpp"
#include "menu.hpp"

class Window {
public:
    void openW(Task<Component*> sched);
    void printWOptions();

private:
    void addTask(Task<Component*> sched);
    void addSubtask(Task<Component*> task);
};

#endif
