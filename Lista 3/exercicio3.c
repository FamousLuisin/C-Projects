#include <stdio.h>

int main()
{
  int x = 2;
  int y = 8;

  int *p;
  int *q;

  p = &x;
  q = &y;


  printf("valor x: %d|| endereco x:  %p\n", x, &x);
  printf("valor x: %d|| endereco x:  %p\n", y, &y);
  printf("valor p: %d|| valor *p:  %p\n", p, *p);
  printf("valor q: %d|| valor *q:  %p\n", q, *q);
  printf("endereco p:  %p\n", &p);
  printf("endereco q:  %p\n", &q);


  return 0;
}