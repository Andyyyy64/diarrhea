#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h> // for checking directory changes
#include <unistd.h> // provides access to the POSIX API(general api for unix-like systems)
#include <limits.h> // for PATH_MAX
#include <string.h>

#include "include/checkdir.h"
#include "include/sound.h"

static int inotify_fd; // file descriptor for inotify
static int watch_fd; // file descriptor for the directory to be watched
static char *watchDir = NULL; // directory to be watched

void set_dir(const char *dir) {
    if(watchDir != NULL) {
        free(watchDir); // if the directory has been set, reset it
    }
    watchDir = strdup(dir); // set the directory
    printf("watchDir: %s\n", watchDir); // debug
}

void handle_events(int fd) {
    char buf[4096] // buffer for reading the events
        __attribute__ ((aligned(__alignof__(struct inotify_event)))); // idk what this does but it's in the example haha
    const struct inotify_event *event; // event structure
    ssize_t len; // length of the event
    char *ptr; // pointer for iterating through the buffer

    len = read(fd, buf, sizeof(buf)); // read the events from the buffer, return the bytes read

    printf("read the events: %ld\n", len); // debug

    if(len == -1) {
        return;
    }

    for(ptr = buf; ptr < buf + len; ptr += sizeof(struct inotify_event) + event->len) { // i guess this is for rooping through the events
        event = (const struct inotify_event *) ptr; // set the event to the current event

        printf("inside the loop\n"); // debug

        if(event->len & (IN_MODIFY | IN_CREATE | IN_DELETE)) {
            make_sound("sounds/diarrhea.mp3"); // play the sound
        }
    }
}

void start_checkdir() {
    if(watchDir == NULL) {
        return; // if the directory has not been set, return
    }

    inotify_fd = inotify_init(); // initialize inotify
    if(inotify_fd == -1) {
        return; // if inotify initialization fails, return
    }
    watch_fd = inotify_add_watch(inotify_fd, watchDir, IN_MODIFY | IN_CREATE | IN_DELETE); // add the directory to be watched
    if(watch_fd == -1) {
        close(inotify_fd); // if adding the directory to be watched fails, close inotify
        return;
    }

    while(1) {
        handle_events(inotify_fd); // handle the events
        usleep(1000); // sleep for 1000 microseconds for cpu usage
    }
}
