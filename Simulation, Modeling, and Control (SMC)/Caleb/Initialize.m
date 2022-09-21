clear;
clear Plotting;
clear SensorModel;
clear drawTire;
clear Control;
clf;
carLocation = [2 2]';  %Car location in the pool frame
thetaC = 0; %set the initial angle of the car
thetaS = -pi/6; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [1, 0]; %, vel, thetaS
seed = rng('shuffle');