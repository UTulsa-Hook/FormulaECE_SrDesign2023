'''
Author: Nicholas Chorette
Date Last Edited: 10/23/2022
Purpose: Generates the number of COM ports specified. I need to figure out how to take note of and record the COM ports generated to pass to the other devices that need them :) 


'''
import virtualserialports
virtualserialports.run(3, loopback=True, debug=False)
