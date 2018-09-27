#include <stdio.h>
#include <stdlib.h>


//please note that the following algorithm does not properly sort.

void printArray(int * arr, int n){
  for (int i = 0; i < n; i++)
  printf(" %d;", arr[i]);
}

//function to find largest number
int LargeNum(int *arr, int n){
  int large = -1;
  for(int i = 0; i < n; i++){
    if(arr[i] > large)
    large = arr[i];
  }
  return large;
}


// Radix Sort inspired by online version of normal Radix sort then tried to reseverse it
void radixSort(int * arr, int size){
  int semiSorted[size];
  int significantDigit = 100; //starting from base 100
  int largestNum = LargeNum(arr, size);
  // Loop until we reach the smallest significant digit
  while (significantDigit >= 1){
    printf("\nsorting: %d's place ", significantDigit);
    printArray(arr, size);
    int temp[10] = { 0 };
    for (int i = 0; i < size; i++)
    temp[(arr[i] / significantDigit) % 10]++;
    for (int i = 1; i < 10; i++)
    temp[i] += temp[i - 1];
    for (int i = size - 1; i >= 0; i--)
    semiSorted[--temp[(arr[i] / significantDigit) % 10]] = arr[i];
    for (int i = 0; i < size; i++)
    arr[i] = semiSorted[i];
    significantDigit /= 10;
  }
}


int main(){
  int x;
  printf("Enter length of array\n");
  scanf("%d", &x);
  int * arr = malloc(x * sizeof(int));
  for(int i=0; i < x ;i++){
    arr[i]=rand()%100+1;
  }
  printf("\nUnsorted List: ");
  printArray(&arr[0], x);
  radixSort(&arr[0], x);
  printf("\nSorted List:");
  printArray(&arr[0], x);
  printf("\n");
  return 0;
}
