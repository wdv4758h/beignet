#include "stdlib.h"
struct big{
  unsigned int a, b;
};

__kernel void add(__global struct big *b, unsigned int x, unsigned int y)
{
  b->a = x + y;
  b->b = x - y + 10;
}


