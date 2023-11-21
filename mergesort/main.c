#include <stdio.h>

void mergeSort(int[], int);
void merge(int[], int, int[], int, int[], int);

int main()
{
  int numbers[] = {5,8,4,3,7,1,6,9,2};
  int size = sizeof(numbers)/sizeof(numbers[0]);

  mergeSort(numbers, size);

  for(int i = 0; i < size; i++)
  {
    printf("%d", numbers[i]);
  }

  return 0;
}

void mergeSort(int numbers[], int size)
{
  if(size <= 1)
  {
    return;
  }

  int middle = size / 2;
  int leftArray[middle];
  int rightArray[size - middle];

  int leftSize = sizeof(leftArray)/sizeof(leftArray[0]);
  int rightSize = sizeof(rightArray)/sizeof(rightArray[0]);

  int j = 0;
  for(int i = 0; i < size; i++)
  {
    if(i < middle)
    {
      leftArray[i] = numbers[i];
    }
    else
    {
      rightArray[j] = numbers[i];
      j++;
    }
  }

  mergeSort(leftArray, leftSize);
  mergeSort(rightArray, rightSize);
  merge(leftArray, leftSize, rightArray, rightSize, numbers, size);

}

void merge(int leftArray[], int leftSize, int rightArray[], int rightSize, int numbers[], int size)
{
  int i = 0;
  int l = 0;
  int r = 0;

  while(l < leftSize && r < rightSize)
  {
    if(leftArray[l] < rightArray[r])
    {
      numbers[i] = leftArray[l];
      i++;
      l++;
    }
    else
    {
      numbers[i] = rightArray[r];
      i++;
      r++;
    }
  }
  while(l < leftSize)
  {
    numbers[i] = leftArray[l];
    i++;
    l++;
  }
  while(r < rightSize)
  {
    numbers[i] = rightArray[r];
    i++;
    r++;
  }
}