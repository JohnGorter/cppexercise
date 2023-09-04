#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "person.h"
#include <string>

class Student: public Person {
    private:
     int m_Number;

    public:
    int GetNumber(); 
    std::string getName() override;
    Student(int n, int a, std::string f, std::string l); 
};

#endif