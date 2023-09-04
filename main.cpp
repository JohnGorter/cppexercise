#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./calc.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "teacher.h"
#include "student.h"

#define NUM_STUDENTS 20
#define MAX_LENGTH 20

// void getStudents(student* students, int total){
//   for (int i = total; i < NUM_STUDENTS; i++) {
//     students[i].age = 0;
//     printf("What is the age of student %d?", i); 
//     scanf("%d", &(students[i].age));
//     if (students[i].age == 0) break;
//     printf("%d", students[i].age);

//     printf("What is the name of student %d?", i); 
//     scanf("%19s", students[i].firstname);
//     printf("What is the lastname of student %d?", i); 
//     scanf("%19s", students[i].lastname);
//    }
// }
// void showStudents(student* students) {
//   for (int i = 0; i < NUM_STUDENTS; i++) {
//     studentptr pStudent = &students[i];
//     if (!pStudent->age) break;
//     std::cout << "Student "<< i + " is " << students[i].age << " " << students[i].firstname << " "  << students[i].lastname << std::endl;
//   }
// }
// void saveStudents(student* students) {
//   FILE* file = fopen ("./data.txt", "w");
//   for (int i = 0; i < NUM_STUDENTS; i++) {
//     studentptr pStudent =  &students[i];
//     if (!pStudent->age) break;
//     fprintf(file, "Student %d, is %d %s %s\r\n", i, students[i].age, students[i].firstname, students[i].lastname);
//   }
//   fclose(file); 
// }
// int loadStudents(student* students) {
//   int teller = 0;
//   FILE* file = fopen ("./data.txt", "r");
//   for (int i = 0; i < NUM_STUDENTS; i++) {
//     int index;
//     students[i].age = 0;
//     if (fscanf(file, "Student %d, is %d %s %s\r\n", &index, &students[i].age, students[i].firstname, students[i].lastname) == EOF) break;
//     teller++; 
//   }
//   fclose(file); 
//   return teller;
// }

void printStudents(std::vector<Person*>& students){
  for (Person* s : students) {
    std::cout << "Person name " << s->getName() << std::endl; 
  }
}

int IndexOfStudent(std::vector<Person*>& students, bool (*fn) (Person)){
   for (int i = 0; i < students.size(); i++) {
      if (fn(*students[i])) return i;
    }
    return -1; 
}

int RemoveStudent(std::vector<Person*>& students, int where){
  students.erase(students.begin() + where);
  return 1;
}

int InsertStudent(std::vector<Person*>& persons, int number, int age, std::string firstname, std::string lastname, int where){
    if (where == 0) 
      persons.push_back(new Student(number, age, firstname, lastname));
    else {
     // students.emplace(students.begin() + where, 1, age, firstname, lastname);
      persons.insert(persons.begin() + where, new Student(number, age, firstname, lastname));
    }
    return 1; 
}

int InsertTeacher(std::vector<Person*>& persons, std::string code, int age, std::string firstname, std::string lastname, int where){
    if (where == 0) 
      persons.push_back(new Teacher(code, age, firstname, lastname));
    else {
     // students.emplace(students.begin() + where, 1, age, firstname, lastname);
     persons.insert(persons.begin() + where, new Teacher(code, age, firstname, lastname));
    }
    return 1; 
}

int InsertStudent(std::vector<Person*>& students, int code, int age, char* firstname, char* lastname){
    return InsertStudent(students, code, age, firstname, lastname, 0); 
}

void p(std::string& test) {
  //// whatever
  test = "hello world";
}

int main(int argc, char** argv){
 //  STUDENTNODEPTR pHead = NULL; // LINKED LIST 
  std::vector<Person*> students; 

  InsertStudent(students, 1, 47, "john1", "gorter");
  InsertStudent(students, 2, 48, "john2", "gorter");
  InsertStudent(students, 3, 49, "john3", "gorter");
  InsertStudent(students, 4, 47, "john4", "gorter");
  printStudents(students);

  InsertStudent(students, 5, 47, "john3.5", "gorter",3);
  InsertTeacher(students, "gtrjm", 47, "(teacher)john", "gorter",3);

  printStudents(students);

  RemoveStudent(students, 3);
  printStudents(students);


  int index =  IndexOfStudent(students, [](Person s){
    return s.getAge() == 49;
  });
  RemoveStudent(students, index);
  std::cout << "%d" << index << std::endl; 
  printStudents(students);

  exit(0); 

  // int total_students = 0; 
  // student students[NUM_STUDENTS]; 
  // total_students = loadStudents(students); 
  // printf("these are the students...\r\n");

  // showStudents(students); 
  // printf("add some more students here...\r\n");
  //  getStudents(students, total_students); 
  //  showStudents(students); 
  //  saveStudents(students);
}

