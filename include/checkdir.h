#ifndef CHECKDIR_H
#define CHECKDIR_H

// set the directory to be watched
void set_dir(const char *dir);

void handle_events(int fd); // handle the events(like file creation, deletion, modification)

// start the thread to watch the directory
void start_checkdir();

// stop the thread to watch the directory
void stop();

#endif // CHECKDIR_H
