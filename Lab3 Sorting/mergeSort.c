#include "mySort.h"

// Function to merge two sorted subarrays into a single sorted array. 
void merge(int arr[], int a1, int b1, int a2, int b2) {
    int temp[MAX_SIZE_N_TO_SORT]; // Creates a temporary array to store the merged elements.
    int c = a1, d = a2, e = 0; // Initializes index variables for the two subarrays and the temporary array.

    // Merges the two subarrays into the temporary array in sorted order.
    while (c <= b1 && d <= b2) {
        // Compare elements in the two subarrays.
        if (myCompare(arr[c], arr[d]) < 0)
            temp[e++] = arr[c++]; // Copies the smaller element from the first subarray.
        else
            temp[e++] = arr[d++]; // Copies the smaller element from the second subarray.
    }

    // Copies any remaining elements from the first subarray, if there are any.
    while (c <= b1)
        myCopy(&arr[c++], &temp[e++]);

    // Copies any remaining elements from the second subarray, if there are any.
    while (d <= b2)
        myCopy(&arr[d++], &temp[e++]);

    // Copies the merged elements from the temporary array back to the original array.
    for (c = a1, e = 0; c <= b2; c++, e++)
        mySwap(&arr[c], &temp[e]);
}

// Function to implement the merge sort algorithm.
void mySort(int array[], unsigned int first, unsigned int last) {
    int middle;

    // If there is more than one element in the array, continue to split it into smaller arrays.
    if (first < last) {
        // Find the middle index of the current subarray.
        middle = (first + last) / 2;

        // Recursively sort the left half of the array.
        mySort(array, first, middle);

        // Recursively sort the right half of the array.
        mySort(array, middle + 1, last);

        // Merge the sorted halves.
        merge(array, first, middle, middle + 1, last);
    }
}

