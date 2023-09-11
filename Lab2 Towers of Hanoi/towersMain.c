// Overview:
// This C program implements the Towers of Hanoi puzzle, a classic mathematical problem.
// The puzzle involves moving a tower of disks from one position to another following specific rules:
// 1. Only one disk can be moved at a time.
// 2. A larger disk cannot be placed on top of a smaller disk.
// The user can specify the number of disks (n), the starting position (from), and the target position (dest) as command-line arguments.
// If no arguments are provided, the default values for n, from, and dest are 3, 1, and 2, respectively.

#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;      // Default number of disks
    int from = 1;   // Default starting position
    int dest = 2;   // Default target position

    // Check if any command-line arguments are provided (greater than 1).
    if (argc > 1) {
        n = atoi(argv[1]);  // Convert the first argument to an integer and set it as the number of disks.

        // Validate the provided arguments.
        if (from > 3 || from < 1 || dest > 3 || dest < 1 || from == dest || n < 1) {
            printf("Invalid input. Positions should be between 1 and 3, and 'from' and 'dest' should be different. Number of disks should be positive.");
            exit(1);
        }
    }

    // Check if exactly one command-line argument is provided.
    if (argc == 2) {
        n = atoi(argv[1]);  // Convert the first argument to an integer and set it as the number of disks.

        // Validate the provided arguments.
        if (from > 3 || from < 1 || dest > 3 || dest < 1 || from == dest || n < 1) {
            printf("Invalid input. Positions should be between 1 and 3, and 'from' and 'dest' should be different. Number of disks should be positive.");
            exit(1);
        }
    }

    // Check if at least three command-line arguments are provided.
    else if (argc >= 3) {
        n = atoi(argv[1]);   // Convert the first argument to an integer and set it as the number of disks.
        from = atoi(argv[2]);  // Convert the second argument to an integer and set it as the starting position.
        dest = atoi(argv[3]);  // Convert the third argument to an integer and set it as the target position.

        // Validate the provided arguments.
        if (from > 3 || from < 1 || dest > 3 || dest < 1 || from == dest || n < 1) {
            printf("Invalid input. Positions should be between 1 and 3, and 'from' and 'dest' should be different. Number of disks should be positive.");
            exit(1);
        }
    }

    // Call the towers function with the specified number of disks, starting position, and target position.
    towers(n, from, dest);

    exit(0);  // Exit the program with a successful status code.
}
