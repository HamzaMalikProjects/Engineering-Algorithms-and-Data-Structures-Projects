#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_STATES 8

// State struct
typedef struct State {
    char name;  // name of the state (A-H)
    int next_states[2];  // index of next state for input 0 and input 1 respectively
    bool is_deleted;  // flag to indicate if the state is deleted or not
} State;

// Global state machine array
State state_machine[NUM_STATES];

// Global variable to store the current state index
int current_state_index = 0;

// Initialize the state machine
void initialize() {
    state_machine[0] = (State) {'A', {5, 6}, false};
    state_machine[1] = (State) {'B', {4, 2}, false};
    state_machine[2] = (State) {'C', {2, 0}, false};
    state_machine[3] = (State) {'D', {6, 4}, false};
    state_machine[4] = (State) {'E', {1, 7}, false};
    state_machine[5] = (State) {'F', {7, 3}, false};
    state_machine[6] = (State) {'G', {5, 1}, false};
    state_machine[7] = (State) {'H', {2, 3}, false};
}

// Function that returns the next state index based on the given input (0 or 1).
int get_next_state_index(int input) {
    // Access the current state's next state for the given input.
    return state_machine[current_state_index].next_states[input];
}

// Update the global current state index based on the given input.
void update_current_state(int input) {
    // Fetch the index of the next state based on the input.
    int next_state_index = get_next_state_index(input);

    // If the next state is deleted, print an error and exit the function.
    while (state_machine[next_state_index].is_deleted) {
        printf("State deleted cannot be accessed\n");
        return;
    }
    
    // Update the global current state index to the next state index.
    current_state_index = next_state_index;
}

// Recursive function to check if a state is reachable from the current state.
bool is_reachable(int state_index, bool visited[]) {
    // Return false if the state has been deleted.
    if (state_machine[state_index].is_deleted) {
        return false;
    }
    
    // Mark the current state as visited.
    visited[state_index] = true;
    
    // Loop over possible transitions (0 and 1).
    for (int i = 0; i < 2; i++) {
        int next_state_index = state_machine[state_index].next_states[i];
        // Recursively check the next state if it hasn't been visited or deleted.
        if (!visited[next_state_index] && !state_machine[next_state_index].is_deleted) {
            if (is_reachable(next_state_index, visited)) {
                return true;
            }
        }
    }

    // If no path was found, return false.
    return false;
}

// Change the state transition for a given input value (0 or 1).
void change_state(char state_name, int input_value) {
    // Convert state name to index (assuming 'A' to 'Z' mapping).
    int state_index = state_name - 'A';
    
    // Validate if the state name is within the expected range.
    if (state_index < 0 || state_index >= NUM_STATES) {
        printf("Invalid state name.\n");
        return;
    }
    
    // Update the transition for the current state based on the input value.
    state_machine[current_state_index].next_states[input_value] = state_index;
}

// Display the current configuration of the state machine.
void print_state_machine() {
    printf("State machine configuration:\n");
    for (int i = 0; i < NUM_STATES; i++) {
        State state = state_machine[i];
        // Only show states that aren't deleted.
        if (!state.is_deleted) {
            printf("%c: %d %d\n", state.name, state.next_states[0], state.next_states[1]);
        }
    }
    printf("\n");
}

// Identify and print out unreachable states.
void identify_garbage() {
    // Initialize an array to track which states are visited.
    bool visited[NUM_STATES] = {false};
    is_reachable(current_state_index, visited);
    
    bool has_garbage = false;
    printf("Garbage (Unreachable States): ");
    for (int i = 0; i < NUM_STATES; i++) {
        // Print states that are not visited and not already deleted.
        if (!visited[i] && !state_machine[i].is_deleted) {
            printf(" %c ", state_machine[i].name);
            has_garbage = true;
        }
    }
    // If no unreachable states found, print a corresponding message.
    if (!has_garbage) {
        printf("No garbage");
    }
    printf("\n");
}

// Function to delete a state or all unreachable states based on the provided state_id.
void delete_state(State *sm, char state_id) {
    // If 'd' is passed as the state_id, delete all unreachable states.
    if (state_id == 'd') {
        bool visited[NUM_STATES] = {false};
        is_reachable(current_state_index, visited);
        
        bool any_deleted = false;
        for (int i = 0; i < NUM_STATES; i++) {
            // Mark states as deleted if they aren't visited and not already deleted.
            if (!visited[i] && !state_machine[i].is_deleted) {
                sm[i].is_deleted = true;
                any_deleted = true;
                printf("%c", sm[i].name);
            }
        }
        
        // Print out the result of the delete operation.
        if (any_deleted) {
            printf("\nDeleted all unreachable states.\n");
            update_current_state(0);
        } else {
            printf("No states deleted.\n");
        }
    } else {
        // If a specific state_id is given, delete it if it's not reachable.
        bool visited[NUM_STATES] = {false};
        bool any_deleted = false;
        
        for (int i = 0; i < NUM_STATES; i++) {
            if (sm[i].name == state_id && !is_reachable(i, visited)) {
                sm[i].is_deleted = true;
                any_deleted = true;
            }
        }
        
        // Provide feedback based on the delete operation.
        if (!any_deleted) {
            printf("Error: state with id %c not found or is reachable.\n", state_id);
        } else {
            update_current_state(0);
            is_reachable(current_state_index, visited);
        }
    }
}



int main() {
    // Initialize the state machine
    initialize();

    // Run the state machine
    char input;
    while (1) {
        printf("Current state: %c\n", state_machine[current_state_index].name);
        printf("Enter input (0 or 1) or command (g to identify garbage, c to change state, d to delete state, p to print state machine, q to quit): ");
        scanf(" %c", &input);

        switch (input) {
            case '0':
                update_current_state(0);
                break;
            case '1':
                update_current_state(1);
                break;
            case 'g':
                identify_garbage();
                break;
            case 'c': {
                char state_name;
                int input_value;
                printf("Enter state name (A-H): ");
                scanf(" %c", &state_name);
                printf("Enter input value (0 or 1): ");
                scanf("%d", &input_value);
                change_state(state_name, input_value);
                break;
            }
            case 'd': {
                char state_name;
                printf("Enter state name (A-H) to delete or enter 'd' again to delete all unreachable states: ");
                scanf(" %c", &state_name);
                delete_state(state_machine, state_name);
                break;
            }
            case 'p':
                print_state_machine();
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}




  

