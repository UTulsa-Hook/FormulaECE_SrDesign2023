import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 57600, timeout=1) #baud rate needs to match arduino
ser.flush()
dCycle = '75'

while dCycle != '0':
    
    dCycle = input("Enter PWM percentage:")   
    ranges = range(0, 100, 1)
    
    if int(dCycle) in ranges:
        ser.write(dCycle.encode('ascii'))
        
    else:
        print("Error re-run code")
    
    time.sleep(1)
    print("Duty Cycle:" + ser.readline().decode('ascii').rstrip()) #decode make sure only to recive the text from arduino not the code surrounding it
            
        
        
