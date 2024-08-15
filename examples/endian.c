#include <stdio.h>

int main() {
    unsigned int x = 1;
    // Create a pointer to the first byte of 'x' by casting the address of 'x' to a char pointer
    char *c = (char*)&x;

    // Check the value at the first byte of 'x' to determine endianness
    // If the system is Little Endian, the least significant byte (LSB) is stored first,
    // and *c will be 1. Otherwise, it is a Big Endian system, and *c will be 0.
    if (*c) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    return 0;
}

