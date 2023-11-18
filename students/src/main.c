#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../include/header.h"

static Student students[50];
static int index = 0;
static int studentId = -1;

int main()
{
  menu();
  
  return 0;
}

void menu()
{
  bool run = true;

  while(run)
  {
    int selectedId;
    printf("A. Add\nL. List\nF. Find\nU. Update\nQ. Quit\n");
    char option;
    scanf(" %c", &option);
    option = toupper(option);
    getchar();

    char name[50];
    int age;
    double gpa;
    char class[3];

    switch(option)
    {
      case 'A':
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        if(name[strlen(name) - 1] == '\n')
        {
          name[strlen(name) - 1] = '\0';
        }

        printf("Age: ");
        scanf("%d", &age);

        printf("GPA: ");
        scanf("%lf", &gpa);

        getchar();

        printf("Class: ");
        fgets(class, sizeof(class), stdin);
        if(class[strlen(class) - 1] == '\n')
        {
          class[strlen(class) - 1] = '\0';
        }
        
        Student s1 = createStudent(name, age, gpa, class);
        addStudent(s1);
        
        break;
      case 'L':
        listStudents();
        break;
      case 'F':
        printf("Id: ");
        scanf("%d", &selectedId);
        findStudent(selectedId);
        break;
      case 'U':
        printf("Id: ");
        scanf("%d", &selectedId);
        editStudent(selectedId);
        break;
      case 'Q':
        run = false;
        break;
      default:
        printf("Enter a valid option");
        break;
    }
  }
}

Student createStudent(char name[50], int age, double gpa, char class[3])
{
  Student student;
  student.id = studentId + 1;
  strcpy(student.name, name);
  student.age = age;
  student.gpa = gpa;
  strcpy(student.class, class);
  return student;
}

void addStudent(Student student)
{
  students[index] = student;
  index++;
  studentId++;
}

void listStudents(){
  if(index < 1)
  {
    printf("List is empty\n");
  }
  else
  {
    printf("---------------------\n");
    for(int i = 0; i < index; i++)
    {
      printf("Id: %d\n", students[i].id);
      printf("Name: %s\n", students[i].name);
      printf("Age: %d\n", students[i].age);
      printf("GPA: %.2f\n", students[i].gpa);
      printf("Class: %s\n", students[i].class);
      printf("---------------------\n");
    }
  }
}

int studentExists(int studentId)
{
  for(int i = 0; i < index; i++)
  {
    if(students[i].id == studentId)
    {
      return i;
    }
  }
  return -1;
}

bool findStudent(int studentId)
{
  int foundIndex = studentExists(studentId);
  if(foundIndex > -1)
  {
    printf("---------------------\n");
    printf("Student Id: %d\n", students[foundIndex].id);
    printf("Name: %s\n", students[foundIndex].name);
    printf("Age: %d\n", students[foundIndex].age);
    printf("GPA: %.2lf\n", students[foundIndex].gpa);
    printf("Class: %s\n", students[foundIndex].class);
    printf("---------------------\n");
    return true;
  }
  else
  {
    printf("Student not found\n");
    return false;
  }
}

void editStudent(int studentId)
{
  int foundIndex = studentExists(studentId);
  if(foundIndex > -1)
  {
    char newName[50];
    strcpy(newName, students[foundIndex].name);
    int newAge = students[foundIndex].age;
    double newGpa = students[foundIndex].gpa;
    char newClass[3];
    strcpy(newClass, students[foundIndex].class);
    bool editing = true;
    while(editing)
    {
      printf("---------------------\n");
      printf("Student Id: %d\n", studentId);
      printf("Name: %s\n", newName);
      printf("Age: %d\n", newAge);
      printf("GPA: %.2lf\n", newGpa);
      printf("Class: %s\n", newClass);
      printf("---------------------\n");
      char editOption;
      printf("N. Name\nA. Age\nG. GPA\nC. Class\nS. Save\n");
      scanf(" %c", &editOption);
      editOption = toupper(editOption);
      getchar();
      switch(editOption)
      {
        case 'N':
          printf("Name: ");
          fgets(newName, sizeof(newName), stdin);
          if(newName[strlen(newName) - 1] == '\n')
          {
            newName[strlen(newName) - 1] = '\0';
          }
          break;
        case 'A':
          printf("Age: ");
          scanf("%d", &newAge);
          getchar();
          break;
        case 'G':
          printf("GPA: ");
          scanf("%lf", &newGpa);
          getchar();
          break;
        case 'C':
          printf("Class: ");
          fgets(newClass, sizeof(newClass), stdin);
          if(newClass[strlen(newClass) - 1] == '\n')
          {
            newClass[strlen(newClass) - 1] = '\0';
          }
          break;
        case 'S':
          editing = false;
          updateStudent(foundIndex, newName, newAge, newGpa, newClass);
          break;
        default:
          printf("Enter a valid option\n");
          break;
      }
    }
  }
  else
  {
    printf("Student not found\n");
  }
}

void updateStudent(int foundIndex, char newName[50], int newAge, double newGpa, char newClass[3])
{
  if(strcmp(newName, students[foundIndex].name) != 0)
  {
    strcpy(students[foundIndex].name, newName);
  }
  if(newAge != students[foundIndex].age)
  {
    students[foundIndex].age = newAge;
  }
  if(newGpa != students[foundIndex].gpa)
  {
    students[foundIndex].gpa = newGpa;
  }
  if(strcmp(newClass, students[foundIndex].class) != 0)
  {
    strcpy(students[foundIndex].class, newClass);
  }
}