import serial
import time

numl = input("Enter PWM percentage:")   
ranges = range(0, 100, 1)

x = 100
y = 255

if int(numl) in ranges:
    print(numl, "In range")
    stepOne = int(numl)/x
    stepTwo = stepOne*y

    if __name__ == '__main__':
        ser = serial.Serial('/dev/ttyUSB0', 57600, timeout=1) #baud rate needs to match arduino
        ser.reset_input_buffer()
    
    stepTwo = str(stepTwo) # number into string to later to get byte
    stepTwo = bytes(stepTwo, 'ascii')
    
    while True:
        ser.write(stepTwo)
        line = ser.readline().decode('ascii').rstrip() #decode make sure only to recive the text from arduino not the code surrounding it
        print(line)
        time.sleep(1)



                
        
        