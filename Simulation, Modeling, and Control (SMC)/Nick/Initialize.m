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
dt = 0.01;
v = 2;
carLocation = [1 8]';  %Car location in the pool frame
thetaC = deg2rad(270); %set the initial angle of the car
thetaS = -pi/6; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [v, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), Cx/W1x, Cy/W1y, R/W2x, CW0/CCW1/W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
    % N normal vector
    % p position of normal vector
    controlArray = [1, 1, 9, 1, 3, 0, -1, 1, 3;
                    0, 3, 3, 2, 1, 1, 0, 3, 1;
                    1, 3, 1, 8, 1, 1, 0, 8, 1;
                    0, 8, 3, 2, 1, -1, 0, 8, 5;
                    0, 8, 7, 2, 0, 0, 1, 6, 7;
                    0, 3.5, 7, 2, 1, 0, -1, 1, 7];
    controlIndex = 1;