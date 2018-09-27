/*
Algorithms and data structures
Assignement 1.2
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void worstCase();
void swap(int * minID, int * yp);
void printArray(int arr[], int size);

int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  /*
  printf("Enter number of elements\n");
  scanf("%d", &n
  */
  int * arr = malloc(n * sizeof(int));
  //the following allows us to generate a random sequence of numbers
  //this is done by using the rand function and then allocating it into the array
  for (int c = 0; c < n; c++) {
    arr[c] = rand();
  }
  // the sorting of the array using selection sort
  for (int i = 0; i < n - 1; i++) {
    int minID = i;
    for (int j = i + 1; j < n; j++){
      if (arr[j] < arr[minID])
      minID = j;
    }
    swap( & arr[minID], & arr[i]);
  }
  printf("Sorted List: \n");
  printArray(arr, n);
  //worstCase(arr, n);
  free(arr);
  return 0;
}

//function to print all the elements in the array
//Print array may also be considered the best case condition in which the array is already Sorted
//in this case the minID = j will not run saving a small amount of time
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++){
    printf("%d\n", arr[i]);
    printf("\n");
  }
}
//worst case simply takes the ordered array and flips it.
//this means that the system must search through the whole array before it can start sorting.
void worstCase(int arr[], int size) {
  int i = 0;       // Assigning i to first array element
  int j = size - 1;   // Assigning j to Last array element

  while (i < j)
  {
    swap(arr + i, arr + j);
    i++;
    j--;
  }

  printf("Result of an Reverse array is: \n");
  for (i = 0; i < size; i++)
  {
    printf("%d \n", arr[i]);
  }
}
//function to swap all the elements to their new positions in the sub array
void swap(int * minID, int * yp) {
  int temp = * minID;
  * minID = * yp;
  * yp = temp;
}
