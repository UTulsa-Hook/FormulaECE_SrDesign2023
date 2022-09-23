% This script will load a car accelerating from 0 over the course of 10
% seconds
Initialize();
dt = .1;

X_bar = SensorModel(X, U);
for t = 0:dt:12
    clf;
    U = Control(X_bar);
    X = Dynamics(U, X);
    % everytime we set X we also have to set the sensor readings
    X_bar = SensorModel(X);
    % Plotting(X, X_bar, U, t);
    pause(dt);
end