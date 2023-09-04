#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
     int m_age; 
     std::string m_firstname;
     std::string m_lastname; 

    public:
    virtual std::string getName(); 
    int getAge(); 
    Person(int a, std::string f, std::string l); 
};

#endif