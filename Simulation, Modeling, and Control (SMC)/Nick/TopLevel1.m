% This script will load a car accelerating from 0 over the course of 10
% seconds
Initialize();
%scale = 5; %scale up car to see kinematics in motion
X_bar = SensorModel(X, U);
while true
    clf;
    U = Control(X_bar);
    X = Dynamics(U, X);
    X_bar = SensorModel(X,U);
    %Plotting(X, X_bar, U, t);
    pause(dt);
end