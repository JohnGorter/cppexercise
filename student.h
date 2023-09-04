#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
    private:
     int m_age; 
     std::string m_firstname;
     std::string m_lastname; 

    public:
    std::string getName(); 
    int getAge(); 
    Student(int a, std::string f, std::string l); 
};

#endif