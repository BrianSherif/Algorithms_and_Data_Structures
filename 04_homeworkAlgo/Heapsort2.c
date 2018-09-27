#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

void sink(int *array, int start, int end);
void heapify(int *array, int length);
void Heapsort(int *array, int length);
void printArray(int arr[], int n);


int main() {
  int x;
  printf("Enter lenght of array\n");
  scanf("%d", &x);
  int * arr = malloc(x * sizeof(int));
  for(int i=0; i < x ;i++){
    arr[i]=rand()%x+1;
  }
  printf("before sorting\n");
  printArray(arr, x);
  clock_t begin = clock();
  Heapsort (arr, x);
  clock_t end = clock();
  printf("After sorting\n");
  printArray(arr, x);
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\n%lf\n\n", time_spent);
  return 0;
}



void sink(int *array, int start, int end)
{
  int root = start;
  while ((2 * (root) + 1) <= end)
  {
    int child = (2 * (root) + 1);
    int swap = root;

    if (array[swap] < array[child])
    {
      swap = child;
    }

    if ((child + 1) <= end && array[swap] < array[child + 1])
    {
      swap = child + 1;
    }

    if (swap != root)
    {
      int tmp = array[root];
      array[root] = array[swap];
      array[swap] = tmp;
      root = swap;            // continue sink down the child we just swapped with
    }
    else
    {
      return;
    }
  }
}




void heapify(int *array, int length)
{
  for (int start =(((length-1) - 1) / 2); start >= 0; start--)
  {
    sink(array, start, length - 1);
  }
}


void Heapsort(int *array, int length)
{
  heapify(array, length);
  int end = length - 1;
  while (end > 0)
  {
    int tmp = array[0];
    array[0] = array[end];
    array[end] = tmp;
    end--;
    sink(array, 0, end);
  }
}


void printArray(int arr[], int n)
{
  for (int i=0; i<n; ++i)
  printf("%d \n", arr[i]);
}
