#!/usr/bin/env python3
from time import sleep
import RPi.GPIO as GPIO

if __name__ == '__main__':
	pin = 12
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(pin,GPIO.OUT)
	pi_pwm = GPIO.PWM(pin,500)
	pi_pwm.start(71)
	while True:
		pi_pwm.ChangeDutyCycle(int(input("enter duty: ")))
