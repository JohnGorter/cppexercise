#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <string>

class Teacher: public Person {
    private:
     std::string m_Code;

    public:
    std::string GetCode(); 
    std::string getName() override;
    Teacher(std::string code, int a, std::string f, std::string l); 
};
#endif