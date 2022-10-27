'''

Author: Nicholas Chorette
Date Last Updated: 10/23/2022

Speed in this version is controlled with typing a character and pressing enter to push it thru.
It is Recommended using a simulatek keyboard and have it press enter for you. While it is not excelent, this method does infact work. 

The general concept here for this test is you have 3 states: Forwards, Neutral, and Backwards.
When you go forwards and need to stop, simply press "s" (backwards) key and it will return to its neutural state.
If you are contimuing to roll from momentum and want to stop faster, it is recommended to drive on carpet, a more
grippable ground, or try and go in reverse and quickly switch back to neutral. (This works best on floors you are
sliding around on). 

For the actual race, this code will not be used, but it IS a good starting place to test and see if your car is working. 

Please note that I am ONLY using the Raspberry Pi to control the PWM of the servo (GND + PWM Signal + 5V power) and the
ESC (electronic speed controller) (GND + PWM Signal,Powered Externally from the Motor Battery). It is advised to NOT
connect power to the ESC directly, this will result in the RasPi having ~6V to it, as the ESC does infact provide ~1V
from its drive motor battery. 

'''

import time
from rpi_hardware_pwm import HardwarePWM

if __name__ == '__main__':
    
    #---Set-up Servo PWM---
    ServoPwm = HardwarePWM(pwm_channel = 0, hz = 480)
    ServoDuty = 76
    ServoPwm.start(ServoDuty)
    
    #---Set-up Drive Motor PWM---
    MotorPwm = HardwarePWM(pwm_channel = 1, hz = 480)
    MotorDuty = 72
    MotorPwm.start(MotorDuty)
    
    motorState = 0 #neutral state
    while True:
        
        drive = input("Drive Time :)\n")
        #Speed Limiter Enabled (+/-1 , Motor State Concept Implemented for testing ONLY, please remove for REAL tests!!!) 
        if (drive == "w"): # Accelerator/Forwards
            #if(motorState ==-1): #backwards or nrutral
            motorState +=1
            if(motorState > 1): #MUST not go past thisw 
                motorState = 1

        elif (drive =="s"): #slowdown/Reverse

            motorState += -1 #no point in me devrementing it when IK i want it to be zero 
            if(motorState <-1): #MUST not go past this state 
                motorState =-1
           
        if(motorState == -1): #---Backwards---
            MotorDuty = 57 #72 - 15 
        elif(motorState == 0):#---Neutral---
            MotorDuty = 72
        elif(motorState == 1):#---Forwards---
            MotorDuty = 72 + 5 #72 + (roundUp(15*0.25) = 72 + 4


        #-------WARNING!!!: I DID NOT SET A TRUE SAFETY RANGE ON THIS THING, THIS SIMPLY PREVENTS CODE FROM CRASHING! TURN WITH CAUTION!!!---
        if(ServoDuty ==100 or ServoDuty ==0):
            print("Servo PWM limit Has been reached!")
            if(ServoDuty==100):
                ServoDuty = 98
            else: #It's 0
                ServoDuty = 2
                
        #---Steering: Left and Right 
        if (drive =="d"): #Right 
           ServoDuty -=2
           # ServoPwm.change_duty_cycle(ServoDuty-2) #-15)
           time.sleep(.01)
            
        elif (drive =="a"): #Left
            ServoDuty +=2
            #ServoPwm.change_duty_cycle(ServoDuty) #y+15)
            time.sleep(.01)
            
        if (drive == "q"): #Stop Car (Drive Motor)
            MotorDuty = 72
            #MotorPwm.change_duty_cycle(72)
            time.sleep(.01)
         
        if (drive =="e"): #Center Servo 
            ServoDuty = 76
            #ServoPwm.change_duty_cycle(76)
            time.sleep(.01)

        #---Update Drive motor, Update Servo, Update User on Status of device 
        ServoPwm.change_duty_cycle(ServoDuty)
        MotorPwm.change_duty_cycle(MotorDuty)
        print("Servo: " + str(ServoDuty) + "\nMotor:" + str(MotorDuty) + "\n MotorState: " + str(motorState))


