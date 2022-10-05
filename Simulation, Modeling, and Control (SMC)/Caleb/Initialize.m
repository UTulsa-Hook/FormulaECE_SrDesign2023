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
velocity = 3;
dt = 0.01;
carLocation = [1.1 8]';  %Car location in the pool frame
thetaC = -pi/2; %set the initial angle of the car
%thetaS = -pi/6; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [velocity, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), C_x/W1_x, C_y/W1_y, R/W2_x, CW/CCW (0,1) / W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
    controlArray = [1, 1, 9, 1, 2, 0, -1, 1, 2.2;
                    0, 2, 2, 1, 1, 1, 0, 1.8, 1
                    1, 2, 1, 6, 2, 1, 0, 6, 2
                    1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
                    0, 10, 2.5, 1, 1, 0, 1, 11, 2.5
                    1, 11, 2.5, 11, 5, 0, 1, 11, 5
                    0, 10, 5, 1, 1, 0, -1, 9, 5
                    0, 8, 5, 1, 0, -1, 0, 8, 4
                    1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
                    0, 4, 5.5, 1, 0, 0, 1, 3, 5.3
                    1, 3, 5.5, 3, 8, 0, 1, 3, 7.8
                    0, 4, 8, 1, 0, 1, 0, 3.8, 9
                    1, 4, 9, 10, 9, 1, 0, 9.8, 9
                    0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
                    1, 10, 12, 6, 10, -1, 0, 6, 10
                    1, 6, 10, 2, 10, -1, 0, 2, 10
                    0, 2, 9, 1, 1, 0, -1, 1, 9];
    controlIndex = 1;