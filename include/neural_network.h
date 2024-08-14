#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

#include "mnist_dataset.h"

// Structure representing a neural network
typedef struct neural_network_t_ {
  float b[MNIST_LABELS]; // Bias vector, one for each output class (10 for MNIST digits 0-9)
  float W[MNIST_LABELS][MNIST_IMAGE_SIZE]; // Weight matrix, connecting input pixels to each output class
} neural_network_t;

// Structure representing the gradient of a neural network's parameters
typedef struct neural_network_gradient_t_ {
  float b_grad[MNIST_LABELS]; // Gradient of the bias vector
  float W_grad[MNIST_LABELS][MNIST_IMAGE_SIZE]; // Gradient of the weight matrix
} neural_network_gradient_t;

// Function to initialize the network's weights and biases randomly
void neural_network_random_weights(neural_network_t * network);

// Function to compute the network's output given an input image (forward pass)
void neural_network_hypothesis(mnist_image_t * image, neural_network_t * network, float activations[MNIST_LABELS]);

// Function to calculate the gradient for a given input image and update the gradient structure
// Returns the loss value for the given input image and label
float neural_network_gradient_update(mnist_image_t * image, neural_network_t * network, neural_network_gradient_t * gradient, uint8_t label);

// Function to perform a single training step on the entire dataset (or batch)
// Updates the network's parameters using the calculated gradients
// Returns the average loss over the dataset
float neural_network_training_step(mnist_dataset_t * dataset, neural_network_t * network, float learning_rate);

#endif

// Example Usage
/*
int main() {
  // Load the MNIST dataset
  mnist_dataset_t *dataset = mnist_load("path_to_mnist_data");

  // Initialize the neural network
  neural_network_t network;
  neural_network_random_weights(&network);  // Randomly initialize weights and biases

  // Set learning rate
  float learning_rate = 0.01f;

  // Train the network for a certain number of epochs
  for (int epoch = 0; epoch < 10; epoch++) {
    float avg_loss = neural_network_training_step(dataset, &network, learning_rate);
    printf("Epoch %d, Average Loss: %f\n", epoch, avg_loss);
  }

  // After training, you can use the network to predict new inputs
  mnist_image_t *test_image = ...; // Load or provide a test image
  float activations[MNIST_LABELS];
  neural_network_hypothesis(test_image, &network, activations);

  // The activations array now contains the network's predictions for the test image

  // Cleanup
  mnist_free(dataset);
  return 0;
}
*/

