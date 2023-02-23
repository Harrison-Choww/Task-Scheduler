#include "task.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
bool Task<T>::add(Task<T> cmp)
{
	for (int i = 0; i < m_children.size(); i++)
	{
		if (m_children.at(i).getID() == cmp.getID() && m_children.at(i).getStatus() == 'A')
		{
			cout << m_children.at(0).getID() << endl;
			return false;
		}
	}
	m_children.push_back(cmp);
	cout << m_children.at(0).getID() << endl;
	return true;
}
template <class T>
bool Task<T>::del(Task<T> cmp)
{
	if (m_children.size() == 0) {
		cout << "SIZE 0" << endl;
	}
	for (int i = 0; i < m_children.size(); i++)
	{
		cout << "Enter" << endl;
		cout << m_children.at(i).getID() << endl << endl;
		cout << "Enter" << endl;
		if (m_children.at(i).getID() == cmp.getID())
		{
			cout << "Enter" << endl;
			m_children.at(i).setStatus('D');
			cout << "Exit" << endl;
			return true;
		}
	}
	return false;
}
template<class T>
bool Task<T>::undel(Task cmp)
{
	for (unsigned int i = 0; i < unsigned(m_children.size()); i++)
	{
		if (m_children.at(i).getID() == cmp.getID())
		{
			m_children.at(i).setStatus('A');
			return true;
		}
	}
	return false;
}
template<class T>
void Task<T>::printID(int level)
{
	for (int j = 0; j < level; j++)
		cout << "\t";
	if (getStatus() == 'A')
	{
		if (level == 0)
		{
			cout << "Master ID: ";
		}
		else if (level == 1)
		{
			cout << "Schedule ID: ";
		}
		else
		{
			cout << "Task ID: ";
		}
		cout << this->getID().c_str() << ", Desc :" << this->getDesc().c_str() << ", Date : " << getDate() << "\n";
	}
	if (!m_children.empty())
	{
		++level;
		for (unsigned int i = 0; i < unsigned(m_children.size()); ++i)
		{
			if (m_children.at(i).getStatus() == 'A')
			{
				m_children.at(i).printID(level);
			}
		}
	}
	else {
		cout << "Empty children" << endl;
	}
}
template <class T>
Task<Component*> Task<T>::getComponent(Task<Component*>& sched, string id)
{
	for (int i = 0; i < m_children.size(); ++i)
	{
		if (id == m_children.at(i).getID())
		{
			return m_children.at(i);
		}
	}
}
template <class T>
Iterator<T, Task<T> >* Task<T>::CreateIterator()
{
	return new Iterator<T, Task>(this);
}
