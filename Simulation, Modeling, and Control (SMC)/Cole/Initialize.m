clear;
clear Plotting;
clear PlottingTest;
clear SensorModel;
clear drawTire;
clear Control;
clear drawChassis;
clear drawTire;
clear Circle;
clear MotorModels;
clf;
global Array;
global Index;
global velocity;
global dt;
velocity = 2;
dt = 0.01;
global includeUncertainty;
global sigmaSteering;
global sigmaDrive;
global sigmaPos;
global sigmaPosTime;
global muPosTime;
global driveTable;
global steerTable;
global Scale;
Scale = 2.5;


driveTable = [77, 0.9; 78 1.1; 79 1.5; 80 1.9];
steerTable = [75, 84; 76, 86];

includeUncertainty = true; %Can turn on or off for sim
sigmaSteering = deg2rad(5); %steering angle radians.
sigmaDrive = 0.2; %m/s
sigmaPos = 0.2;
sigmaPosTime = 0.1;
muPosTime = 0.7;

carLocation = [1.5 9]';
thetaC = deg2rad(270);
%thetaDot = -pi/6;
X = [carLocation(1) carLocation(2) thetaC]';
U = [velocity, 0];
seed = rng('shuffle');  

Array = [1, 1, 9, 1, 3, 0, -1, 1, 3;
        0, 3, 3, 2, 1, 1, 0, 11, 1
        1, 3, 1, 6, 1, 1, 0, 6, 1
        1, 6, 1, 9, 1, 1, 0, 9, 1
        0, 9, 3, 2, 1, 0, 1, 11, 3
        1, 11, 3, 11, 5, 0, 1, 11, 5
        0, 9.5, 5, 1.5, 1, 0, -1, 8, 5
        1, 8, 4, 5, 4, -1, 0, 5, 4
        0, 5, 6, 2, 0, 0, 1, 5, 7.9
        1, 5, 8, 9, 8, 1, 0, 9, 8
        0, 9, 9.5, 1.5, 1, -1, 0, 9, 11
        1, 9, 11, 2, 11, -1, 0, 2, 11
        0, 2, 10, 1, 1, 0, -1, 1, 10];

Index = 1;