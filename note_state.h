// note_state.h
#ifndef NOTE_STATE_H
#define NOTE_STATE_H

#include <stdbool.h>

// Define struct to store note state
typedef struct {
    bool green;    // Represents whether the green note is being input (true or false)
    bool red;      // Represents whether the red note is being input (true or false)
    bool yellow;   // Represents whether the yellow note is being input (true or false)
    bool blue;     // Represents whether the blue note is being input (true or false)
    bool orange;   // Represents whether the orange note is being input (true or false)
    bool strum;    // Represents whether the strum note is being input (true or false)
    // Add any other necessary fields to represent the state of the note
} NoteState;

#endif
