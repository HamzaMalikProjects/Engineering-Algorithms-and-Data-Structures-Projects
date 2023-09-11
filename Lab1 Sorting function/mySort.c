// Insertion sort
void mySort(int d[], unsigned int n)
{
    int i, j, temp_var;

    // Iterate over the array starting from the second element
    for (i = 1; i < n; i++) {
        temp_var = d[i];  // Stores the current element in a temporary variable
        j = i - 1;  // Initialize the index for comparison

        // Compares the current element with previous elements and shift them if necessary
        while (j >= 0 && d[j] > temp_var) {
            d[j + 1] = d[j];  // Shift the element to the right
            j = j - 1;  // Move to the previous element
        }

        d[j + 1] = temp_var;  // Places the current element in its correct position
    }
}

