//usr/bin/cc "$0" "comms.c" && exec ./a.out "$@"
#include "comms.h"

#define BUFFSIZE 512

int main(void) {
	struct Pipes pip;
	pip = openPipes();
	int n;
	int count = 0;
	char buf[BUFFSIZE] = {0};
	char outbuf[BUFFSIZE] = {0};
	while(count <= 100) {
		n = readInPipe(pip, buf, BUFFSIZE);
        if ( write(STDOUT_FILENO, buf, n) != n) {
            return 1;
        }
        sprintf(outbuf, "received: %d", count++);
        writeOutPipe(pip, outbuf, BUFFSIZE);
	}
	closePipes(pip);
	return 0;
}
