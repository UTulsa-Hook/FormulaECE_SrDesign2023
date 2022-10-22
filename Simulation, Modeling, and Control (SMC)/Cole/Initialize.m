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
velocity = 5;
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
%NOTE: For the servo steering and motor characteristic curves, I think we
%should approximate with equations rather than discete points

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

Array = [1, 1, 9, 1, 2, 0, -1, 1, 2; %0, 5, 5, 3, 0, 1, 0, 100, 100];
        0, 2.1, 2.1, 1, 1, 1, 0, 2, 1
        1, 2, 1, 6, 1.5, 1, 0, 6, 1.5
        1, 6, 1.5, 9, 1, 1, 0, 9, 3
        0, 9, 3, 2, 1, 0, 1, 10.8, 2.5
        1, 11, 2.5, 11, 5, 0, 1, 11, 5
        0, 10, 4.9, 1, 1, 0, -1, 9, 5
        0, 7.9, 5.1, 1, 0, -1, 0, 8, 4
        1, 8, 3.75, 4, 4, -1, 0, 4.2, 4.5
        0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3
        1, 3, 5.5, 3, 8, 0, 1, 3, 7.6
        0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9
        1, 4, 8, 10, 8, 1, 0, 10.1, 9
        0, 10, 10.5, 1.5, 1, -3, 0, 10, 12
        1, 10, 12, 6, 10.5, 1, -2, 6, 10
        1, 6, 10, 2, 10, -1, 0, 2, 10
        0, 2, 9, 1, 1, 0, -1, 1, 9];
Index = 1;