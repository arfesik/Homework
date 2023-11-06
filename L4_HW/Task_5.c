#include <stdio.h>
int main()
{
  int a = 12;
  int b = 7;
  
  printf("%d\n", a);
  printf("%d\n", b);

  a = a + b;
  b = b - a;
  b = -b;
  a = a - b;
  
  printf("%d\n", a);
  printf("%d\n", b);
  
  return 0;
}


