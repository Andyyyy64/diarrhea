#include <stdlib.h>
#include <stdio.h>
#include "include/checkdir.h"

int main() {

    char *watch_dir = getenv("WATCH_DIR");
    set_dir(watch_dir); // set the directory to be watched
    start_checkdir(); // start the thread to watch the directory
    return 0;
}
