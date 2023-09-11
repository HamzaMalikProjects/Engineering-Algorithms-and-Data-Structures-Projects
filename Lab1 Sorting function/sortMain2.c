// Basically sortMain.c just with command line arguments 
#include <stdio.h>              
#include <stdlib.h>             
#include "mySort.h"             

int main(int argc, char* argv[]) {

    int data[100000];           // Array to store integers for sorting
    int nDataItems;             // Number of elements in the array
    int i;                      // Loop counter variable
    static int j = 0;           // Counter for the number of elements added to the data array

    if (argc > 1) {             // Checks if command line arguments are present

        fprintf(stderr, "Command line arguments detected:\n");  // Prints a message to indicate command line arguments are provided
        for (i = 1; i < argc; i++) {
            data[j] = atoi(argv[i]);  // Converts each command-line argument to an integer and stores it in the data array
            j++;
        }
    } else {

        fprintf(stderr, "No command line arguments found.\n");  // Print a message to indicate no command line arguments are provided
    }

    /* Test data */
    nDataItems = j;             // Set the number of data items to the number of elements added to the data array

    mySort(data, nDataItems);   // Sort the data array using the mySort function

    /* Verify the sorted order of the data array */
    for (i = 0; i < nDataItems - 1; i++) {

        if (data[i] > data[i + 1]) {

            fprintf(stderr, "Sorting error: data[%d] (= %d) should be <= data[%d] (= %d) - Aborting\n",
                    i, data[i], i + 1, data[i + 1]);
            exit(1);           // Exit the program with a status code of 1 to indicate a sorting error
        }
    }

    /* Print the sorted array */
    for (i = 0; i < nDataItems; i++) {
        
        printf("%d\n", data[i]);  // Print each element of the sorted array on a new line
    }

    exit(0);                    // Exit the program with a status code of 0 to indicate successful execution
}

