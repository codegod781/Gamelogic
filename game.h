// game.h
#ifndef GAME_H
#define GAME_H

// Define game states
typedef enum {
    RUNNING,
    PAUSED,
    BETWEEN_GAMES
} GameState;

// Define functions
void initialize_game();
void start_game();
void pause_game();
void resume_game();
void end_game();
void read_note_state(int note);

#endif
