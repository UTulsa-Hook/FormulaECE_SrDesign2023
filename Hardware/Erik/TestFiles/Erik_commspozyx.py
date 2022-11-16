#!/usr/bin/env python3
from pypozyx import *
from pypozyx.structures.device_information import *
from time import sleep
import os, serial

if __name__ == '__main__':
	port = get_first_pozyx_serial_port()
	pozyx = PozyxSerial(port,print_output=False)
	sensors = SensorData()
	raw = RawSensorData()
	
	details = DeviceDetails()
	pozyx.getDeviceDetails(details)
	print(details.id)
	print(pozyx.getNetworkId(details))
	pozyx.printDeviceInfo()
	
	outPath = "pytoc"
	inPath = "ctopy"
	try:
		try:
			os.mkfifo(outPath, 0o600)
			print(f"Pipe named '{outPath}' is created successfully.\n")
		except:
			print(f"Pipe '{outPath}' already exists\n" )
		try:
			os.mkfifo(inPath, 0o600)
			print(f"Pipe named '{inPath}' is created successfully.\n")
		except:
			print(f"Pipe '{inPath}' already exists\n" )
		sleep(0.01)
		out = os.open(outPath, os.O_WRONLY)
		infile = os.open(inPath, os.O_RDONLY)
	except:
		try:
			os.unlink(outPath)
			os.unlink(inPath)
		except:
			print("Files already deleted\n")
		exit()
	#os.write(out, b'hello\n')
	#os.close(out)
	
	while True:
		try:
			pozyx.getAllSensorData(raw)
			os.write(out, bytes(f"{raw[4]},{raw[5]},{raw[6]}\n","utf-8"))
			print(os.read(infile, 512).decode("utf-8"))
		except:
			try:
				os.close(out)
				os.close(infile)
				os.unlink(outPath)
				os.unlink(inPath)
			except:
				print("Files already deleted\n")
			exit()
		
		
