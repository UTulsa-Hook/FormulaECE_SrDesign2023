% This script will load a car accelerating from 0 over the course of 10
% seconds
Initialize();
scale = 1; %scale up car to see kinematics in motion
global dt;
X_bar = SensorModel(X, U);
%for t = 0:dt:30
while 1
    clf; %comment out for plotting 
    U_bar = Control(X_bar);
    U = MotorModels(U_bar);
    X = Dynamics(U, X);
    X_bar = SensorModel(X, U);
    %Plotting(X, X_bar, U, t);
    pause(dt);
end