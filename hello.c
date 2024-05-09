/*
 * Userspace program that communicates with the vga_ball device driver
 * through ioctls
 *
 * Stephen A. Edwards
 * Columbia University
 */

#include <stdio.h>
#include "note_reader.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "package_note.h"
#include "note_state.h"

#define BUFFER_SIZE 10
#define MAX_ROW_LENGTH 9  // Including null terminator for 8-bit binary number

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
char buffer[BUFFER_SIZE];
char expected_note_buffer[BUFFER_SIZE];
int buffer_index = 0;
int expected_note_buffer_index = 0;

int notes_fd;



//Call to kernel
char* read_note() {
    printf("call to kernel\n");
    int arg;
    
    if (ioctl(notes_fd, VGA_BALL_READ_BACKGROUND, &arg)) {
        perror("ioctl(VGA_BALL_READ_BACKGROUND) failed");
    }
    printf("chunk  = %02x\n", arg);

    // Static buffer to hold the string (two characters + null terminator)
    static char result_string[3];

    // Convert the integer value to a two-digit hexadecimal string
    snprintf(result_string, 3, "%02x", arg);

    printf("string  = %s\n", result_string);

    return result_string;

}


// Function to generate a random hexadecimal character
//used to simulate controller input
char* generate_random_hex() {
    const char hex_chars[] = "0123456789ABCDEF";
    static char hex_number[3]; // Static array to hold the generated hex number

    hex_number[0] = hex_chars[rand() % 16]; // First digit
    hex_number[1] = hex_chars[rand() % 16]; // Second digit
    hex_number[2] = '\0'; // Null terminator

    return hex_number;
}


// Function to generate a random hexadecimal and add it to the buffer
void *read_and_buffer_input(void *arg) {
    for (int i = 0 ; i < 20 ; i++) {
        
        char *random_hex = read_note();

        printf("random hex: %s\n", random_hex);

        char *binary_string = hex_string_to_binary(random_hex);

        printf("Binary: %s\n", binary_string);


        NoteState note;
        set_note_guitar(&note, binary_string);
        print_note_state(&note);


        pthread_mutex_lock(&buffer_mutex);
        if (buffer_index < BUFFER_SIZE) {
            buffer[buffer_index++] = *random_hex;
            // printf("Generated random hex: %c, Buffer: %s\n", random_hex, buffer);
        }
        pthread_mutex_unlock(&buffer_mutex);

        usleep(400000); // Sleep for 40000 microseconds

    }
    return NULL;
}





//This opens and reads in the reference file for the song Baracuda
void process_note_file(const char *filename) {
    printf("process");
    char line[9]; // Buffer to store each line (8 characters + null terminator)
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline character if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) == 8) {
            printf("note: %s\n", line);

            //NEEDS TO APPEND TO BUFFER

            else {
                printf("Buffer overflow. Cannot read more lines.\n");
                break;
            }
        }

    } 
    
    fclose(file);
}






int main()
{
  int i;
  static const char filename[] = "/dev/notes";
  pthread_t tid;
  const char *expected_note_file = "single_note_comaless.txt";
  
  process_note_file(expected_note_file); 


  if ( (notes_fd = open(filename, O_RDWR)) == -1) {
    fprintf(stderr, "could not open %s\n", filename);
    return -1;
  }


  printf("Welcome to guitar hero\n");
  // Seed the random number generator
  
  srand(time(NULL)); 

  // Create thread
  if (pthread_create(&tid, NULL, read_and_buffer_input, NULL) != 0) {
      fprintf(stderr, "Error creating thread\n");
      return 1;
  }


  pthread_join(tid, NULL);

  
  printf("VGA BALL Userspace program terminating\n");
  return 0;
}
