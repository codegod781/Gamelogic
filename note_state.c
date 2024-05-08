// note_state.c
#include "note_state.h"
#include <stdio.h>

void set_note(NoteState *note_state, const char *binary_string) {
    if (note_state == NULL || binary_string == NULL) {
        return; // Error handling: Ensure note_state and binary_string are not NULL
    }

    // Convert the binary string to integer values
    int green = binary_string[0] - '0';
    int red = binary_string[1] - '0';
    int yellow = binary_string[2] - '0';
    int blue = binary_string[3] - '0';
    int orange = binary_string[4] - '0';
    int strum = binary_string[5] - '0';

    // Assign the values to the struct fields
    note_state->green = green;
    note_state->red = red;
    note_state->yellow = yellow;
    note_state->blue = blue;
    note_state->orange = orange;
    note_state->strum = strum;
}

void print_note_state(const NoteState *note_state) {
    if (note_state == NULL) {
        return; // Error handling: Ensure note_state is not NULL
    }

    printf("Green: %d\n", note_state->green);
    printf("Red: %d\n", note_state->red);
    printf("Yellow: %d\n", note_state->yellow);
    printf("Blue: %d\n", note_state->blue);
    printf("Orange: %d\n", note_state->orange);
    printf("Strum: %d\n", note_state->strum);
}