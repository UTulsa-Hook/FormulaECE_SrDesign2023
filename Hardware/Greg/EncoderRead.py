import json
from time import sleep
from rpi_hardware_pwm import HardwarePWM
import sys
import termios
import atexit
from select import select
import RPi.GPIO as GPIO
import time
import serial
import random

duty = 76
fuck = 0
characterization = {76: [],76.5: [],77: [],77.5: [],78: [],78.5: [],79: [],79.5: [],80: [],80.5: [],81: [],81.5: [],82: []}

def ReadSpeed():
    data = ""
    ser.flushInput()
    average = 0
    for i in range(5):
        while(True):
            readChar = ser.read().decode("utf-8")
            if (readChar != '\n'):
                data += readChar
            elif (len(data) < 5):
                #print(data)
                average += int(data)
                data = ""
                break
            else:
                data = ""
    return average / 5

if __name__ == '__main__':
    motorpwm = HardwarePWM(pwm_channel=1, hz=480.0)
    motorpwm.start(76) # motor

    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
    ser.reset_input_buffer()

    while(fuck < 6):    
        motorpwm.change_duty_cycle(duty)
        sleep(1)
        characterization[duty].append(str(ReadSpeed()))
        duty += .5
        if (duty == 82):
            duty = 76
            fuck += 1
    motorpwm.change_duty_cycle(72)
    with open('Dicktionary.txt', 'w') as convert_file:
        convert_file.write(json.dumps(characterization))
