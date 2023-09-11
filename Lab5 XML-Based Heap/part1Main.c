#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the maximum length of a tag identity
#define MAX_TAG_LENGTH 100

// Declare the Stack functions
extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[]) {
    int ch, tagIndex = 0;
    int inTag = 0, inEndTag = 0;
    char tag[MAX_TAG_LENGTH + 1]; // Allow space for null terminator

    // Loop through each character in the input
    while ((ch = getchar()) != EOF) {
        // Ignore any characters that are not part of a tag
        if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')) {
            continue;
        }

        // Check if the current character starts a tag
        if (ch == '<') {
            inTag = 1; // Flag that we are in a tag
            inEndTag = 0;
            tagIndex = 0; // Reset the index for the tag identity
        }
        // Check if the current character ends a tag
        else if (ch == '>') {
            tag[tagIndex] = '\0'; // Add a null terminator to the end of the tag identity
            if (inEndTag) { // If this is an end-tag
                char *startTagIdentity = pop(); // Pop the start-tag identity from the stack
                if (startTagIdentity == NULL || strncmp(tag, startTagIdentity, MAX_TAG_LENGTH + 1) != 0) {
                    printf("The XML expression is invalid.\n");
                    return 1; // Stop the program
                }
            }
            else { // If this is a start-tag
                push(strdup(tag)); // Push the tag identity onto the stack
            }
            inTag = 0; // Flag that we are no longer in a tag
            inEndTag = 0;
        }
        // Check if the current character indicates an end-tag
        else if (ch == '/' && inTag) {
            inEndTag = 1;
        }
        // If the current character is part of a tag identity
        else if (isalpha(ch)) {
            // If the tag identity is too long, terminate the program
            if (tagIndex >= MAX_TAG_LENGTH) {
                printf("The XML expression is invalid.\n");
                return 1;
            }
            tag[tagIndex++] = ch; // Add the character to the tag identity
        }
    }

    if (isEmpty()) { // Check if the stack is empty
        printf("The XML expression is valid.\n");
    }
    else {
        printf("The XML expression is invalid.\n");
        return 1; // Stop the program
    }

    return 0; // Exit the program successfully
}
