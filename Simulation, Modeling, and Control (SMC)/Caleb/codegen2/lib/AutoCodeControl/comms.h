//usr/bin/cc "$0" && exec ./a.out "$@"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pipes {int in; int out;};

struct Pipes openPipes();
int readInPipe(struct Pipes file, char *buf, int bufsize);
void writeOutPipe(struct Pipes file, char *buf, int bufsize);
void closePipes(struct Pipes file);