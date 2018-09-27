/*
Algorithms and data structures
Assignement 3.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//function prototype
long long int  BottomUpFib (int n);
int main() {
  int n = 0;
  int x;
  printf("Enter the nth number in fibonacci series: ");
  scanf("%d", &x);
  clock_t begin = clock();
  do{
  printf("%lld\n", BottomUpFib(n));
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\n %d, %lf\n\n", n, time_spent);
  n++;
} while(n<=x);
  return 0;
}
//bottom up fibonacci function where we calculate an array of fibonacci up to the nth term
long long int BottomUpFib (int n){
      long long int * F = malloc(n * sizeof(long long int));
      F[0] = 0; //base case for zero
      F[1] = 1;//base case for 1
      //for loop to allocate fibonacci numbers up to the nth term.
      for(int i = 2; i <= n; ++i){
       F[i] = F[i - 1] + F[i - 2]; //summing of fibonnacci numbers
     }
     return F[n]; //returning nth term for output
}
