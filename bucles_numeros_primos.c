#include <stdio.h>
#define N 1000

// numero primos del 1 al 1000
int main()
{
  int i, j;
  int divisores;

  for (i = 2; i <= N; i++)
  {
    divisores = 0;
    for (j = 1; j <= i; j++)
    {
      if (i % j == 0)
        divisores++;
    }
    if (divisores == 2)
    {
      printf("%d ", i);
    }
  }

  return 0;
}
