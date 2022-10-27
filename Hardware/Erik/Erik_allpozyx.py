#!/usr/bin/env python3
from pypozyx import *
from pypozyx.structures.device_information import *
from rpi_hardware_pwm import HardwarePWM
from time import sleep
from datetime import datetime
read = datetime.now()
write = datetime.now()
import os, serial
from pypozyx import (POZYX_POS_ALG_UWB_ONLY, POZYX_3D, Coordinates, POZYX_SUCCESS, PozyxConstants, version,
					 DeviceCoordinates, PozyxSerial, get_first_pozyx_serial_port, SingleRegister, DeviceList, PozyxRegisters)

class ReadyToLocalize(object):
	"""Continuously calls the Pozyx positioning function and prints its position."""

	def __init__(self, pozyx, anchors, algorithm=POZYX_POS_ALG_UWB_ONLY, dimension=POZYX_3D, height=1000, remote_id=None):
		self.pozyx = pozyx

		self.anchors = anchors
		self.algorithm = algorithm
		self.dimension = dimension
		self.height = height
		self.remote_id = remote_id

	def setup(self):
		"""Sets up the Pozyx for positioning by calibrating its anchor list."""
		print("------------POZYX POSITIONING V{} -------------".format(version))
		print("")
		print("- System will manually configure tag")
		print("")
		print("- System will auto start positioning")
		print("")
		if self.remote_id is None:
			self.pozyx.printDeviceInfo(self.remote_id)
		else:
			for device_id in [None, self.remote_id]:
				self.pozyx.printDeviceInfo(device_id)
		print("")
		print("------------POZYX POSITIONING V{} -------------".format(version))
		print("")

		self.setAnchorsManual(save_to_flash=False)
		self.printPublishConfigurationResult()

	def loop(self):
		"""Performs positioning and displays/exports the results."""
		position = Coordinates()
		status = self.pozyx.doPositioning(
			position, self.dimension, self.height, self.algorithm, remote_id=self.remote_id)
		if status == POZYX_SUCCESS:
			return self.printPublishPosition(position)
		else:
			#write = datetime.now()-read
			return Coordinates(0,0,0), -1, self.remote_id
			self.printPublishErrorCode("positioning")

	def printPublishPosition(self, position):
		"""Prints the Pozyx's position and possibly sends it as a OSC packet"""
		network_id = self.remote_id
		if network_id is None:
			network_id = 0
		write = datetime.now()-read
		return position, write, network_id
		print("POS ID {}, x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z} time: {time}".format(
			"0x%0.4x" % network_id, pos=position, time=write))

	def printPublishErrorCode(self, operation):
		"""Prints the Pozyx's error and possibly sends it as a OSC packet"""
		error_code = SingleRegister()
		network_id = self.remote_id
		if network_id is None:
			self.pozyx.getErrorCode(error_code)
			print("LOCAL ERROR %s, %s" % (operation, self.pozyx.getErrorMessage(error_code)))
		status = self.pozyx.getErrorCode(error_code, self.remote_id)
		if status == POZYX_SUCCESS:
			print("ERROR %s on ID %s, %s" %
				  (operation, "0x%0.4x" % network_id, self.pozyx.getErrorMessage(error_code)))
		else:
			self.pozyx.getErrorCode(error_code)
			print("ERROR %s, couldn't retrieve remote error code, LOCAL ERROR %s" %
				  (operation, self.pozyx.getErrorMessage(error_code)))
			# should only happen when not being able to communicate with a remote Pozyx.

	def setAnchorsManual(self, save_to_flash=False):
		"""Adds the manually measured anchors to the Pozyx's device list one for one."""
		status = self.pozyx.clearDevices(remote_id=self.remote_id)
		for anchor in self.anchors:
			status &= self.pozyx.addDevice(anchor, remote_id=self.remote_id)
		if len(self.anchors) > 4:
			status &= self.pozyx.setSelectionOfAnchors(PozyxConstants.ANCHOR_SELECT_AUTO, len(self.anchors),
													   remote_id=self.remote_id)

		if save_to_flash:
			self.pozyx.saveAnchorIds(remote_id=self.remote_id)
			self.pozyx.saveRegisters([PozyxRegisters.POSITIONING_NUMBER_OF_ANCHORS], remote_id=self.remote_id)
		return status

	def printPublishConfigurationResult(self):
		"""Prints and potentially publishes the anchor configuration result in a human-readable way."""
		list_size = SingleRegister()

		self.pozyx.getDeviceListSize(list_size, self.remote_id)
		print("List size: {0}".format(list_size[0]))
		if list_size[0] != len(self.anchors):
			self.printPublishErrorCode("configuration")
			return
		device_list = DeviceList(list_size=list_size[0])
		self.pozyx.getDeviceIds(device_list, self.remote_id)
		print("Calibration result:")
		print("Anchors found: {0}".format(list_size[0]))
		print("Anchor IDs: ", device_list)

		for i in range(list_size[0]):
			anchor_coordinates = Coordinates()
			self.pozyx.getDeviceCoordinates(device_list[i], anchor_coordinates, self.remote_id)
			print("ANCHOR, 0x%0.4x, %s" % (device_list[i], str(anchor_coordinates)))


	def printPublishAnchorConfiguration(self):
		"""Prints and potentially publishes the anchor configuration"""
		for anchor in self.anchors:
			print("ANCHOR,0x%0.4x,%s" % (anchor.network_id, str(anchor.coordinates)))


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
	
	
	# shortcut to not have to find out the port yourself
	serial_port = get_first_pozyx_serial_port()
	if serial_port is None:
		print("No Pozyx connected. Check your USB cable or your driver!")
		quit()

	# enable to send position data through OSC
	use_processing = False

	# configure if you want to route OSC to outside your localhost. Networking knowledge is required.
	ip = "127.0.0.1"
	network_port = 8888
	osc_udp_client = None
	
	remote_id = None#0x7624

	# necessary data for calibration, change the IDs and coordinates yourself according to your measurement
	anchors = [DeviceCoordinates(0x7604, 1, Coordinates(5734,11275,1370)),
			   DeviceCoordinates(0x7673, 1, Coordinates(9685,2300,1270)),
			   DeviceCoordinates(0x761A, 1, Coordinates(5720,4730,830)),
			   DeviceCoordinates(0x7616, 1, Coordinates(2145,2947,1250)),
			   DeviceCoordinates(0x614A, 1, Coordinates(10865,12466,1400)),
			   DeviceCoordinates(0x6A11, 1, Coordinates(2297,8453,1370))]

	# positioning algorithm to use, other is PozyxConstants.POSITIONING_ALGORITHM_TRACKING
	algorithm = PozyxConstants.POSITIONING_ALGORITHM_UWB_ONLY
	# positioning dimension. Others are PozyxConstants.DIMENSION_2D, PozyxConstants.DIMENSION_2_5D
	dimension = PozyxConstants.DIMENSION_2D
	# height of device, required in 2.5D positioning
	height = 1000

	pozyx = PozyxSerial(serial_port)
	r = ReadyToLocalize(pozyx, anchors, algorithm, dimension, height, remote_id)
	r.setup()
	pos = Coordinates()
	mag = Magnetic()
	head = EulerAngles()

	servopwm = HardwarePWM(pwm_channel=0, hz=480)
	servoduty = 72
	servopwm.start(servoduty) # servo
	motorpwm = HardwarePWM(pwm_channel=1, hz=480)
	motorduty = 72
	motorpwm.start(72) # motor
	while True:
		try:
			read = datetime.now()
			pos, write, net_id = r.loop()
			pozyx.getAllSensorData(raw, remote_id)
			mag = Magnetic(raw[4],raw[5],raw[6])
			head = EulerAngles(raw[10],raw[11],raw[12])
			os.write(out, bytes(f"{pos.x/1000},{pos.y/1000},{head.heading},{write},{net_id}\n","utf-8"))
			print(pos)
			[motorduty, servoduty] = [float(x) for x in os.read(infile, 512).decode("utf-8").rstrip("\x00").split(",")]
			servopwm.change_duty_cycle(servoduty)
			motorpwm.change_duty_cycle(motorduty)
			print(f"{motorduty},{servoduty}")
		except:
			try:
				os.close(out)
				os.close(infile)
				os.unlink(outPath)
				os.unlink(inPath)
			except:
				print("Files already deleted\n")
			exit()
		
		
		
