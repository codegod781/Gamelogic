// note_state.h
#ifndef NOTE_STATE_H
#define NOTE_STATE_H

#include <stdbool.h>

// Define struct to store note state
typedef struct {
    int green;    // Represents whether the green note is being input (true or false)
    int red;      // Represents whether the red note is being input (true or false)
    int yellow;   // Represents whether the yellow note is being input (true or false)
    int blue;     // Represents whether the blue note is being input (true or false)
    int orange;   // Represents whether the orange note is being input (true or false)
    int strum;    // Represents whether the strum note is being input (true or false)
    // Add any other necessary fields to represent the state of the note
} NoteState;

// Function to set note state from binary string
void set_note(NoteState *note_state, const char *binary_string);

// Function to print note state
void print_note_state(const NoteState *note_state);

#endif /* NOTE_STATE_H */
