cmake_minimum_required(VERSION 3.0)
project(mnist)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add the library
add_library(mnist-lib
  
)

# Add the executable
add_executable(mnist
  src/main.cpp
)

# Link the executable with the library
# Tell to link the library with the executable
target_link_libraries(essential-MLP essential-MLP-lib)

# Enable testing
enable_testing()

# Add the tests directory if necessary
# add_subdirectory(tests)

