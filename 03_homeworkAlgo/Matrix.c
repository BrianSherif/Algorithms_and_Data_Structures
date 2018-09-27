/*
Algorithms and data structures
Assignement 3.1
Brian Sherif Nazmi Hanna Nasralla
b.hannanasralla@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//function prototypes
void multiply(int A[2][2], int B[2][2]);
void power(int A[2][2], int n);
int fib(int n);

int main()
{
  int n = 0;
  int x;
  printf("Enter the nth number in fibonacci series: ");
  scanf("%d", &x);
  clock_t begin = clock();
  do{
    printf("%d\n", fib(n));
    clock_t end = clock();
    double time_spent = (long double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\n %d, %lf\n\n", n, time_spent);
    n++;
  } while (n<=x);
  return 0;
}

int fib(int n)
{
  int A[2][2] = {{1,1},{1,0}};
  if (n == 0){
    return 0;
  }
  power(A, n-1);
  return A[0][0];
}

void multiply(int A[2][2], int B[2][2])
{
  int x =  A[0][0]*B[0][0] + A[0][1]*B[1][0];
  int y =  A[0][0]*B[0][1] + A[0][1]*B[1][1];
  int z =  A[1][0]*B[0][0] + A[1][1]*B[1][0];
  int w =  A[1][0]*B[0][1] + A[1][1]*B[1][1];

  A[0][0] = x;
  A[0][1] = y;
  A[1][0] = z;
  A[1][1] = w;
}

void power(int A[2][2], int n)
{
  int B[2][2] = {{1,1},{1,0}};
  for (int i = 2; i <= n; i++)
  {
    multiply(A, B);
  }
}
