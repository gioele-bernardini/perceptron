cmake_minimum_required(VERSION 3.0)
project(mnist-c)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add the library
add_library(mnist-lib
  src/mnist_dataset.c
  src/neural_network.c
)

# Add the executable
add_executable(mnist
  src/main.c
)

# Link the executable with the library and the math library
target_link_libraries(mnist mnist-lib m)
target_link_libraries(mnist-lib m)

# Enable testing
enable_testing()

# Add the tests directory if necessary
# add_subdirectory(tests)

