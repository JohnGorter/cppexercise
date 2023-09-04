#include <string>
#include "teacher.h"


std::string Teacher::GetCode(){
    return m_Code;
}

std::string Teacher::getName() {
    return "TEACHER: " + m_Code + " " + Person::getName(); 
}


Teacher::Teacher(std::string n, int a, std::string f, std::string l) : Person (a, f, l) {
   m_Code = n; 
}


