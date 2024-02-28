#include <stdlib.h>
#include "include/checkdir.h"

#define WATCH_DIR "/home/andy/PROJECT/4fun/diarrhea/.git/logs" // directory to be watched

int main() {
    set_dir(WATCH_DIR); // set the directory to be watched
    start_checkdir(); // start the thread to watch the directory
    return 0;
}
