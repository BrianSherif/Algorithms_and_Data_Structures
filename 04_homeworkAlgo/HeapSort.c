#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

void HeapSort(int arr[], int n);
void Max_Heapify(int arr[], int n, int i);
//int Heap_Maximum (int arr[]);
//int Heap_extract_max (int arr[], int n);
//void Heap_increase_key(int arr[], int i, int key);
//void Max_Heap_Insert (int arr[], int key, int n);
void printArray(int arr[], int n);
int main() {
  int x;
  printf("Enter lenght of array\n");
  scanf("%d", &x);
  int * arr = malloc(x * sizeof(int));
  for(int i=0; i < x ;i++){
    arr[i]=rand()%100+1;
  }
  printf("before sorting\n");
  printArray(arr, x);
  clock_t begin = clock();
  HeapSort (arr, x);
  clock_t end = clock();
  printf("After sorting\n");
  printArray(arr, x);
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\n%lf\n\n", time_spent);
  return 0;
}

void HeapSort(int arr[], int n)
{
  int i;
  for (i = (n/2 - 1); i >= 0; i--)
  Max_Heapify(arr, n, i);

  for (int i=n-1; i>=0; i--)
  {
    int exchange = arr [i];
    arr [i] = arr [0];
    arr [0] = exchange;
    Max_Heapify(arr, i, 0);
  }
}

void Max_Heapify(int arr[], int n, int i)
{
  int largest = i;  // Initialize largest as root
  int l = 2*i;  // left = 2*i + 1
  int r = 2*i + 1;  // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest]){
    largest = l;
  }
  if (r < n && arr[r] > arr[largest]){
    largest = r;
  }
  if (largest != i)
  {
    int exchange = arr [i];
    arr [i] = arr [largest];
    arr [largest] = exchange;
    Max_Heapify(arr, n, largest);
  }
}

/*
int Heap_Maximum (int arr[]){
return arr[1];
}

int Heap_extract_max (int arr[], int n){
if (Heapsize < 1) {
printf("Heap underflow!\n");
exit (1);
}
int max = arr[1];
arr [1]=arr[Heapsize];
n--;
Max_Heapify (arr, 1, n);
return max;
}


void Heap_increase_key(int arr[], int i, int key){
if (key<arr[i]) {
printf("New key is smaller than current key\n");
exit(2);
}
arr[i]=key;
while (i>1 && arr[i/2]<arr[i]) {
int exchange = arr [i];
arr [i] = arr [i/2];
arr [i/2] = exchange;
i = arr [i/2];
}
}

void Max_Heap_Insert (int arr[], int key, int n){
n++;
arr[Heapsize]= -HUGE_VAL;
Heap_increase_key(arr, n, key);
}
*/

void printArray(int arr[], int n)
{
  for (int i=0; i<n; ++i)
  printf("%d \n", arr[i]);
}
