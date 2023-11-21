#include <stdio.h>

void bubbleSort(int [], int);

int main()
{
  int numbers[] = {7,2,4,9,8,3,6,1,5};
  int size = sizeof(numbers)/sizeof(numbers[0]);

  for(int i = 0; i < size; i++)
  {
    printf("%d", numbers[i]);
  }
  printf("\n");

  bubbleSort(numbers, size);

  return 0;
}

void bubbleSort(int numbers[], int size)
{
  for(int i = 0; i < size-1; i++)
  {
    for(int j = 0; j < size-1; j++)
    {
      if(numbers[j] > numbers[j+1])
      {
        int temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;
      }
      
      for(int i = 0; i < size; i++)
      {
        printf("%d", numbers[i]);
      }
      printf("\n");
    }
      printf("\n");
  }
}