import time
from rpi_hardware_pwm import HardwarePWM

if __name__ == '__main__':
    servo = HardwarePWM(pwm_channel = 0, hz = 480)
    servoDuty = 76
    servo.start(servoDuty)
    
    motor = HardwarePWM(pwm_channel = 1, hz = 480)
    motorDuty = 72
    motor.start(motorDuty)
    
    while True:
        duty = input("enter duty: \n")
        
        if (duty =="a"):
            servo.change_duty_cycle(servoDuty-10)
            time.sleep(.01)
        if (duty =="d"):
            servo.change_duty_cycle(servoDuty+10)
            time.sleep(.01)
        if (duty =="w"):
            motor.change_duty_cycle(80)
            time.sleep(.01)
        if (duty =="s"):
            motor.change_duty_cycle(64)
            time.sleep(.01)
        if (duty =="q"):
            motor.change_duty_cycle(72)
            time.sleep(.01)
        if (duty =="e"):
            servo.change_duty_cycle(76)
            time.sleep(.01)
            exit
        # set motor outside range for stop
        # Set one back to straight
        