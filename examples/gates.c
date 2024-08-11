// gcc {filename} -lm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define train_count (sizeof(train) / sizeof(train[0]))

// Training set: input values (x1, x2) and the corresponding target output
// OR-gate
float train[][3] = {
  {0, 0, 0},
  {1, 0, 1},
  {0, 1, 1},
  {1, 1, 0},
};

// An activation function to "squeeze" the raw value of the neuron
float sigmoid(float x) {
  return 1.f / (1.f + expf(-x));
}

// Function to calculate the cost (mean squared error)
float cost(float w1, float w2) {
  float result = 0.0f;

  // Loop over the entire training set
  for (size_t i = 0; i < train_count; i++) {
    float x1 = train[i][0];
    float x2 = train[i][1];

    // Compute the predicted output based on current weights
    float y = x1 * w1 + x2 * w2;
    // Later we'll be using the activation function here
    // float y = sigmoidf(x1*w1 + x2*w2);

    // Calculate the difference (error) between the predicted and actual output
    float d = y - train[i][2];

    // Accumulate the squared error
    result += d * d;
  }

  // Average the error over all training samples
  result /= train_count;
  return result;
}

// Generate a random float between 0 and 1
float rand_float(void) {
  return (float) rand() / (float) RAND_MAX;
}

int main(void) {
  srand(69); // Seed for reproducibility

  // Initialize weights with random values
  float w1 = rand_float();
  float w2 = rand_float();

  // Hyperparameters
  float eps = 1e-3; // Small perturbation for numerical gradient approximation
  float rate = 1e-3; // Learning rate: controls the step size

  // Gradient descent iteration
  for (size_t i = 0; i < 2; i++) { // In practice, we'd use many more iterations
    float c = cost(w1, w2);
    printf("w1: %f, w2: %f, c: %f\n", w1, w2, c);

    // Calculate the numerical partial derivative with respect to w1
    float dw1 = (cost(w1 + eps, w2) - c) / eps;
    // Calculate the numerical partial derivative with respect to w2
    float dw2 = (cost(w1, w2 + eps) - c) / eps;

    // Update the weights by moving in the direction opposite to the gradient
    // This decreases the cost, hence moving towards the minimum
    w1 -= rate * dw1;
    w2 -= rate * dw2;
  }

  return 0;
}

