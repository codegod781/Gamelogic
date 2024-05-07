// main.c
#include <stdio.h>
#include "game.h"

int main() {
    // Initialize the game
    initialize_game();

    // Start the game
    start_game();

    // Simulate reading notes
    read_note_state(1); // Simulated note input

    // Pause the game
    pause_game();

    // Resume the game
    resume_game();

    // Simulate reading notes again
    read_note_state(2); // Simulated note input

    // End the game
    end_game();

    return 0;
}
