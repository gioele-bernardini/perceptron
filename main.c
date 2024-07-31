#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// training set - input, output
float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8},
};

float rand_float(void) {
  return (float) rand() / (float) RAND_MAX;
}

int main() {
  // srand(time(0));
  srand(42);
  // y = x*w;
  float w = rand_float();

  printf("%f\n", w);

  return 0;
}

