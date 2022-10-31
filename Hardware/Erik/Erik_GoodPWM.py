#!/usr/bin/env python3
# https://pypi.org/project/rpi-hardware-pwm/
from time import sleep
from rpi_hardware_pwm import HardwarePWM

if __name__ == '__main__':
	pwm = HardwarePWM(pwm_channel=0, hz=480)
	pwm.start(72) # full duty cycle

	while True:
		duty = int(input("enter duty: "))
		if (duty == 0):
			pwm.stop()
			exit
		pwm.change_duty_cycle(duty)
