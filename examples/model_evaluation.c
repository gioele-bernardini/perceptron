#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define train_count (sizeof(train) / sizeof(train[0]))

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
  float w = rand_float() * 10.0f;
  

  float eps = 1e-3;

  float result = 0;

  for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = x * w;

    // Define a way to measure the difference between the actual value and the expected one
    float d = y - train[i][1];
    result += d * d;

    printf("Actual: %f, expected: %f\n", y, train[i][1]);
  }

  result /= train_count;

  printf("%f\n", result);

  return 0;
}

