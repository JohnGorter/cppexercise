#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./calc.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

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

void printStudents(std::vector<Student>& students){
  for (Student& s : students) {
    std::cout << "Student name " << s.getName() << std::endl; 
  }
}

int IndexOfStudent(std::vector<Student>& students, bool (*fn) (Student)){
   for (int i = 0; i < students.size(); i++) {
      if (fn(students[i])) return i;
    }
    return -1; 
}

int RemoveStudent(std::vector<Student>& students, int where){
  students.erase(students.begin() + where);
  return 1;
}

int InsertStudent(std::vector<Student>& students, int age, std::string firstname, std::string lastname, int where){
    if (where == 0) 
      students.emplace_back(age, firstname, lastname);
    else 
      students.emplace(students.begin() + where, age, firstname, lastname);
    return 1; 
}

int InsertStudent(std::vector<Student>& students, int age, char* firstname, char* lastname){
    return InsertStudent(students, age, firstname, lastname, 0); 
}

void p(std::string& test) {
  //// whatever
  test = "hello world";
}

int main(int argc, char** argv){
 //  STUDENTNODEPTR pHead = NULL; // LINKED LIST 
  std::vector<Student> students; 

  InsertStudent(students, 47, "john1", "gorter");
  InsertStudent(students, 48, "john2", "gorter");
  InsertStudent(students, 49, "john3", "gorter");
  InsertStudent(students, 47, "john4", "gorter");
  printStudents(students);

  InsertStudent(students, 47, "john3.5", "gorter",3);
  printStudents(students);

  RemoveStudent(students, 3);
  printStudents(students);


  int index =  IndexOfStudent(students, [](Student s){
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

