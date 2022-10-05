%this function sets the initial parameters of the vehicle 

clear;
clear Plotting;
clear SensorModel;
clear drawTire;
clear Control;
clf;

global controlArray;
global controlIndex;
carLocation = [1 2]';  %Car location in the pool frame
thetaC = 0; %set the initial angle of the car
thetaS = -pi/8; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [1, 0]; %, vel, thetaS
seed = rng('shuffle');

%circ/line (0/1), Cx/W1x, Cy/W1y, R/W2x, CW(0),CCW(1)/W2y, Nx(halfplane), Ny
controlArray = {0, 3, 3, 2, 0, 0, 1, 0, 100;
                1, 3, 3, 6, 2, 0, 1, 0, 100};