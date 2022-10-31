#!/usr/bin/env python3
# https://github.com/pozyxLabs/Pozyx-Python-library/tree/master/pypozyx
from pypozyx import *
from time import sleep
import pypozyx
print(pypozyx.__file__)
if __name__ == '__main__':
	port = get_first_pozyx_serial_port()
	pozyx = PozyxSerial(port)
	sensors = SensorData()
	raw = RawSensorData()
	
	while True:
		pozyx.getAllSensorData(sensors)
		print(sensors.pressure,sensors.acceleration,sensors.magnetic,\
		sensors.angular_vel,sensors.euler_angles,sensors.quaternion,\
		sensors.linear_acceleration,sensors.gravity_vector,\
		sensors.temperature, sep="\n")
		pozyx.getAllSensorData(raw)
		print(Pressure(raw[0]),\
		Acceleration(raw[1], raw[2], raw[3]),\
		Magnetic(raw[4], raw[5], raw[6]),\
		AngularVelocity(raw[7], raw[8], raw[9]),\
		EulerAngles(raw[10], raw[11], raw[12]),\
		Quaternion(raw[13], raw[14], raw[15], raw[16]),\
		LinearAcceleration(raw[17], raw[18], raw[19]),\
		LinearAcceleration(raw[20], raw[21], raw[22]),\
		Temperature(raw[23]), sep="\n")
		sleep(1)
