%this function sets the initial parameters of the vehicle 

clear;
clear Plotting;
clear SensorModel;
clear drawTire;
clear Control;
clf;

global controlArray;
global controlIndex;
global dt;
global v;
dt = .01;
v = 3;
carLocation = [1 9]';  %Car location in the pool frame
thetaC = 0; %set the initial angle of the car
%thetaS = -pi/8; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [v, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), C_x/W1_x, C_y/W1_y, R/W2_x, CW/CCW (0,1) / W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
%WRITE THIS LATER
% controlArray = [1, 1, 9, 1, 2, 0, -1, 1, 2.2;
%                 0, 2, 2, 1, 1, 1, 0, 1.8, 1
%                 1, 2, 1, 6, 2, 1, 0, 6, 2
%                 1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
%                 0, 10, 2.5, 1, 1, 0, 1, 11, 2.5
%                 1, 11, 2.5, 11, 5, 0, 1, 11, 5
%                 0, 10, 5, 1, 1, 0, -1, 9, 5
%                 0, 8, 5, 1, 0, -1, 0, 8, 4
%                 1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
%                 0, 4, 5.5, 1, 0, 0, 1, 3, 5.3
%                 1, 3, 5.5, 3, 8, 0, 1, 3, 7.8
%                 0, 4, 8, 1, 0, 1, 0, 3.8, 9
%                 1, 4, 9, 10, 9, 1, 0, 9.8, 9
%                 0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
%                 1, 10, 12, 6, 10, -1, 0, 6, 10
%                 1, 6, 10, 2, 10, -1, 0, 2, 10
%                 0, 2, 9, 1, 1, 0, -1, 1, 9];
controlArray = [1, .9, 9.1, 7, 2, 0, -1, 7, 2;
                  0, 7.8, 2.6, 1, 1, 1, 0, 8, 1.8; 
                1, 7.8, 1.6, 9, 3, 1, 0, 9, 3;
                 0, 6.1, 3.8, 3, 1, 0, 1, 9, 4.5;
                 1, 9, 4.6, 7, 6, 0, 1, 7, 6; 
                 0, 7, 7, 1, 0, 0, 1, 7, 8; 
                1, 7, 8, 8, 6.5, 1, 0, 7.8, 7.3; 
                  0, 8, 7.5, 1, 1, 0, 1, 9, 7.5;
                 1, 9, 7.5, 3, 10, -1, 0, 3, 10;
                  0, 3, 7, 3, 1, 0, -1, 1, 9];
%                 1, 2, 1, 1, 8, 0, 1, 8, 6 %r
%                  0, 7, 2, 5, 0, 0, -1, 5, 7 %r
%                 1, 9, 8, 5, 3, -1, 0, 6, 3 %r
%                  0, 2, 6, 3, 0, 1, 0, 5, 4 %r
%                 1, 8, 10, 6, 2, 0, -1, 7, 8 %r
%                  0, 2, 4, 7, 0, 0, -1, 8, 6 %r
%                 1, 2, 4, 6, 9, -1, 0, 4, 2]; %r
    controlIndex = 1;