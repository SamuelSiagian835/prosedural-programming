#include <stdio.h>
 
int main(int argc, char **argv)
{
  unsigned short s = 100;
  unsigned short *ps;
  ps = &s;
  printf("%d|%p|%p", s, &s, &ps);
}