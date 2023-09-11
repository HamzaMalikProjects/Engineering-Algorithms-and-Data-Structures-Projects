#include "mySort.h" // Include the header file that contains function declarations.

// Function to sort an integer array using the insertion sort algorithm.
// Parameters:
//   array: Pointer to the integer array to be sorted.
//   first: The starting index of the range to be sorted.
//   last: The ending index of the range to be sorted.
void mySort(int array[], unsigned int first, unsigned int last) {
    int i, j, key;

    // Iterate over the array elements within the specified range [first, last].
    for (i = first; i <= last; i++) {

        // Make a copy of the current element at index 'i'.
	//mycopy makes a copy from one location to another	
        myCopy(&array[i], &key);
	

        // Find the correct position for 'key' in the sorted part of the array.
	//Sets index j 1 less then i so if i = 2 then j = -1
        j = i - 1; 

        // Shift elements greater than 'key' to the right.
        // Loop runs as long as 'j' is greater than or equal to 0 and the value at index 'j' is greater than 'key'.
        while (j >= 0 && myCompare(array[j], key) > 0) {
            mySwap(&array[j + 1], &array[j]); // Swap the elements to make space for 'key'.
            j--; // Move 'j' one index to the left.
        }

        array[j + 1] = key; // Insert 'key' into its correct sorted position.
    }
}

/* Overview of Insertion Sort:
- The 'mySort' function implements the insertion sort algorithm to sort a given integer array within the specified range.
- The function starts by making a copy of the current element to be inserted into the sorted part of the array.
- It then compares the copied element ('key') with the elements in the sorted part of the array in reverse order (right-to-left).
- If an element is greater than 'key', it is shifted one position to the right.
- This process continues until the correct position for 'key' is found, and then it is inserted there.
- The 'myCopy', 'myCompare', and 'mySwap' functions are used to manage copying, comparing, and swapping operations, respectively.
- The function ensures that the specified range of the array is sorted in ascending order when the sorting process is complete.
*/
