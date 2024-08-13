#ifndef MNIST_FILE_H
#define MNIST_FILE_H

#include <cstdint>
#include <stdint.h>

#define MNIST_LABEL_MAGIC 0x00000801
#define MNIST_IMAGE_MAGIC 0x00000803
#define MNIST_IMAGE_WIDTH 28
#define MNIST_IMAGE_HEIGHT 28
#define MNIST_IMAGE_SIZE (MNIST_IMAGE_WIDTH * MNIST_IMAGE_HEIGHT)
#define MNIST_LABELS 10

typedef struct mnist_label_file_header_t_ {
  uint32_t 
}

