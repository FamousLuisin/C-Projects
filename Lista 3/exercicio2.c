#include <stdio.h>

int main()
{
  int n1 = 0;
  float n2 = 1;
  char n3 = 'a';

  int *x;
  float *y;
  char *z;

  x = &n1;
  y = &n2;
  z = &n3;

  printf("memoria inteira: %p\n", x);
  printf("memoria flutuante: %p\n", y);
  printf("memoria char: %p\n", z);

  return 0;
}

/*
DIAGRAMA


0       |
1       |
2       |
3       |
4       |
5  n1   | valor: 0
6  n1   | valor: 0
7  n1   | valor: 0
8  n1   | valor: 0
9  n2   | valor: 1
10 n2   | valor: 1
11 n2   | valor: 1
12 n2   | valor: 1
13 n3   | valor: 'a'
14 n3   | valor: 'a'
15 n3   | valor: 'a'
16 n3   | valor: 'a'
18      |
19      |
20      |
21      |
22      |
23      |
24      |











*/
