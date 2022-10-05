Initialize();
scale = 2; %scale up car to see kinematics in motion

dt = 0.1;   
xbar = SensorModel(X);
for t = 0:dt:120
    clf;
    U = Control(xbar);
    X = Dynamics(U, X);
    xbar = SensorModel(X);
    %Plotting(X, xbar, U, t);
    pause(dt);
end