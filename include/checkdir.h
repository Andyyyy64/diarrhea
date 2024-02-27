#ifndef CHECKDIR_H
#define CHECKDIR_H

// set the directory to be watched
void set_dir(const char *dir);

// start the thread to watch the directory
void start_chackdir();

// stop the thread to watch the directory
void stop();

#endif // CHECKDIR_H
