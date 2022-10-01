clear;
clear Plotting;
clear PlottingTest;
clear SensorModel;
clear drawTire;
clear Control;
clf;
global controlArray;
global controlIndex;
global velocity;
global dt; 
velocity = 2;
dt = 0.01;
carLocation = [6 3]';  %Car location in the pool frame
thetaC = pi/2; %set the initial angle of the car
%thetaS = -pi/6; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [velocity, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), C_x/W1_x, C_y/W1_y, R/W2_x, CW/CCW (0,1) / W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
    controlArray = [0, 3, 3, 2, 1, 0, -1, 1, 3;
                    1, 1, 3, 9, 2, 0, 1, 0, 100];
    controlIndex = 1;