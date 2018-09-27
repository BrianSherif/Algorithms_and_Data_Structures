#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* a, int* b);
void UseFirstTwoElements(int *arr, int length);
int partition(int* arr, int first, int last, int* lp);
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
  UseFirstTwoElements(arr, x-1); //swapping the second element with the last element
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
//function to swap last and second element in the array
void UseFirstTwoElements(int *arr, int length){
  if (arr[0]>=arr[1]) {
    swap(&arr[0], &arr[1]);
  }
  swap(&arr[1], &arr[length]);
}

void DPquickSort(int* arr, int first, int last)
{
  if (first < last) {
    int left;
    int right;
    right = partition(arr, first, last, &left);
    DPquickSort(arr, first, left - 1);
    DPquickSort(arr, left + 1, right - 1);
    DPquickSort(arr, right + 1, last);
  }
}

int partition(int* arr, int first, int last, int* lpi)
{
  //swap first and last if one is bigger than the other.
  if (arr[first] > arr[last]){
    swap(&arr[first], &arr[last]);
  }
  int lidx = first + 1;
  int ridx = last - 1;
  int lp = arr[first];
  int rp = arr[last];
  for ( int idx = first + 1; idx <= ridx; idx++) {
    // if elements are less than the left pivot
    if (arr[idx] < lp) {
      swap(&arr[idx], &arr[lidx]);
      lidx++;
    }
    // if elements are greater than or equal to the right pivot
    else if (arr[idx] >= rp) {
      while (arr[ridx] > rp && idx < ridx)
      ridx--;
      swap(&arr[idx], &arr[ridx]);
      ridx--;
      if (arr[idx] < lp) {
        swap(&arr[idx], &arr[lidx]);
        lidx++;
      }
    }
  }
  lidx--;
  ridx++;

  // bring pivots to their correct positions
  swap(&arr[first], &arr[lidx]);
  swap(&arr[last], &arr[ridx]);
  *lpi = lidx;
  return ridx;
}
