#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <time.h>

int main() {
    // Calculate the size in bytes for 20 MB
    size_t size = 2 * 1024 * 1024; // 20 MB = 20 * 1024 * 1024 bytes

    // Allocate memory
    char *array = (char *)malloc(size);

    // Check if the memory allocation was successful
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit with an error code
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Fill the array with random values
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 256; // Generate a random byte value (0-255)
    }

    // printf("Memory allocation successful\n");


    // keep it running
    while(1) {
        sleep(10);
    }

    return 0;
}
