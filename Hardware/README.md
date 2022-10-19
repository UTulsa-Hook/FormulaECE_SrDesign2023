# Some info about my code

## Arduino
The files Erik_ArduinoCode.ino and Erik_PythonCode.py are for controlling the servo and ESC from the arduino, but we realized the Arduino was not necessary so those files are now obsolete. They are still useful to keep as examples.

## Pozyx
The files Erik_multitag.py, Erik_range.py, and Erik_localize.py are modified copies of the ready_to_localize, ready_to_range, and ready_to_localize pozyx tutorial files respectively. The main difference between Erik_multitag.py and Erik_localize.py is that Erik_multitag.py includes the IDs of other tags.
To connect to the pozyx tag go through the micro-USB port on the pozyx tag to a USB port on the pi.

## Raspberry Pi PWM
For Erik_GoodPWM.py and controller.py they both use https://github.com/Pioreactor/rpi_hardware_pwm (`from rpi_hardware_pwm import HardwarePWM`). Follow the instructions on their Github to get the library working. I have copied the instructions here for convenience.

1. On the Raspberry Pi, add `dtoverlay=pwm-2chan` to `/boot/config.txt`. This defaults to `GPIO_18` as the pin for `PWM0` and `GPIO_19` as the pin for `PWM1`.
	* Alternatively, you can change `GPIO_18` to `GPIO_12` and `GPIO_19` to `GPIO_13` using `dtoverlay=pwm-2chan,pin=12,func=4,pin2=13,func2=4`.
2. **Reboot your Raspberry Pi**.
	* You can check everything is working on running `lsmod | grep pwm` and looking for `pwm_bcm2835`
3. Install this library: `sudo pip3 install rpi-hardware-pwm`

For Erik_controller.py `class KBHit` is copied from https://stackoverflow.com/a/22085679 and edited to remove the OS checks.
