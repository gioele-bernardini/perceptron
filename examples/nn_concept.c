// A neural network looks like below
// Given a set of input and a set of weights:
// x1, x2, x3 ... xn ... b (bias!)
// w1, w2, w3 ... wn
// The computation will be the following:
// x1*w1 + x2*w2 + x3*w3 + b
// The Bias modifies the activation threshold

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the training set with input and expected output values
#define train_count (sizeof(train) / sizeof(train[0]))

float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8},
};

// Function to generate a random float between 0 and 1
float rand_float(void) {
  return (float) rand() / (float) RAND_MAX;
}

// Loss function calculates the mean squared error between the predicted and actual outputs
float loss_function(float weight, float bias) {
  float result = 0.0f;

  for (size_t i = 0; i < train_count; i++) {
    float x = train[i][0];
    float y = x * weight + bias;  // Include bias in the prediction
    float d = y - train[i][1];

    result += d * d;
  }

  result /= train_count;  // Mean squared error
  return result;
}

int main() {
  srand(42);  // Seed the random number generator for reproducibility

  // Initialize weight and bias with random values
  float w = rand_float() * 10.0f;  // Random starting weight
  float b = rand_float() * 10.0f;  // Random starting bias

  float eps = 1e-3;  // Small value for calculating numerical derivative
  float rate = 1e-3;  // Learning rate

  // Calculate the derivative of the loss function with respect to weight and bias
  float dcost_dw = (loss_function(w + eps, b) - loss_function(w, b)) / eps;  // Derivative w.r.t. weight
  float dcost_db = (loss_function(w, b + eps) - loss_function(w, b)) / eps;  // Derivative w.r.t. bias

  // Output the initial loss
  printf("Initial loss: %f\n", loss_function(w, b));

  // Update weight and bias using gradient descent
  w -= rate * dcost_dw;
  b -= rate * dcost_db;

  // Output the updated loss
  printf("Updated loss: %f\n", loss_function(w, b));

  return 0;
}

