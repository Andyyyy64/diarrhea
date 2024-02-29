#include <stdlib.h>
#include <stdio.h>
#include "include/checkdir.h"

int main() {

    char *watch_dir = getenv("WATCH_DIR"); // get the directory to be watched from the environment variable
    char *sound_file = getenv("SOUND_FILE"); // get the sound file from the environment variable
    if (sound_file == NULL) {
        sound_file = "sound/diarrhea.mp3";
    }
    set_dir(watch_dir); // set the directory to be watched
    set_sound(sound_file); // set the sound file to be played
    start_checkdir(); // start the thread to watch the directory
    return 0;
}
