#ifndef __TASK_HPP__
#define __TASK_HPP__
#include "component.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <string>
#include <vector>
//using namespace std;
template <class T>
class Task : public Component
{
private:
	std::vector<Task<Component*> > m_children;
	friend class Iterator<T, Task>;
public:
	Task(std::string ID, std::string Desc, std::string Date, char Status) : Component(ID, Desc, Date, Status) {}
	bool add(Task cmp);
	bool del(Task cmp);
	bool undel(Task cmp);
	void printID(int level);
	//insert getComponent here
	Task<Component*> getComponent(Task<Component*>& sched, std::string id);
	Iterator<T, Task>* CreateIterator();
};
#endif
