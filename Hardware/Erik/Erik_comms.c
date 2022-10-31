//usr/bin/cc "$0" && exec ./a.out "$@"
#include "comms.h"

#define INFILENAME "pytoc"
#define OUTFILENAME "ctopy"

struct Pipes openPipes() {
    struct Pipes ret = {0,0};
    mkfifo(INFILENAME, 0600);
    mkfifo(OUTFILENAME, 0600);
    if ((ret.in = open(INFILENAME, O_RDONLY)) < 0) {
        fprintf(stderr,"Error: open infile");
    	return ret;
    }
        
    if ((ret.out = open(OUTFILENAME, O_WRONLY)) < 0) {
        fprintf(stderr,"Error: open outfile");
    	return ret;
	}
    return ret;
}

int readInPipe(struct Pipes file, char *buf, int bufsize) {
    return read(file.in, buf, bufsize);
}

void writeOutPipe(struct Pipes file, char *outbuf, int bufsize) {
	write(file.out, outbuf, bufsize);
}
    
void closePipes(struct Pipes file) {
    unlink(INFILENAME);
    unlink(OUTFILENAME);
    close(file.in);
    close(file.out);
}
