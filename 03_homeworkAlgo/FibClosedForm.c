/*
Algorithms and data structures
Assignement 3.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int main() {
  int n = 0;
  int x;
  printf("Enter the nth number in fibonacci series: ");
  scanf("%d", &x);
    clock_t begin = clock();
  do{

  double gr = (1 + sqrt(5))/2;

  long long int Fib = ((pow(gr, n) - pow(1 - gr, n))/sqrt(5));
    clock_t end = clock();
  printf("\n%lld\n", Fib);
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\n %d, %lf\n\n", n, time_spent);
  n++;
} while(n<=x);
  return 0;
}
