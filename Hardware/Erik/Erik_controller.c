//usr/bin/cc "$0" && exec ./a.out "$@"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	printf("Hello World\n");
	char *fexport = "/sys/class/pwm/pwmchip0/export";
	char *f0enable = "/sys/class/pwm/pwmchip0/pwm0/enable";
	char *f0duty = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle";
	char *f0period = "/sys/class/pwm/pwmchip0/pwm0/period";
	FILE *enable = fopen(f0enable,"w");
	if (enable == NULL) {
		FILE *export = fopen(fexport,"w");
		if (export == NULL) {   
			printf("Error! Could not open export file.\n");
			printf("Need to add 'dtoverlay=pwm-2chan' ");
			printf("to /boot/config.txt and reboot\n");
			return -1;
		}
		fprintf(export,"%d\n",0);
	}
	enable = fopen(f0enable,"w");
	while (enable == NULL) {
		sleep(0.01);
		enable = fopen(f0enable,"w");
	}
	FILE *duty = fopen(f0duty,"w");
	while (duty == NULL) {   
		sleep(0.01);
		duty = fopen(f0duty,"w");
	}
	FILE *period = fopen(f0period,"w");
	if (period == NULL) {   
		printf("Error! Could not open period file.\n");
		return -1;
	}
	
	float freq = 485;
	int per = 1000000000/freq;
	float duty_cycle = 71.05;
	int dc = per*duty_cycle/100;
	printf("%d %d %d %d\n", (int)freq,per,(int)duty_cycle,dc);
	fprintf(enable,"%d\n",1);
	//fprintf(duty,"%d\n",0);
	fprintf(period,"%d\n",per);
	fprintf(duty,"%d\n",dc);
	int buf[100];
	while(1){
		return 0;
	}
}
