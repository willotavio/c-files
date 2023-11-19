#ifndef HEADER_H
#define HEADER_H

typedef struct
{
  int id;
  char * name;
  int age;
  double gpa;
  char * class;
} Student;

void menu();
Student createStudent(char *, int, double, char *);
void addStudent(Student *);
void listStudents();
int studentExists(int);
bool findStudent(int);
void editStudent(int);
void updateStudent(int, char[50], int, double, char[3]);
void deleteStudent(int);
void freeMemory();

#endif