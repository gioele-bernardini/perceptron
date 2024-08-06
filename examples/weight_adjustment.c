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

float loss_function(float weight) {
  float result = 0.0f;

  for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = x * weight;
    float d = y - train[i][1];

    result += d * d;
  }

  result /= train_count;
  return result;
}

int main() {
  // srand(time(0));
  srand(42);

  // y = x*w;
  float w = rand_float() * 10.0f;
  float eps = 1e-3;
  float rate = 1e-3;

  // We might calculate the derivative and then operate with that
  // That's literally the definition of Derivative!
  float dcost = (loss_function(w + eps) - loss_function(w)) / eps;

  printf("%f\n", loss_function(w));
  // w -= dcost;
  w -= rate * dcost;
  printf("%f\n", loss_function(w));

  return 0;
}

