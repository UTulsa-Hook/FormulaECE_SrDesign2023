#!/usr/bin/env python3
from time import sleep
from rpi_hardware_pwm import HardwarePWM
import sys
import termios
import atexit
from select import select
class KBHit:
	def __init__(self):
		'''Creates a KBHit object that you can call to do various keyboard things.
		'''
		# Save the terminal settings
		self.fd = sys.stdin.fileno()
		self.new_term = termios.tcgetattr(self.fd)
		self.old_term = termios.tcgetattr(self.fd)

		# New terminal setting unbuffered
		self.new_term[3] = (self.new_term[3] & ~termios.ICANON & ~termios.ECHO)
		termios.tcsetattr(self.fd, termios.TCSAFLUSH, self.new_term)

		# Support normal-terminal reset at exit
		atexit.register(self.set_normal_term)

	def set_normal_term(self):
		termios.tcsetattr(self.fd, termios.TCSAFLUSH, self.old_term)

	def getch(self):
		''' Returns a keyboard character after kbhit() has been called.
			Should not be called in the same program as getarrow().
		'''
		return sys.stdin.read(1)


	def getarrow(self):
		''' Returns an arrow-key code after kbhit() has been called. Codes are
		0 : up
		1 : right
		2 : down
		3 : left
		Should not be called in the same program as getch().
		'''

		c = sys.stdin.read(3)[2]
		vals = [65, 67, 66, 68]
		return vals.index(ord(c.decode('utf-8')))


	def kbhit(self):
		''' Returns True if keyboard character was hit, False otherwise.
		'''
		dr,dw,de = select([sys.stdin], [], [], 0)
		return dr != []

if __name__ == '__main__':
	servopwm = HardwarePWM(pwm_channel=0, hz=480)
	servoduty = 72
	servopwm.start(servoduty) # servo
	motorpwm = HardwarePWM(pwm_channel=1, hz=480)
	motorpwm.start(72) # motor
	kb = KBHit()
	counter = 0
	userinput = None
	while True:
		if kb.kbhit():
			userinput = kb.getch()
			print(userinput)
		counter += 1
		if (counter == 20):
			motorpwm.change_duty_cycle(72)
			print("no input")
		if (userinput == "w"):
			counter = 0
			motorpwm.change_duty_cycle(80)
		elif (userinput == "a"):
			servoduty = min(servoduty+2, 82)
			servopwm.change_duty_cycle(servoduty)
		elif (userinput == "s"):
			counter = 0
			motorpwm.change_duty_cycle(50)
		elif (userinput == "d"):
			servoduty = max(servoduty-2, 62)
			servopwm.change_duty_cycle(servoduty)
		elif (userinput == "c"):
			servoduty = 72
			servopwm.change_duty_cycle(servoduty)
		elif (userinput == "q"):
			servoduty = 82
			servopwm.change_duty_cycle(servoduty)
		elif (userinput == "e"):
			servoduty = 62
			servopwm.change_duty_cycle(servoduty)
		elif (userinput == "p"):
			break
		sleep(0.01)
		userinput = None
	kb.set_normal_term()
