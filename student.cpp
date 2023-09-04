#include <string>
#include "student.h"


int Student::GetNumber(){
    return m_Number;
}

std::string Student::getName() {
    return "STUDENT: " + std::to_string(m_Number) + " " + Person::getName(); 
}

Student::Student(int n, int a, std::string f, std::string l) : Person (a, f, l) {
   m_Number = n; 
}


