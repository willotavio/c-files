#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct 
{
  int id;
  char * name;
  int age;
  char * class;
} Student;

Student createStudent(int, char[], int, char[]);
void addStudent(Student);
void listStudents();
void freeStudents();

static Student students[50];
static int index = 0;
static int id = 0;

int main()
{ 
  char name[100];
  int age;
  char class[3];
  char option;
  bool run = true;
  while(run)
  {
    printf("A. Add Student\nL. List Students\nQ. Quit\n");
    scanf(" %c", &option);
    option = toupper(option);
    while (getchar() != '\n');
    switch(option)
    {
      case 'A':
        printf("Name: ");
        scanf("%s", name);

        printf("Age: ");
        scanf("%d", &age);

        printf("Class: ");
        scanf("%s", class);

        Student s = createStudent(id+1, name, age, class);

        addStudent(s);
        break;
      case 'L':
        listStudents();
        break;
      case 'Q':
        run = false;
        break;
      default:
        printf("Choose a valid option\n");
        break;
    }
  }

  freeStudents();

  return 0;
}

Student createStudent(int id, char name[], int age, char class[])
{
  Student student;
  student.id = id;
  student.name = strdup(name);
  student.age = age;
  student.class = strdup(class);
  return student;
}

void addStudent(Student student)
{
  students[index] = student;
  index++;
  id++;
}

void listStudents(){
  if(index == 0)
  {
    printf("Empty list\n");
  }
  else
  {
    printf("\n----------------------");
    printf("\nListing all students: \n");
    for(int i = 0; i < index; i++)
    {
      printf("Id: %d\n", students[i].id);
      printf("Name: %s\n", students[i].name);
      printf("Age: %d\n", students[i].age);
      printf("Class: %s\n", students[i].class);
      printf("----------------------\n");
    }
  }
}

void freeStudents()
{
  for(int i = 0; i < index; i++)
  {
    free(students[index].name);
    free(students[index].class);
  }
}