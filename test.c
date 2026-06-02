#include <stdio.h>
#include <math.h>

int main(void)
{
  double x = 5;
  double y = 0;

  printf("Number: ");
  scanf("%lf", &x);

  y = sin(x);

  printf("y == %f\n", y);

  return 0;
}