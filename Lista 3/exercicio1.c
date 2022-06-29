#include <stdio.h>
void troca(int *p1, int *p2);

int main()
{
  int x[5];
  x[0] = 0;
  x[1] = 1;
  x[2] = 2;
  x[3] = 3;
  x[4] = 4;
  troca(x + 1, x + 4);
  return 0;
}

void troca(int *p1, int *p2)
{
  printf("%d, %d\n", *p1, *p2);
  int t;
  t = *p1;
  *p1 = *p2;
  *p2 = t;
  printf("%d, %d\n", *p1, *p2);
}

/*Resposta:
Antes: 1, 4;
Depois: 4 , 1;*/