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
long long int Fib (int n);
int main() {
  int n = 0;
  int x;
  printf("Enter the nth number in fibonacci series: ");
  scanf("%d", &x);
  clock_t begin = clock();
  do{
  printf("%lld, ", Fib(n));
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\n\n %d, %lf\n\n", n, time_spent);
  n++;
} while(n<=x);
  return 0;
}
//fibonacci function using recurssion
long long int Fib (int n){
  if (n<2) {
    return n; //since fibonacci of 0=0 & 1-1 & we cannot obtain fibonacci of negative numbers
  }
  else{
    //return will be a call of the function (base case of n<2 will stop execution)
    return (Fib(n-1)+Fib(n-2));
  }
}
