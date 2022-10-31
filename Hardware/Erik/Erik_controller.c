//usr/bin/cc "$0" && exec ./a.out "$@"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct channel {
	char *enable;
	char *duty;
	char *period;
};

int main(void) {
	printf("Hello World\n");
	struct channel pwm0 = {
		.enable = "/sys/class/pwm/pwmchip0/pwm0/enable",
		.duty = "/sys/class/pwm/pwmchip0/pwm0/duty_cycle",
		.period = "/sys/class/pwm/pwmchip0/pwm0/period"
	};
	char *fexport = "/sys/class/pwm/pwmchip0/export";
	FILE *export = fopen(fexport,"w");
	if (export == NULL) {   
		printf("Error! Could not open export file.\n");
		printf("Need to add 'dtoverlay=pwm-2chan' ");
		printf("to /boot/config.txt and reboot\n");
		return -1;
	}
	FILE *enable = fopen(pwm0.enable,"w");
	while (enable == NULL) {
		fprintf(export,"%d",0);
		sleep(0.1);
		enable = fopen(pwm0.enable,"w");
	}
	FILE *duty = fopen(pwm0.duty,"w");
	while (duty == NULL) {   
		sleep(0.1);
		duty = fopen(pwm0.duty,"w");
	}
	FILE *period = fopen(pwm0.period,"w");
	if (period == NULL) {   
		printf("Error! Could not open period file.\n");
		return -1;
	}
	
	float freq = 480;
	int per = 1000000000/freq;
	float duty_cycle = 72;
	int dc = per*duty_cycle/100;
	printf("%d %d %d %d\n", (int)freq,per,(int)duty_cycle,dc);
	fprintf(enable,"%d",1);
	//fprintf(duty,"%d\n",0);
	fprintf(period,"%d",per);
	fprintf(duty,"%d",dc);
	int buf[100];
	while(1){
		return 0;
	}
}
