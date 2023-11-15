#include <stdio.h>
#include <string.h>

typedef struct 
{
  char * name;
  int age;
  char * class;
} Student;

Student createStudent(char[], int, char[]);
void addStudent(Student);

static Student students[50];
static int index = 0;

int main()
{
  while(1)
  {
    char name[100];
    int age;
    char class[3];

    printf("Name: ");
    scanf("%s", name);

    if(strcmp(name, "exit") == 0)
    {
      break;
    }

    printf("Age: ");
    scanf("%d", &age);

    printf("Class: ");
    scanf("%s", class);

    Student s = createStudent(name, age, class);

    addStudent(s);

  }
  
  for(int i = 0; i < index; i++)
  {
    printf("\nLooping through all students %d\n", i);
    printf("Name: %s\n", students[i].name);
    printf("Age: %d\n", students[i].age);
    printf("Class: %s\n", students[i].class);
  }

  return 0;
}

Student createStudent(char name[], int age, char class[])
{
  Student student;
  student.name = strdup(name);
  student.age = age;
  student.class = strdup(class);
  return student;
}

void addStudent(Student student)
{
  students[index] = student;
  index++;
}