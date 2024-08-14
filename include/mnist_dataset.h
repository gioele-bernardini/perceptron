// Inclusion Guards
#ifndef MNIST_FILE_H_
#define MNIST_FILE_H_

#include <stdint.h>

// Magic numbers to identify MNIST label and image files
#define MNIST_LABEL_MAGIC 0x00000801  // Magic number for label files
#define MNIST_IMAGE_MAGIC 0x00000803  // Magic number for image files

// Image dimensions in the MNIST dataset
#define MNIST_IMAGE_WIDTH 28
#define MNIST_IMAGE_HEIGHT 28
#define MNIST_IMAGE_SIZE (MNIST_IMAGE_WIDTH * MNIST_IMAGE_HEIGHT)  // Total number of pixels in an image

// Number of unique labels in MNIST (digits 0-9)
#define MNIST_LABELS 10

// Structure to hold the header of a label file
typedef struct mnist_label_file_header_t_ {
    uint32_t magic_number;       // Magic number for verification
    uint32_t number_of_labels;   // Number of labels in the file
} __attribute__((packed)) mnist_label_file_header_t;

// Structure to hold the header of an image file
typedef struct mnist_image_file_header_t_ {
    uint32_t magic_number;       // Magic number for verification
    uint32_t number_of_images;   // Number of images in the file
    uint32_t number_of_rows;     // Number of rows per image (typically 28)
    uint32_t number_of_columns;  // Number of columns per image (typically 28)
} __attribute__((packed)) mnist_image_file_header_t;

// Structure to hold a single image's pixel data
typedef struct mnist_image_t_ {
    uint8_t pixels[MNIST_IMAGE_SIZE];  // Array of pixel values (size 28x28)
} __attribute__((packed)) mnist_image_t;

// Structure to represent an MNIST dataset
typedef struct mnist_dataset_t_ {
    mnist_image_t * images;  // Pointer to an array of images
    uint8_t * labels;        // Pointer to an array of labels
    uint32_t size;           // Number of images/labels in the dataset
} mnist_dataset_t;

// Function prototypes for working with the MNIST dataset

// Load the MNIST dataset from image and label files
mnist_dataset_t * mnist_get_dataset(const char * image_path, const char * label_path);

// Free the memory allocated for the MNIST dataset
void mnist_free_dataset(mnist_dataset_t * dataset);

// Extract a batch of data from the MNIST dataset
int mnist_batch(mnist_dataset_t * dataset, mnist_dataset_t * batch, int batch_size, int batch_number);

#endif  // MNIST_FILE_H_

