TopLevel1.m
	main file to run the program, iterates the time steps and calls all functions
Initialize.m
	clears all persistent variables, figures, and sets the initial parameters
	also sets the rng seed for the sensor model
Control.m
	Sets the car on a path to follow a line using a PD controller
	Input: Sensed State (X_bar)
	Output: Change Function (U)
Dynamics.m
	Uses the kinematic equations to update the location and angle of the car
	Input: Current State (X) and Change Function (U)
	Output: New Current State (X)
SensorModel.m
	Generates sensor measurements using simulated biases, noise, and rng values
	Input: Current State (X) and Change Function (U)
	Output: Sensed State (X_bar)

Other Notes:
	Current State (X): x_position, y_position, thetaC
	Sensed State (X_bar): x_position, y_position, thetaC
	Change Function (U): velocity, thetaS