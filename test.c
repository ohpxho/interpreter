#include <limits.h>
#include <stdio.h>

int main() {
  float v = -1.19921875f;
  float w = 123456.203125f;
  float x = 123456.187501f;
  float y = 2147483.123f;
  float z = 111.123456f;
  float addf = 0.1f + 0.2f;
  int e = INT_MAX;
  int f = INT_MAX;
  int emf = e * f;
  unsigned int b = UINT_MAX;
  unsigned int c = UINT_MAX;
  unsigned int bpc = b + c;
  unsigned int bmc = b * c;
  printf("v: %f\n", v);
  printf("w: %f\n", w);
  printf("x: %f\n", x);
  printf("y: %f\n", y);
  printf("z: %f\n", z);
  printf("addf: %f\n", addf);
  printf("e: %d\n", e);
  printf("f: %d\n", f);
  printf("b: %u\n", b);
  printf("c: %u\n", c);
  printf("bpc: %u\n", bpc);
  printf("bmc: %u\n", bmc);
  return 0;
}
