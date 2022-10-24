function [X, U] = AutoCodeInitialize()
% global controlArray;
% global controlIndex;
% global dt;
% global v;
% 
% global driveTable;
% global steerTable;
% 
% driveTable = [78 .92; 80 1.56; 82 2.19; 84 2.61;]; % Eriks PWM values, speed;
% steerTable = [60, 45; 62, 45; 64, 55; 66, 60;...
%                 68, 70; 70 75; 72 80; 74 90;...
%                 76 95; 78 105; 80 110; 82 115;...
%                 84 120; 86 125; 88 130;]; % Eriks PWM values, angle,
%                                           % 90 is straight
% 
% global includeUncertainty;
% global sigmaSteering;
% global sigmaDrive;
% global sigmaPos;
% global sigmaPosTime;
% global muPosTime;
% 
% includeUncertainty = false;
% sigmaSteering = deg2rad(5); %steering angle radians.
% sigmaDrive = .2; %m/s
% sigmaPos = .2;
% sigmaPosTime = .1;
% muPosTime = .7;
v = 1;
carLocation = [1 1]';  %Car location in the pool frame
thetaC = deg2rad(270); %set the initial angle of the car
thetaS = -pi/6; %set the initial steering angle of the car
X = [carLocation(1) carLocation(2) thetaC]'; %x, y, thetaC
U = [v, 0]; %, vel, thetaS
seed = rng('shuffle');

% circ/line(0/1), Cx/W1x, Cy/W1y, R/W2x, CW0/CCW1/W2_y,
    % Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane)
    % N normal vector
    % p position of normal vector
    