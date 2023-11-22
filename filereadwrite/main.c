#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void writeFile(char *, int);
void appendFile(char *, int);
void readFile();

int main()
{
  bool run = true;

  while(run)
  {
    char option;
    printf("W\nA\nR\nQ\n");
    scanf("%c", &option);
    option = toupper(option);
    getchar();
    char *content = NULL;
    switch(option)
    {
      case 'W':
        content = (char *)malloc(255 * sizeof(char));
        if(content == NULL)
        {
          fprintf(stderr, "Memory allocation failed");
          exit(EXIT_FAILURE);
        }
        fgets(content, 255, stdin);
        writeFile(content, strlen(content));
        free(content);
        break;
      case 'A':
        content = (char *)malloc(255 * sizeof(char));
        if(content == NULL)
        {
          fprintf(stderr, "Memory allocation failed");
          exit(EXIT_FAILURE);
        }
        fgets(content, 255, stdin);
        appendFile(content, strlen(content));
        free(content);
        break;
      case 'R':
        readFile();
        break;
      case 'Q':
        run = false;
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  }

  return 0;
}

void writeFile(char *content, int size)
{
  FILE *pF = fopen("text.txt", "w");
  fprintf(pF, content);
  fclose(pF);
}

void appendFile(char *content, int size)
{
  FILE *pF = fopen("text.txt", "a");
  fprintf(pF, content);
  fclose(pF);
}

void readFile()
{
  FILE *pF = fopen("text.txt", "r");
  char * buffer = NULL;
  buffer = (char *)malloc(255 * sizeof(char));
  while(fgets(buffer, 255, pF))
  {
    printf("%s", buffer);
  }
  free(buffer);
  fclose(pF);
}