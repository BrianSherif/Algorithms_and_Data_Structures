/*
Algorithms and data structures
Assignement 2.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//function prototypes
void sort (int *array, int low, int high);
void merge (int *array, int *sub, int low, int mid, int high);
void split (int *array, int *sub, int low, int high, int k);
void printArray(int arr[], int size);
int main(int argc, char** argv) {
  int m = 0;
  int n;
  int k;
  printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter length of k\n");
  scanf("%d", &k);
  int splits = n/k;
  int *arr = malloc(n * sizeof(int));
  int *sub = malloc(n * sizeof(int));
  clock_t begin = clock(); //using to measure execution time
  //the following allows us to generate a random sequence of numbers
  //this is done by using the rand function and then allocating it into the array
  srand(time(NULL));
  for(int i=0; i < n ;i++){
    arr[i]=rand()%10000+1;
  }
  //calling split function to break down array of numbers to arrays of length K for insertion sort.
  split (arr, sub, 0, n, k);
  //printing of sorted list
  printf("Sorted List: \n");
  printArray(arr, n-1);
  clock_t end = clock();
  //printing time takwn for execution
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  m++;
  printf("\n\n %d, %lf\n\n", n, time_spent);
  //free memory allocated
  free(arr);
  free(sub);
  return 0;
}
//function used to break list down to sub-lists
void split (int *arr, int *sub, int low, int high, int k) {
  if (low < high - 1) {
    int mid = (low + high) / 2;
    split(arr, sub, low, mid, k);
    split(arr, sub, mid, high, k);
    //comparing if list is of length k.
    if ((high - low) >= k){
      merge(arr, sub, low, mid, high);
    } else {
      //using insert sort till the lists are of size k
      sort(arr, low, high);
    }}}

    //Function for insertion sort which takes the  split arrays and sorts them.
void sort (int *arr, int low, int high) {
  for (int i = low; i < high; i++) {
    for (int j = i - 1; j >= low; j--) {
      //comparing elements in array one with the other and assigning a subsitute element to switch elements.
      if (arr[i] < arr [j]) {
        int sub = arr[j];
        arr[j] = arr[i];
        arr[i] = sub;
        i--;
      }}}}

void merge (int *arr, int *sub, int low, int mid, int high) {
  int a = low; // Initial index of first split
  int b = low; // Initial index of second split
  int c = mid; // Initial index of merged subarray
  while ((a < mid) && (c < high)) {
    if (arr[a] <= arr[c]) {
    sub[b] = arr[a];
    a++;
  } else {
    sub[b] = arr[c];
    c++;
        }
    b++;
    }
/* Copy the remaining elements from 1 side*/
  while (a == mid && c < high) {
    sub[b] = arr[c];
    c++;
    b++;
    }
/* Copy the remaining elements from the other side*/
  while (c == high && a < mid) {
    sub[b] = arr[a];
    a++;
    b++;
    }
    for (int d = low; d < high; d++) {
      arr[d] = sub[d];
      }}

//function to print taken from last homework
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++){
  printf("%d \n", arr[i]);
  }}
