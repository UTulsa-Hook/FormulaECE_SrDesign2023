clear;
clear Plotting;
clear PlottingTest;
clear SensorModel;
clear drawTire;
clear Control;
clear drawChassis;
clear controlCircle;
clear controlLine;
clear MotorModels;
clf;

global controlArray;
global controlIndex;
global dt;
global v;

global driveTable;
global steerTable;

driveTable = [78 .92; 80 1.56; 82 2.19; 84 2.61;]; % Eriks PWM values, speed;
steerTable = [60, 45; 62, 45; 64, 55; 66, 60;...
                68, 70; 70 75; 72 80; 74 90;...
                76 95; 78 105; 80 110; 82 115;...
                84 120; 86 125; 88 130;]; % Eriks PWM values, angle,
                                          % 90 is straight

global includeUncertainty;
global sigmaSteering;
global sigmaDrive;
global sigmaPos;
global sigmaPosTime;
global muPosTime;

includeUncertainty = false;
sigmaSteering = deg2rad(5); %steering angle radians.
sigmaDrive = .2; %m/s
sigmaPos = .2;
sigmaPosTime = .1;
muPosTime = .7;

dt = 0.01;
v = 1;
carLocation = [10.927 9]';  %Car location in the pool frame
thetaC = deg2rad(180); %set the initial angle of the car
thetaS = 0; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [v, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), Cx/W1x, Cy/W1y, R/W2x, CW0/CCW1/W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
    % N normal vector
    % p position of normal vector
%     controlArray = [1, 1, 9, 1, 2, 0, -1, 1, 2; 
%                     0, 2.1, 2.1, 1, 1, 1, 0, 2, 1
%                     1, 2, 1, 6, 2, 1, 0, 6, 2
%                     1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
%                     0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5
%                     1, 11, 2.5, 11, 5, 0, 1, 11, 5
%                     0, 10, 4.9, 1, 1, 0, -1, 9, 5
%                     0, 7.9, 5.1, 1, 0, -1, 0, 8, 4
%                     1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
%                     0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3
%                     1, 3, 5.5, 3, 8, 0, 1, 3, 7.6
%                     0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9
%                     1, 4, 9, 10, 9, 1, 0, 10.1, 9
%                     0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
%                     1, 10, 12, 6, 10, -1, 0, 6, 10
%                     1, 6, 10, 2, 10, -1, 0, 2, 10
%                     0, 2, 9, 1, 1, 0, -1, 1, 9];
    controlArray = [1, 10.927, 9.55, 5.366, 9.464, -1, 0, -100, 0]; %line
   % controlArray = [0, 9.415, 9.592, 1.5, 1, 0, 1, 0, 100];
   % controlArray = [1, 9.352, 11.069, 6.823, 11.054, 0, -1, 6.7, 11.054; 
%                     0, 6.857, 9.552, 1.5, 1, 1, 0, 6.9, 8.037; 
%                     1, 6.959, 8.037, 9.446, 8.058, 1, 0, 9.4, 8.058;
%                     0, 9.415, 9.592, 1.5, 1, -1, 0, 9.2, 11.069];
    controlIndex = 1;