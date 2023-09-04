#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./calc.h"
#include <string>
#include <fstream>
#include <iostream>

#define NUM_STUDENTS 20
#define MAX_LENGTH 20


// typedef struct {
//   int age; 
//   std::string firstname; 
//   std::string lastname;
// } student, * studentptr;

typedef struct studentNode * STUDENTNODEPTR;
typedef struct studentNode {
  student student; 
  STUDENTNODEPTR next;
  
} STUDENTNODE;

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

void printStudents(STUDENTNODEPTR* pHead){
   STUDENTNODEPTR prev, curr = *pHead;
  while (curr != NULL) {
    std::cout << "Student name " << curr->student.firstname << std::endl; 
    curr = curr->next;
  }
}

int IndexOfStudent(STUDENTNODEPTR* pHead, bool (*fn) (student)){
  STUDENTNODEPTR prev, curr;
  if (*pHead == NULL) return -1;
  int index = 0; 
    prev = curr = *pHead;
    if (fn(curr->student)) return index;
    while (curr->next != NULL) {
      index++;
      curr = curr->next;
      if (fn(curr->student)) return index;
    }
    return -1; 
}

int RemoveStudent(STUDENTNODEPTR* pHead, int where){
  STUDENTNODEPTR prev, curr;
  if (*pHead == NULL && where != 0) return 0;
  int index = 0; 
    prev = curr = *pHead;
    if (where > 0) {
      while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        index++;
        if (index == where) break;
      }
    }
    if (index != where) return 0; 
    STUDENTNODEPTR temp = curr; 
    prev->next = curr->next; 
    temp->next = NULL;
    free(temp); 
    return 1;
}

int InsertStudent(STUDENTNODEPTR* pHead, int age, std::string firstname, std::string lastname, int where){
    STUDENTNODEPTR prev, curr;
    if (*pHead == NULL && where != 0) return 0;
    
    int index = 0; 
    prev = curr = *pHead;
    if (where > 0) {
      while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
        index++;
        if (index == where) break;
      }
    }
    if (index != where) return 0; 

    
    STUDENTNODEPTR pFirstStudent = (STUDENTNODEPTR) malloc(sizeof(STUDENTNODE)); 
    pFirstStudent->student.age = age; 
    pFirstStudent->student.firstname = firstname; 
    pFirstStudent->student.lastname = lastname; 
    
    if (where == 0) {
      if (*pHead == NULL) *pHead = pFirstStudent;
      else {
         while(curr->next != NULL) curr = curr->next;
         curr->next = pFirstStudent;
      } 
    }
    else {
      pFirstStudent->next = prev->next;
      prev->next = pFirstStudent;
    }
    return 1; 
}


int InsertStudent(STUDENTNODEPTR* pHead, int age, char* firstname, char* lastname){
    return InsertStudent(pHead, age, firstname, lastname, 0); 
}

void p(std::string& test) {
  //// whatever
  test = "hello world";

}

int main(int argc, char** argv){


  STUDENTNODEPTR pHead = NULL; // LINKED LIST 

  InsertStudent(&pHead, 47, "john1", "gorter");
  InsertStudent(&pHead, 48, "john2", "gorter");
  InsertStudent(&pHead, 49, "john3", "gorter");
  InsertStudent(&pHead, 47, "john4", "gorter");
  printStudents(&pHead);

  InsertStudent(&pHead, 47, "john3.5", "gorter",3);
  printStudents(&pHead);

  RemoveStudent(&pHead, 3);
  printStudents(&pHead);


  int index =  IndexOfStudent(&pHead, [](student s){
    return s.age == 49;
  });
  RemoveStudent(&pHead, index);
  std::cout << "%d" << index << std::endl; 
  printStudents(&pHead);

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

