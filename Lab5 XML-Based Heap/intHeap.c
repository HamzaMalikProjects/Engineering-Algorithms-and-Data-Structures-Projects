/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
#include <stdio.h>

// Declaring a static array to represent the heap of size 101.
static int heap[101];

// This integer tracks the current size of the heap.
static int size = 0;
// Function to get the parent index of a given node in the heap.
int parent(int i) { return i / 2; }
// Function to get the left child index of a given node in the heap.
int left(int i) { return 2 * i; }
// Function to get the right child index of a given node in the heap.
int right(int i) { return 2 * i + 1; }

// Function to swap two elements in the heap.
void swap(int i, int j)
{
  int temp = heap[i];  // Storing the value at index i in a temporary variable. 
  heap[i] = heap[j];   // Assigning the value at index j to index i.
  heap[j] = temp;   // Assigning the stored value in temp to index j.

}

// Function to adjust the heap structure to ensure max heap property is maintained.
void maxHeapify(int i)
{
  int largest; // Variable to track the largest value between a 
  int l = left(i);  // Get the left child index.
  int r = right(i);  // Get the right child index.

// Checking if left child exists and if it's greater than current element.
  if (l <= size && heap[l] > heap[i])
    largest = l;
  else
    largest = i;

  // Checking if right child exists and if it's greater than the largest of current and left child.
  if (r <= size && heap[r] > heap[largest])
    largest = r;

 // If the largest element isn't the current element, swap them and recurse on the largest child.
  if (largest != i) {
    swap(i, largest);
    maxHeapify(largest);
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
// If the heap is empty, print an error message and return -1.
  if (size < 1) {
    fprintf(stderr, "Error: Heap underflow.\n");
    return -1;
  }
  int max_val = heap[1]; // The largest element is at the root of the max 
  heap[1] = heap[size]; // Replace the root with the last element in the heap.

  size--;  // Decrease the size of the heap by 1.
  maxHeapify(1); // Restore the max heap property for the root.

  return max_val; // Return the largest element.
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  size++; // Increase the size of the heap.
  int i = size;  // Index where the new element will be placed
  heap[i] = thing2add;  // Place the new element at the end of the heap.

 // While the added element is greater than its parent, swap them. This loop ensures the max heap property is maintained.
  while (i > 1 && heap[parent(i)] < heap[i]) {
    swap(i, parent(i));
    i = parent(i);
  }
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}
