#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declare external functions
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
  int value;
  int descending_values[100];   // Declare an array to store descending values
  int descending_index = 0;    // Declare and initialize index to 0

  // Read integers from standard input and add them to the heap
  while (scanf("%d\n", &value) != EOF) {
    addHeap(value);            // Call addHeap function to add values to heap
  }

  // Extract the maximum value from the heap and store it in descending_values array
  int first_max_val = heapDelete();
  descending_values[descending_index++] = first_max_val;

  // Print the ID of the maximum value node in XML format
  printf("<node id=\"%d\">", first_max_val);

  // Push the maximum value onto the stack
  push(first_max_val);

  // Extract the remaining maximum values from the heap
  while (heapSize() > 0) {
    int max_val = heapDelete();
    descending_values[descending_index++] = max_val;

    // Print the ID of the maximum value node in XML format
    printf("<node id=\"%d\"></node>", max_val);

    // Push the maximum value onto the stack
    push(max_val);
  }

  // Close the root node tag in XML format
  printf("</node>\n");

  // Print sorted numbers in descending order
  for (int i = 0; i < descending_index; i++) {
    printf("%d\n", descending_values[i]);
  }

  // Print sorted numbers in ascending order
  while (!isEmpty()) {
    printf("%d\n", pop());
  }

  // Exit the program with a status code of 0
  exit(0);
}
