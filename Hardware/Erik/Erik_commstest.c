//usr/bin/cc "$0" "comms.c" && exec ./a.out "$@"
#include "comms.h"
#include <string.h>

#define BUFFSIZE 512

int main(void) {
	struct Pipes pip;
	pip = openPipes();
	int n;
	int count = 0;
	char buf[BUFFSIZE] = {0};
	char outbuf[BUFFSIZE] = {0};
	double heading;
	double posx;
	double posy;
	while(1) {
		n = readInPipe(pip, buf, BUFFSIZE);
        /*if ( write(STDOUT_FILENO, buf, n) != n) {
            //return 1;
        }*/
        sprintf(outbuf, "received: %d", count++);
		writeOutPipe(pip, outbuf, BUFFSIZE);

		/*char *token = strtok(buf, ",");
		n = 0;
		while(n++ < 5) {
			printf("%s\n",token);
			token = strtok(NULL, ",");
		}*/

		/*char *token = strtok(buf, ",");
		sscanf(token, "%lf", &posx);
		printf("%.4lf\n", posx);
		token = strtok(NULL, ",");
		sscanf(token, "%lf", &posy);
		printf("%.4lf\n", posy);
		token = strtok(NULL, ",");
		//printf("%s\n", token);
		sscanf(token, "%lf", &heading);
		printf("%.4lf\n", heading);*/

		sscanf(strtok(buf, ","), "%lf", &posx);
		printf("%.4lf\n", posx);
		sscanf(strtok(NULL, ","), "%lf", &posy);
		printf("%.4lf\n", posy);
		sscanf(strtok(NULL, ","), "%lf", &heading);
		printf("%.4lf\n", heading);

		}
	closePipes(pip);
	return 0;
}
