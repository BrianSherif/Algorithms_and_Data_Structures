#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* a, int* b);
int random_partition(int* arr, int first, int last);
void DPquickSort(int* arr, int first, int last);

int main() {
  int x;
  printf("Enter lenght of array\n");
  scanf("%d", &x);
  int * arr = malloc(x * sizeof(int));
  for(int i=0; i < x ;i++){
    arr[i]=rand()%100+1;
  }
  clock_t begin = clock();
  DPquickSort(arr, 0, x);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  for (int i=0; i<x; ++i){
    printf("%d \n", arr[i]);
  }
  printf("\n\n%lf\n\n", time_spent);
  return 0;
}


void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


void DPquickSort(int* arr, int first, int last)
{
  if (first < last) {
    int left;
    int right;
    right = random_partition(arr, first, last);
    DPquickSort(arr, first, left - 1);
    DPquickSort(arr, left + 1, right - 1);
    DPquickSort(arr, right + 1, last);
  }
}

int random_partition(int* arr, int start, int end)
{
    //random function to create one pivot that is randomly selected from the size of the array
    srand(time(NULL));
    int pivotIdx1 = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx1];
    swap(&arr[pivotIdx1], &arr[end]); // move pivot element to the end
    pivotIdx1 = end;
    int i = start -1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[pivotIdx1]);
    return i+1;
}
