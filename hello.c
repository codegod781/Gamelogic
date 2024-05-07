/*
 * Userspace program that communicates with the vga_ball device driver
 * through ioctls
 *
 * Stephen A. Edwards
 * Columbia University
 */

#include <stdio.h>
// #include "vga_framebuffer.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int notes_fd;

/* Read and print the background color */
void read_note() {
  printf("call to kernel\n");
  int arg;
  
  if (ioctl(notes_fd, VGA_BALL_READ_BACKGROUND, &arg)) {
      perror("ioctl(VGA_BALL_READ_BACKGROUND) failed");
      return;
  }
  printf("chunk  = %02x\n", arg);
}


int main()
{
  vga_ball_arg_t vla;
  int i;
  static const char filename[] = "/dev/notes";


  printf("VGA ball Userspace program started\n");

  if ( (notes_fd = open(filename, O_RDWR)) == -1) {
    fprintf(stderr, "could not open %s\n", filename);
    return -1;
  }

  printf("initial state: ");
  read_note();

  for (i = 0 ; i < 24 ; i++) {
    printf("Hello...\n");
    read_note();
    usleep(400000);
  }
  
  printf("VGA BALL Userspace program terminating\n");
  return 0;
}
