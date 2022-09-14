% This script will load a car accelerating from 0 over the course of 10
% seconds
Initialize();
dt = .1;

for t = 0:dt:12
    X_bar = SensorModel(X);
    U = Control(X_bar);
    X = Dynamics(U, X);
    Plotting(X, X_bar, U, t);
    pause(dt);
end