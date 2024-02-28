#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/sound.h"

#define SOUND_CMD "aplay -q " // command line to play sound

void make_sound(const char *file_path) {
    size_t cmdline_size = strlen(SOUND_CMD) + strlen(file_path) + 1 ; // calculate the size of the command line string
    char *cmdline = malloc(cmdline_size); // allocate memory for the command line string

    snprintf(cmdline, cmdline_size, "%s%s", SOUND_CMD, file_path); // create the command line

    system(cmdline); // execute the command line

    free(cmdline);
}
