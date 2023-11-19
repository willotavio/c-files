#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/header.h"

int studentArraySize = 50;
static Student *students;
static int index = 0;
static int currentStudentId = -1;

void freeMemory()
{
  for(int i = 0; i < index; i++)
  {
    free(students[i].name);
    free(students[i].class);
  }
  free(students);
}

int main()
{
  students = (Student *)malloc(studentArraySize * sizeof(Student));
  if(students == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return (EXIT_FAILURE);
  }
  menu();

  freeMemory();
  return 0;
}

void menu()
{
  bool run = true;

  char * name = (char *) malloc(50 * sizeof(char));
  int age;
  double gpa;
  char * class = (char *) malloc(3 * sizeof(char));

  if(name == NULL || class == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  while(run)
  {
    int selectedId;
    printf("A. Add\nL. List\nF. Find\nU. Update\nD. Delete\nQ. Quit\n");
    char option;
    scanf(" %c", &option);
    option = toupper(option);
    getchar();

    switch(option)
    {
      case 'A':
        printf("Name: ");
        fgets(name, 50, stdin);
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
        fgets(class, 3, stdin);
        if(class[strlen(class) - 1] == '\n')
        {
          class[strlen(class) - 1] = '\0';
        }
        
        Student s1 = createStudent(name, age, gpa, class);
        addStudent(&s1);
        
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
      case 'D':
        printf("Id: ");
        scanf("%d", &selectedId);
        deleteStudent(selectedId);
        break;
      case 'Q':
        run = false;
        break;
      default:
        printf("Enter a valid option\n");
        break;
    }
  }
  free(name);
  free(class);
}

Student createStudent(char *name, int age, double gpa, char *class)
{
  Student student;
  student.name = (char *) malloc(strlen(name) + 1);
  student.class = (char *) malloc(strlen(class) + 1);

  if(student.name == NULL || student.class == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  student.id = currentStudentId + 1;
  if(strncpy(student.name, name, strlen(name) + 1) == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  student.age = age;
  student.gpa = gpa;
  if(strncpy(student.class, class, strlen(class) + 1) == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  return student;
}

void addStudent(Student *student)
{
  students[index] = *student;
  index++;
  currentStudentId++;
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
  int indexFound = studentExists(studentId);
  if(indexFound > -1)
  {
    printf("---------------------\n");
    printf("Student Id: %d\n", students[indexFound].id);
    printf("Name: %s\n", students[indexFound].name);
    printf("Age: %d\n", students[indexFound].age);
    printf("GPA: %.2lf\n", students[indexFound].gpa);
    printf("Class: %s\n", students[indexFound].class);
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
  int indexFound = studentExists(studentId);
  if(indexFound > -1)
  {
    char newName[50];
    strcpy(newName, students[indexFound].name);
    int newAge = students[indexFound].age;
    double newGpa = students[indexFound].gpa;
    char newClass[3];
    strcpy(newClass, students[indexFound].class);
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
          updateStudent(indexFound, newName, newAge, newGpa, newClass);
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

void updateStudent(int indexFound, char newName[50], int newAge, double newGpa, char newClass[3])
{
  if(strcmp(newName, students[indexFound].name) != 0)
  {
    strcpy(students[indexFound].name, newName);
  }
  if(newAge != students[indexFound].age)
  {
    students[indexFound].age = newAge;
  }
  if(newGpa != students[indexFound].gpa)
  {
    students[indexFound].gpa = newGpa;
  }
  if(strcmp(newClass, students[indexFound].class) != 0)
  {
    strcpy(students[indexFound].class, newClass);
  }
}

void deleteStudent(int studentId)
{
  int indexFound = studentExists(studentId);
  if(indexFound > -1)
  {
    for(int i = indexFound; i < index; i++)
    {
      students[i] = students[i+1];
    }
    index--;
  }
  else
  {
    printf("Student not found\n");
  }
}