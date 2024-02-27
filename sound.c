#include "include/sound.h"
#include <stdlib.h>

void make_sound(const char *file_path) {
    char *cmdline = NULL;
    cmdline = malloc(strlen("aplay -q ") + strlen(file_path) + 1); // allocate memory for the command line string
    system(cmdline); // execute the command line
    free(cmdline);
}
