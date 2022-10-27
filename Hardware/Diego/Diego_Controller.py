from time import sleep
from rpi_hardware_pwm import HardwarePWM

if __name__ == '__main__':
    servo = HardwarePWM(pwm_channel = 0, hz = 480)
    servoDuty = 75
    servo.start(servoDuty)
    
    motor = HardwarePWM(pwm_channel = 1, hz = 480)
    motorDuty = 72
    motor.start(motorDuty)
    
    while True:
        duty = input("Enter duty: ")
        
        if (duty == "a"):
            servo.change_duty_cycle(servoDuty-10)
        elif (duty == "w"):
            motor.change_duty_cycle(80)
        elif (duty == "d"):
            servo.change_duty_cycle(servoDuty+6)
        elif (duty == "e"):
            servo.change_duty_cycle(77)
        
        elif (duty == "s"):
            motor.change_duty_cycle(64)
        elif (duty == "q"):
            motor.change_duty_cycle(76)
        sleep(0.01)
