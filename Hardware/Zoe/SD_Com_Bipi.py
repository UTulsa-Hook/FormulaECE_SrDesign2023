import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1) #baud rate needs to match arduino
    ser.reset_input_buffer()
    
    while True:
        ser.write(b"Hello from Zjam!\n")
        line = ser.readline().decode('ascii').rstrip() #decode make sure only to recive the text from arduino not th code surrounding it
        print(line)
        time.sleep(1)
