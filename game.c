// game.c
#include <stdio.h>
#include "game.h"

// Global variable to hold the current game state
GameState current_state = BETWEEN_GAMES;

void initialize_game() {
    // Initialize game state and any necessary variables
    current_state = BETWEEN_GAMES;
}

void start_game() {
    // Start the game
    current_state = RUNNING;
    printf("Game started!\n");
}

void pause_game() {
    // Pause the game
    current_state = PAUSED;
    printf("Game paused.\n");
}

void resume_game() {
    // Resume the game
    current_state = RUNNING;
    printf("Game resumed!\n");
}

void end_game() {
    // End the game
    current_state = BETWEEN_GAMES;
    printf("Game ended.\n");
}

void read_note_state(int note) {
    // Read the state of the note and perform actions based on the game state
    if (current_state == RUNNING) {
        // Check if the right note is being input
        // Perform actions based on the input note
        printf("Note %d is being input.\n", note);
    } else {
        printf("Game is not running. Ignoring input.\n");
    }
}
