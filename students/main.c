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
void editStudent(int);
void updateStudent(int, char[], int, char[]);
void listStudents();
int studentExists(int);
void findStudent(int);
void freeStudents();

static Student students[50];
static int index = 0;
static int id = -1;

int main()
{ 
  char name[100];
  int age;
  char class[3];
  char option;
  bool run = true;
  while(run)
  {
    printf("A. Add Student\nU. Update Student\nL. List Students\nF. Find Student\nQ. Quit\n");
    scanf(" %c", &option);
    option = toupper(option);
    while (getchar() != '\n');
    int idToEdit;
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
      case 'U':
        printf("Id: ");
        scanf("%d", &idToEdit);
        editStudent(idToEdit);
        break;
      case 'L':
        listStudents();
        break;
      case 'F':
        scanf("%d", &idToEdit);
        findStudent(idToEdit);
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

void editStudent(int id)
{
  int indexFound = studentExists(id);
  if(indexFound > -1)
  {
    char editOption;

    char newName[100];
    strcpy(newName, students[indexFound].name);
    int newAge = students[indexFound].age;
    char newClass[3];
    strcpy(newClass, students[indexFound].class);
    
    bool editing = true;
    while(editing)
    {
      printf("%s\n", newName);
      printf("%d\n", newAge);
      printf("%s\n", newClass);
      printf("N. Name\nA. Age\nC. Class\nS. Save\n");
      scanf(" %c", &editOption);
      editOption = toupper(editOption);
      while (getchar() != '\n');
      switch(editOption)
      {
        case 'N':
          printf("Name: ");
          scanf("%s", newName);
          break;
        case 'A':
          printf("Age: ");
          scanf("%d", &newAge);
          break;
        case 'C':
          printf("Class: ");
          scanf("%s", newClass);
          break;
        case 'S':
          editing = false;
          break;
        default:
          printf("Choose a valid option\n");
          break;
      }
    }
    updateStudent(indexFound, newName, newAge, newClass);
  }
  else
  {
    printf("Student not found\n");
  }
}

void updateStudent(int id, char name[], int age, char class[])
{
   strcpy(students[id].name, name);
   students[id].age = age;
   strcpy(students[id].class, class);
}

void listStudents()
{
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

int studentExists(int id)
{
  for(int i = 0; i < index; i++)
    {
      if(students[i].id == id)
      {
        return i;
      }
    }
    return -1;
}

void findStudent(int id)
{
  int foundIndex = studentExists(id);
  if(foundIndex > -1)
  {
    printf("----------------------\n");
    printf("Id: %d\n", students[foundIndex].id);
    printf("Name: %s\n", students[foundIndex].name);
    printf("Age: %d\n", students[foundIndex].age);
    printf("Class: %s\n", students[foundIndex].class);
    printf("----------------------\n");
  }
  else
  {
    printf("Student not found\n");
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