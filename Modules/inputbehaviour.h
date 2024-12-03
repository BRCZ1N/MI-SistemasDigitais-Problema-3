#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <linux/input.h>

extern struct input_event ev;
extern pthread_mutex_t lock;
extern int fd_mouse;
extern int xsoma, ysoma;
extern unsigned int click_reset;
extern int start;
extern int end;
extern int restart;
extern int stop;

void* read_mouse(void* arg);
void* read_key(void* arg);