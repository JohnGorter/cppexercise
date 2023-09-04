#include <string>
#include "student.h"


std::string Student::getName() {
   return m_firstname + " " + m_lastname;
}

int Student::getAge() {
    return m_age;
}

Student::Student(int a, std::string f, std::string l) {
    m_age = a; 
    m_firstname = f; 
    m_lastname = l;
}


