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
    printf("A. Add\nL. List\nF. Find\nQ. Quit\n");
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

void findStudent(int studentId)
{
  int foundId = studentExists(studentId);
  if(foundId > -1)
  {
    printf("---------------------\n");
    printf("Student Id: %d\n", students[foundId].id);
    printf("Name: %s\n", students[foundId].name);
    printf("Age: %d\n", students[foundId].age);
    printf("GPA: %.2lf\n", students[foundId].gpa);
    printf("Class: %s\n", students[foundId].class);
    printf("---------------------\n");
  }
  else
  {
    printf("Student not found\n");
  }
}