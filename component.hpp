#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <string>

class Component {
private:
    std::string m_ID;
    std::string m_Desc;
    std::string m_Date;
    char m_Status;

public:
    Component(std::string ID, std::string Desc, std::string Date, char Status)
        : m_ID(ID), m_Desc(Desc), m_Date(Date), m_Status('A') {}

    virtual void printID(int level) = 0;
    std::string getID() { return this->m_ID; }
    std::string getDesc() { return this->m_Desc; }
    std::string getDate() { return this->m_Date; }
    char getStatus() { return this->m_Status; }
    void setStatus(char m_Status) { this->m_Status = m_Status; }


};

#endif
