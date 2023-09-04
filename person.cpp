#include "person.h"
#include <string>


std::string Person::getName() {
   return m_firstname + " " + m_lastname;
}

int Person::getAge() {
    return m_age;
}

Person::Person(int a, std::string f, std::string l) {
    m_age = a; 
    m_firstname = f; 
    m_lastname = l;
}