#ifndef HEADER_H
#define HEADER_H

typedef struct
{
  int id;
  char name[50];
  int age;
  double gpa;
  char class[3];
} Student;

void menu();
Student createStudent(char[50], int, double, char[3]);
void addStudent(Student);
void listStudents();
int studentExists(int);
void findStudent(int);

#endif